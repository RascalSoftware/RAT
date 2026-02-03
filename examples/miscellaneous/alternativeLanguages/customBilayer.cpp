//customBilayer.cpp

#include <vector>

#if defined(_WIN32) || defined(_WIN64)
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT
#endif

// We user extern "C" decorator to avoid name mangling....
extern "C" {

    LIB_EXPORT void customBilayer(std::vector<double>& params, std::vector<double>& bulkIn, std::vector<double>& bulkOut, int contrast, std::vector<double>& output, double* outputSize, double* rough)
    {
        # Note - The first contrast number is 1 (not 0) so be careful if you use 
        # this variable for array indexing. 
        double subRough = params[0];
        double oxideThick = params[1];
        double oxideHydration = params[2];
        double lipidAPM = params[3];
        double headHydration = params[4];
        double bilayerHydration = params[5];
        double bilayerRough = params[6];
        double waterThick = params[7];

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
        double oxSLD = (oxideHydration * bulkOut[contrast-1]) + ((1 - oxideHydration) * oxideSLD);
        double headSLD = (headHydration * bulkOut[contrast-1]) + ((1 - headHydration) * SLDhead);
        double tailSLD = (bilayerHydration * bulkOut[contrast-1]) + ((1 - bilayerHydration) * SLDtail);

        // Make the layers
        // oxide...
        output.push_back(oxideThick);
        output.push_back(oxSLD);
        output.push_back(subRough);

        // Water...
        output.push_back(waterThick);
        output.push_back(bulkOut[contrast-1]);
        output.push_back(bilayerRough);

        // Heads...
        output.push_back(headThick);
        output.push_back(headSLD);
        output.push_back(bilayerRough);

        // Tails...
        output.push_back(tailThick);
        output.push_back(tailSLD);
        output.push_back(bilayerRough);

        // Tails...
        output.push_back(tailThick);
        output.push_back(tailSLD);
        output.push_back(bilayerRough);

        // Heads...
        output.push_back(headThick);
        output.push_back(headSLD);
        output.push_back(bilayerRough);

        *rough = subRough;
        
        outputSize[0] = 6;     // row - Necessary to ouptut how many layers in stack
        outputSize[1] = 3;     // col - Should be different depending on calculation 
    }
} // extern "C"