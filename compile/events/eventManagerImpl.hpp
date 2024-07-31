#ifndef EVENT_MANAGER_IMPL_HPP
#define EVENT_MANAGER_IMPL_HPP

#include <mutex>
#include <vector>
#include <functional>

/* 
  Implementation of a singleton event manager with support for multiple 
  event types.
*/
enum class EventTypes {
  Message,
  Plot,
  Progress
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
    double* subRoughs;
    double* resample;
    double* dataPresent;
    const char* modelType;
    const char* contrastNames;
    const double* nContrastNames;
};


struct baseEvent {
    EventTypes type;
    baseEvent(EventTypes type) : type(type) {}
    virtual ~baseEvent() {}
};

struct messageEvent : baseEvent {
    const char* msg;
    messageEvent(const char* msg) : baseEvent(EventTypes::Message), msg(msg) {}
};

struct progressEvent : baseEvent {
    const char* msg;
    double percent;
    progressEvent(const char* msg, double percent) : baseEvent(EventTypes::Progress), msg(msg), percent(percent) {}
};

struct plotEvent : baseEvent {
    const plotData* data;
    plotEvent(const plotData* data) : baseEvent(EventTypes::Plot),  data(data) {}
};
		     
		     	      
class eventManager
{
public:
    
    eventManager(eventManager const&) = delete;
    eventManager& operator=(eventManager const&) = delete;
    ~eventManager() {}
    
    const std::vector<EventTypes>& getEventNames()const {return eventNames;}

    void addListener(EventTypes type, const std::function<void(const baseEvent&)> fn) {
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
    std::vector<EventTypes> eventNames;
    std::vector<std::function<void(const baseEvent&)>> eventHandlers;
    std::mutex m_mutex;
};

#endif // EVENT_MANAGER_IMPL_HPP