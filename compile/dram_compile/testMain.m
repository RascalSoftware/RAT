t = load('testParams');
t = t.testParams;

controls = load('controls');
controls = controls.controls;
controls.para = 'single';
controls.repeats = 1;

problemDef = t.problemDef;
problemDef_cells = t.problemDef_cells;
problemDef_limits = t.problemDef_limits;
priors = t.priors;


[outProblemDef,problem,results,bayesResults] = runDram(problemDef,problemDef_cells,problemDef_limits,priors,controls);



%           contrastBacks: [1 2 3]
%       contrastBacksType: [1 1 1]
%                      TF: 'standardTF'
%                resample: [0 0 0]
%             dataPresent: [1 1 1]
%       numberOfContrasts: 3
%                geometry: 'substrate/liquid'
%          contrastShifts: [1 1 1]
%          contrastScales: [1 1 1]
%            contrastNbas: [1 1 1]
%            contrastNbss: [1 2 3]
%             contrastRes: [1 1 1]
%                   backs: [0 0 0]
%                  shifts: 0
%                      sf: 1
%                     nba: 2.0730e-06
%                     nbs: [6.3500e-06 2.0730e-06 -5.6000e-07]
%                     res: 0.0300
%                  params: [3 20 0.2000 55 0.2000 0.1000 4 2]
%          numberOfLayers: 0
%               modelType: 'custom layers'
%     contrastCustomFiles: [1 1 1]
%                 fitpars: []
%               otherpars: []
%               fitconstr: []
%             otherconstr: []

% % Pre-processor directives for Matlab Coder.
% coder.varsize('problem.ssubs',[Inf 1],[1 0]);
% coder.varsize('problem.backgrounds',[Inf 1],[1 0]);
% coder.varsize('problem.qshifts',[Inf 1],[1 0]);
% coder.varsize('problem.scalefactors',[Inf 1],[1 0]);
% coder.varsize('problem.nbairs',[Inf 1],[1 0]);
% coder.varsize('problem.nbsubs',[Inf 1],[1 0]);
% coder.varsize('problem.resolutions',[Inf 1],[1 0]);
% coder.varsize('problem.ssubs',[Inf 1],[1 0]);
% coder.varsize('problem.calculations.all_chis',[Inf 1],[1 0]);
% coder.varsize('problem.calculations.sum_chi',[1 1],[0 0]);
% coder.varsize('problem.allSubRough',[Inf 1],[1 0]);
% 
% %Result coder definitions....
% coder.varsize('result{1}',[Inf 1],[1 0]);           %Reflectivity
% coder.varsize('result{1}{:}',[Inf 2],[1 0]);
% 
% coder.varsize('result{2}',[Inf 1],[1 0]);           %Simulatin
% coder.varsize('result{2}{:}',[Inf 2],[1 0]);
% 
% coder.varsize('result{3}',[Inf 1],[1 0]);           %Shifted data
% coder.varsize('result{3}{:}',[Inf 3],[1 0]);
% 
% coder.varsize('result{4}',[Inf 1],[1 0]);           %Layers slds
% coder.varsize('result{4}{:}',[Inf 3],[1 0]);
% 
% coder.varsize('result{5}',[Inf 1],[1 0]);           %Sld profiles
% coder.varsize('result{5}{:}',[Inf 2],[1 0]);
% 
% coder.varsize('result{6}',[Inf 1],[1 0]);           %All layers
% coder.varsize('result{6}{:}',[Inf 1],[1 0]);


% Put the extracted fields into a cell array...
% Structure of problemDef_cells array.
%
% {1} - inputProblemDef.contrastRepeatSLDs
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}.
%
% {2} - inputProblemDef.allData
%       {1 x nContrasts} array of cells
%       Each cell is {Inf x 3 double}
%
% {3} - inputProblemDef.dataLimits
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}
%
% {4} - inputProblemDef.simLimits
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}
%
% {5} - inputProblemDef.contrastLayers
%       {1 x nContrasts} array of cells
%       Each cell is {1 x Inf double}
%
% {6} - inputProblemDef.layersDetails
%       {n x 1} array of cells
%       Each cell is (1 x 5 double}
%
% {7} - inputProblemDef.paramNames
%       {1 x nParams} array of cells
%       Each cell is {1 x Inf char}
%
% {8} - inputProblemDef.backgroundsNames
%       {1 x nBackgrounds} array of cells
%       Each cell is {1 x Inf char}
% 
% {9} - inputProblemDef.scalefactorNames
%       {1 x nScales} array of cells
%       Each cell is {1 x Inf char}
% 
% {10}- inputProblemDef.qzshiftNames
%       {1 x nShifts} array of cells
%       Each cell is {1 x Inf char}
% 
% {11}- inputProblemDef.nbairNames
%       {1 x nNba} array of cells
%       Each cell is {1 x Inf char}
% 
% {12}- inputProblemDef.nbsrNames
%       {1 x nNba} array of cells
%       Each cell is {1 x Inf char}
% 
% {13}- inputProblemDef.resolNames
%       {1 x nNba} array of cells
%       Each cell is {1 x Inf char}
%
% {14} - inputProblemDef.customFiles
%          array of cells
%       Each cell is {fName, lang, path}




