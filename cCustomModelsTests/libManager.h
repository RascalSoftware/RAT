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
        void loadRunner(double* params,double *bulk_in, double *bulk_out, int contrast, double *tempOutput,double *roughness, char* libName, char* functionName)

            // std::cout << "loading library" << std::endl;
        {       

            //std::string libName = "mainFromGCC";
            // creating an instance of dylib
            dylib library;
            // load the library with libName 
            library = dylib (libName,dylib::extension);
            // store the function pointer in a variable called func
            auto func = library.get_function<void(double*, double*, double*, int, double*, double*)>(functionName);
            // pass the arguments to the function
            func(params, bulk_in, bulk_out, contrast, tempOutput, roughness);         
        };
};

#endif





    // int main()
    // {
    //     double params[] = {1,2,3,4,5,6,7,8};
    //     double *paramsPtr = params;
    //     double bulk_in = 1;
    //     double *bulkinPtr = &bulk_in;
    //     double bulk_out = 1;
    //     double *bulkoutPtr = &bulk_out;
    //     int contrast = 1;
    //     real64_T output[8] = {6,8,7,1,8,4,3,2};
    //     // create a pointer to output vector to pass to the function
    //     double roughness = 1;
    //     double *roughnessPtr = &roughness;
        
    //     std::cout << "Before Params" << std::endl;
    //     printArray(params);
    //     // print the value pointed to by bulk_in
    //     std::cout << "Before bulk_in: " << bulk_in << std::endl;
    //     // print bulk_out
    //     std::cout << "Before bulk_out: "<< bulk_out << std::endl;
    //     // print contrast
    //     std::cout << "Before contrast: "<< contrast << std::endl;
    //     // print roughness
    //     std::cout << "Before roughness: "<< roughness << std::endl;


    //     loadRunner(paramsPtr,bulkinPtr,bulkoutPtr,contrast,output,roughnessPtr);

        

    //     // print output
    //     std::cout << "output After: ";
    //     printArray(output);

        

    // // a function that extracts the function from the dll and returns a function pointer to it
    // void getFunctionPtr(std::string libName, std::string functionName, void *funcPtr)
    // {
    //     // creating an instance of dylib
    //     dylib library;
    //     // load the library with libName 
    //     library = dylib (libName,dylib::extension);
    //     // store the function pointer in a variable called func
    //     auto func = library.get_function<void(double*, double*, double*, int, std::vector<double>&, double*)>(functionName);
        
    //     // point ot funPtr to the function pointer
    //     funcPtr = &func;
    // };




    // }
