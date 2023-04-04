//customBilayer_libExp.cpp

#include <iostream>
#include <iterator>

#if defined(_WIN32) || defined(_WIN64)
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT
#endif

// We user extern "C" decorator to avoid name mangling....
extern "C" {

    LIB_EXPORT void customBilayer(double* params, double* bulkIn, double* bulkOut, int contrast, double* output, double* rough, double* nLayers)

    {
        double subRough = params[0];
        double oxideThick = params[1];
        double oxideHydration = params[2];
        double lipidAPM = params[3];
        double headHydration = params[4];
        double bilayerHydration = params[5];
        double bilayerRough = params[6];
        double waterThick = params[7];

        double bulk_out = *bulkOut;
        std::cout << "Bulk out value: " << bulk_out;

        // We have a constant SLD for the oxide
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
        double SLDtail = Tails / vTail;

        // We calculate the layer thickness' from
        // the volumes and the APM...
        double headThick = vHead / lipidAPM;
        double tailThick = vTail / lipidAPM;

        // Manually deal with hydration for layers in
        // this example.
        double oxSLD = (oxideHydration * *bulkOut) + ((1 - oxideHydration) * oxideSLD);
        double headSLD = (headHydration * *bulkOut) + ((1 - headHydration) * SLDhead);
        double tailSLD = (bilayerHydration * *bulkOut) + ((1 - bilayerHydration) * SLDtail);

        // Make the layers
        //output = new double[18];

        
        // static auto array = new double[18];

        // oxide...
        output[0] = oxideThick;
        output[1] = oxSLD;
        output[2] = subRough;

        // Water...
        output[3] = waterThick;
        output[4] = *bulkOut;
        output[5] = bilayerRough;

        // Heads...
        output[6] = headThick;
        output[7] = headSLD;
        output[8] = bilayerRough;

        // Tails...
        output[9] = tailThick;
        output[10] = tailSLD;
        output[11] = bilayerRough;

        // Tails...
        output[12] = tailThick;
        output[13] = tailSLD;
        output[14] = bilayerRough;

        // Heads...
        output[15] = headThick;
        output[16] = headSLD;
        output[17] = bilayerRough;

        *rough = subRough;
        *nLayers = 6;       // Necessary to ouptut how many layers in stack


        //std::cout << "roughness in func : " << subRough << "\n";
        //std::cout << "Head SLD in func : " << headSLD << "\n";
        //std::cout << "Array[1] in func : " << output[1] << "\n";

        //output = array;

        //outRough = subRough;
        //std::cout << "Value of outRough in customBilayer : " << outRough << "\n";

        //outArray = output;
    }

} // extern "C"