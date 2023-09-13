/*
Adapted from https://github.com/ojwoodford/mex_class_wrapper

* The class handle is used to hold a pointer with a method to validate the ptr is valid 
* The callback interface is provides the interface for domain and non-domain custom function
*/
#ifndef __CLASS_HANDLE_HPP__
#define __CLASS_HANDLE_HPP__

#include <stdint.h>
#include <string>
#include <cstring>
#include <typeinfo>
#include <stdexcept>

#define CLASS_HANDLE_SIGNATURE 0xFF00F0A5
template<class base> class ClassHandle
{
public:
    ClassHandle(base *ptr) : signature_m(CLASS_HANDLE_SIGNATURE), name_m(typeid(base).name()), ptr_m(ptr) {}
    ~ClassHandle() { signature_m = 0; delete ptr_m; }
    bool isValid() { return ((signature_m == CLASS_HANDLE_SIGNATURE) && !strcmp(name_m.c_str(), typeid(base).name())); }
    base* ptr() { return ptr_m; }

private:
    uint32_t signature_m;
    const std::string name_m;
    base* const ptr_m;
};


class CallbackInterface
{
public:
    virtual void invoke(double* params,double *bulk_in,double *bulk_out, int contrast,  
                                                        double *tempOutput,double *roughness,double *nLayers)=0;
    virtual void invoke(double* params,double *bulk_in,double *bulk_out, int contrast, int domainNumber, 
                                                        double *tempOutput,double *roughness,double *nLayers)=0;
};


template<class base> inline std::string convertPtr2String(base *ptr)
{  
    auto handle = reinterpret_cast<uint64_t>(new ClassHandle<base>(ptr));
    return std::to_string(handle);
}

template<class base> inline ClassHandle<base> *convertString2HandlePtr(const char* in)
{
    uint64_t value = stoull(std::string(in));
    ClassHandle<base> *ptr = reinterpret_cast<ClassHandle<base> *>(value);
    if (!ptr->isValid())
       throw std::invalid_argument("callback handle is not valid");
    return ptr;
}

#endif // __CLASS_HANDLE_HPP__
