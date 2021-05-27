clear

R = load('R.mat');
R = R.R;

oldpar = [   3.0000e+00
   2.0000e+01
   2.0000e-01
   5.5000e+01
   2.0000e-01
   1.0000e-01
   4.0000e+00
   2.0000e+00
            0
            0
            0
   1.0000e+00
   6.3500e-06
   2.0730e-06
  -5.6000e-07];
oldpar = oldpar';

newpar = [   3.0484e+00
   2.1009e+01
   1.8871e-01
   5.5172e+01
   2.0159e-01
   9.7385e-02
   3.9740e+00
   2.0343e+00
   3.5784e-07
   2.7694e-07
  -1.3499e-07
   1.0455e+00
   6.3598e-06
   2.0717e-06
  -5.5786e-07];
newpar = newpar';

low = ones(1,15) * -10;
upp = ones(1,15) .* 100;

Ntry = 7;
DR_scale = [5 4 3];
npar = 15;
parind = [1:15];
thetamu = zeros(1,15);
thetasig = ones(1,15) .* Inf;

[out] = drPart(R,npar,oldpar,newpar,Ntry,DR_scale,parind,low,upp,thetamu,thetasig);



