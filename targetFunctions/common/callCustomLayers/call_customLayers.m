function [output,sRough] = call_customLayers(params,contrast,thisCustomFile,bulkIn,bulkOut,nContrasts)

% Call a custom layers function
% This function calls a custom model, which can be in Matlab, Python or
% Octave. The custom function is called 'custom layers', but the same
% routines are required for layers or XY, so the same function is used.
% For Matlab, the gererated C++ passes excecution back to the base Matlab
% workspace. For Octave, an embedded Octave interpreter is used. An
% embedded interpreter is also used for Python.


% TODO: Add the Octave and Python functionality.


% Split up the custom file array into name, language and path...
fName = thisCustomFile{1};
lang = thisCustomFile{2};
path = thisCustomFile{3};

% Call the relevant routines depending on the language required
%
% (1) Note that in order to generate code for use outside Matlab, it is
% necessary to comment out the 'callMatlabCustomLayers' option as this 
% will throw an error. To create the source code uncomment the dummy output
% for 'output' and 'sRough'. To create the mexy file, comment out the
% dummy returns and uncomment 'callMatlabCustomLayers which executes the
% Matlab custom codes in the base matlab workspace using 'feval.
% This option (i.e. using 'feval') will eventually
% be replaced by a dedicated C++ class which will instantiate and call
% an external Matlab session (or the base workspace) using the 'Matlab Engine 
% for C++' API...  
% https://uk.mathworks.com/help/matlab/calling-matlab-engine-from-cpp-programs.html
%
% (2) It is not possible to build the full Library from Coder when using the Octave 
% interpreter, as there are name clashes between mex.h (Matlab) and 'oct.h'
% (Octave). To use Octave, comment out the Octave option, generate the code
% only using Matlab Coder, then manually include the Octave calling
% function, and the use external tools to build the dynamic library.
%
% (3) Embedding the Python interpreter has not yet been done


% switch lang
%     case 'matlab'
        % Send the calculation to the base Matlab workspace. This call must
        % be commented out for source code generation or it throws and
        % error, but required for mex generation.      
        % Use the dummy values of 'outPut' and 'sRough' instead to keep the
        % translator happy for source code generation.

        % Use this line for mex generation:
        [output,sRough] = callMatlabCustomLayers(params,contrast,fName,path,bulkIn,bulkOut,nContrasts);
        
        % Deal with possible 5 column outLayers (i.e. need to calculate the
        % hydrated SLD manually)
%         outSize = size(output);
%         if outSize(2) == 5                           % we need to calculate the hydrated SLD
%             newOutLayers = zeros(outSize(1),3);
%             newOutLayers(:,1) = output(:,1);         % Thickness'
%             newOutLayers(:,3) = output(:,3);
%             
%             for i = 1:outSize(1)
%                 thisSLD = output(i,2);
%                 thisHydration = output(i,4) / 100;   % Assume percent for backwards compatability
%                 thisHydrWhat = output(i,5);
%                 if thisHydrWhat == 1                 % Bulk out
%                     thisBulkHydr = bulkIn;
%                 else
%                     thisBulkHydr = bulkOut;
%                 end
%                 newSld = (thisHydration * thisBulkHydr) + ((1-thisHydration) * thisSLD);
%                 newOutLayers(i,2) = newSld;
%             end
%             output = newOutLayers;
%         end

        %
        % Use these dummy outputs for souce code generation:
%         output = [10 1e-6 3 ; 50 2e-6 4; 100 1e-6 4];
%         sRough = 3;
        
    %case 'octave'
        % Use the embedded Octave interpreter. 
        % [output,layers] = octaveCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
        %
        %
    %case 'python'
        % This has not been implemented yet
        %[output,layers] = pythonCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
%end

end



