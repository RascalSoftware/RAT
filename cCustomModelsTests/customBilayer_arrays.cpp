#include <vector>
#include "dylib.hpp"

class CustomBilayer {

public:
   DYLIB_API void customBilayer(double &params,double &bulk_in,double &bulk_out,int &contrast,double *output, double *rough);

    {
        double sub_rough = params[0];
        double oxide_thick = params[1];
        double oxide_hydration = params[2];
        double lipidAPM = params[3];
        double headHydration = params[4];
        double bilayerHydration = params[5];
        double bilayerRough = params[6];
        double waterThick = params[7];

        // We have a constant SLD for the bilayer
        double oxide_SLD = 3.41e-6;

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
        double oxSLD = (oxide_hydration * bulk_out[contrast]) + ((1 - oxide_hydration) * oxide_SLD);
        double headSLD = (headHydration * bulk_out[contrast]) + ((1 - headHydration) * SLDhead);
        double tailSLD = (bilayerHydration * bulk_out[contrast]) + ((1 - bilayerHydration) * SLDtail);

        // Make the layers
        double oxide[3] = {oxide_thick, oxSLD, sub_rough};
        double water[3] = {waterThick, bulk_out[contrast], bilayerRough};
        double head[3] = {headThick, headSLD, bilayerRough};
        double tails[3] = {tailThick, tailSLD, bilayerRough};

        // Make the output 2D array..
        // need {oxide, water, head, tail, tail, head};
        output[6][3] = {
                        {oxide},
                        {water},
                        {head},
                        {tail},
                        {tail},
                        {head}
                       };
        rough = sub_rough;

    }
};
