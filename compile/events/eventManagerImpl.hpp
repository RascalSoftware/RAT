#ifndef EVENT_MANAGER_IMPL_HPP
#define EVENT_MANAGER_IMPL_HPP

#include <mutex>
#include <vector>

/* 
  Implementation of a singleton event manager with support for multiple 
  event types.
*/
enum eventTypes {
  MESSAGE,
  PLOT
}; 


struct plotData {
    int nContrast;
    double* reflect;
    double* nReflect;
    double* shiftedData;
    double* nShiftedData;
    double* sldProfiles;
    double* nSldProfiles;
    double* layers;
    double* nLayers;
    double* sldProfiles2;
    double* nSldProfiles2;
    double* layers2;
    double* nLayers2;
    double* ssubs;
    double* resample;
    double* dataPresent;
    const char* modelType;
};


struct baseEvent {
    enum eventTypes type;
    baseEvent(enum eventTypes type) : type(type) {}
    virtual ~baseEvent() {}
};

struct messageEvent : baseEvent {
    const char* msg;
    messageEvent(const char* msg) : baseEvent(MESSAGE), msg(msg) {}
};

struct plotEvent : baseEvent {
    const plotData* data;
    plotEvent(const plotData* data) : baseEvent(PLOT),  data(data) {}
};


typedef void (*callback) (const baseEvent&);
		     
		     	      
class eventManager
{
public:
    
    eventManager(eventManager const&) = delete;
    eventManager& operator=(eventManager const&) = delete;
    ~eventManager() {}
    
    void addListener(enum eventTypes type, const callback fn) {
       std::lock_guard<std::mutex> lock(m_mutex);
	   eventNames.push_back(type);
       eventHandlers.push_back(fn);
    }

    void notify(const baseEvent& event) {
        for(unsigned i=0; i < eventNames.size(); i++) {
            if (event.type == eventNames[i])
                eventHandlers[i] (event);
        }
    }
    
    void clear() {
	    eventNames.clear();
	    eventHandlers.clear();
    }

    static eventManager* get_instance()
    {
        // Static local variable initialization is thread-safe
        // and will be initialized only once.
        static eventManager instance{};
        return &instance;
    }

private:
    explicit eventManager() {}
    std::vector<enum eventTypes> eventNames;
    std::vector<void (*)(const baseEvent&)> eventHandlers;
    std::mutex m_mutex;
};

#endif // EVENT_MANAGER_IMPL_HPP