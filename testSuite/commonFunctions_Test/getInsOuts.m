

% ChiSqaured inputs from orsoDSPC_stanLay_script.m

inputs = {thisData,thisFit,P}

% save the inputs

save('chiSqauredInputs.mat','inputs')



% ChiSqaured outputs from orsoDSPC_stanLay_script.m

outputs = chi2

% save the outputs
    
save('chiSqauredOutputs.mat','outputs')



%load the inputs
    
load('chiSqauredInputs.mat')

firstArg = inputs{1};
secondArg = inputs{2};
thirdArg = inputs{3};
