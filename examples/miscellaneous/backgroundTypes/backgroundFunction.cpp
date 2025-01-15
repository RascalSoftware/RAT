//backgroundFunction.cpp

#include <vector>
#include <cmath>

#if defined(_WIN32) || defined(_WIN64)
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT
#endif

// We user extern "C" decorator to avoid name mangling....
extern "C" {

    LIB_EXPORT void backgroundFunction(std::vector<double>& xdata, std::vector<double>& params, std::vector<double>& output)
    {
        double Ao = params[0];
        double k = params[1];
        double backConst = params[2];

        for (int i = 0; i < xdata.size(); i++)
        {
           output.push_back(Ao*std::exp(-k*xdata[i]) + backConst); 
        }
    }
} // extern "C"