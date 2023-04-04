#ifndef WRAPPER_H
#define WRAPPER_H


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <tuple>
#include "dylib.hpp" // dylib.hpp is a header file that contains the dylib class that extracts a function from dll

class Library
{
    public:
        std::string functionName;
        std::string libName;
    
        Library(void){};
        ~Library(void){};

        void loadInfo(std::string libName, std::string functionName)
        {
            this->libName = libName;
            this->functionName = functionName;
        };

        // coder.ref(params),coder.ref(nba),coder.ref(nbs),numberOfContrasts,coder.ref(output),coder.ref(subrough));
        void loadRunner(double* params,double *bulk_in,double *bulk_out,int contrast,double *tempOutput,double *roughness,double *nLayers,char* libName,char* functionName)

        {       
            // create an instance of dylib
            dylib library;
            
            // load the library with libName 
            library = dylib (libName,dylib::extension);
            
            // store the function pointer in func
            auto func = library.get_function<void(double*, double*, double*, int, double*, double*, double*)>(functionName);
            
            // pass the arguments to the function
            func(params, bulk_in, bulk_out, contrast, tempOutput, roughness, nLayers);   

        };
};

#endif

