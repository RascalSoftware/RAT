#include <iostream>
#include <iterator>
#include <array>

#if defined(_WIN32) || defined(_WIN64)
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT
#endif

// We user extern "C" decorator to avoid name mangling (apparently!)....
extern "C" {
    //LIB_EXPORT double outRough = 15.1;

    //LIB_EXPORT double outArray[18];

    LIB_EXPORT void customBilayer(double* params, double* bulkIn, double* bulkOut, int contrast, double* output, double* rough)

    {
        double subRough = params[0];
        double oxideThick = params[1];
        double oxideHydration = params[2];
        double lipidAPM = params[3];
        double headHydration = params[4];
        double bilayerHydration = params[5];
        double bilayerRough = params[6];
        double waterThick = params[7];

        // We have a constant SLD for the bilayer
        double oxideSLD = 3.41e-6;

        // Now make the lipid layers..
        // Use known lipid volume and compositions
        // to make the layers

        // define all the neutron b's.
        double bc = 0.6646e-4;     //Carbon
        double bo = 0.5843e-4;     //Oxygen
        double bh = -0.3739e-4;	   //Hydrogen
        double bp = 0.513e-4;      //Phosphorus
        double bn = 0.936e-4;      //Nitrogen
        double bd = 0.6671e-4;     //Deuterium

        // Now make the lipid groups..
        double COO = (4*bo) + (2*bc);
        double GLYC = (3*bc) + (5*bh);
        double CH3 = (2*bc) + (6*bh);
        double PO4 = (1*bp) + (4*bo);
        double CH2 = (1*bc) + (2*bh);
        double CHOL = (5*bc) + (12*bh) + (1*bn);

        // Group these into heads and tails:
        double Head = CHOL + PO4 + GLYC + COO;
        double Tails = (34*CH2) + (2*CH3);

        // We need volumes for each.
        // Use literature values:
        double vHead = 319;
        double vTail = 782;

        // we use the volumes to calculate the SLD's
        double SLDhead = Head / vHead;
        double SLDtail = Tails;

        // We calculate the layer thickness' from
        // the volumes and the APM...
        double headThick = vHead / lipidAPM;
        double tailThick = vTail / lipidAPM;

        // Manually deal with hydration for layers in
        // this example.
        double oxSLD = (oxideHydration * bulkOut[contrast]) + ((1 - oxideHydration) * oxideSLD);
        double headSLD = (headHydration * bulkOut[contrast]) + ((1 - headHydration) * SLDhead);
        double tailSLD = (bilayerHydration * bulkOut[contrast]) + ((1 - bilayerHydration) * SLDtail);

        // Make the layers
        //output = new double[18];

        const auto nLayers = 6;
        const auto array = new double[nLayers][3];

        // oxide...
        array[0][0] = oxideThick;
        array[0][1] = oxSLD;
        array[0][2] = subRough;

        // Water...
        array[1][0] = waterThick;
        array[1][1] = bulkOut[contrast];
        array[1][2] = bilayerRough;

        // Heads...
        array[2][0] = headThick;
        array[2][1] = headSLD;
        array[2][2] = bilayerRough;

        // Tails...
        array[3][0] = tailThick;
        array[3][1] = tailSLD;
        array[3][2] = bilayerRough;

        // Tails...
        array[4][0] = tailThick;
        array[4][1] = tailSLD;
        array[4][2] = bilayerRough;

        // Heads...
        array[5][0] = headThick;
        array[5][1] = headSLD;
        array[5][2] = bilayerRough;

        output = *array;
        *rough = subRough;
        std::cout << "roughness in func : " << subRough << "\n";

        

        //output = array;

        //outRough = subRough;
        //std::cout << "Value of outRough in customBilayer : " << outRough << "\n";

        //outArray = output;
    }

} // extern "C"