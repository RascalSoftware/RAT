%       DUMMY FUNCTIONS FOR SOURCE COMPILE 
%
% At present, when compiling to source, the Matlab custom layers / custom
% XY will not work, since they use an 'fval' extrinsic call to the base
% Matlab worspace. This causes code generation to fail

% So, in order for source generation to proceed, we replace these functions
% with dummy functions for now. Eventually, we will replace those functions
% with calls to a Matlab Engine, so that the generated source will also
% allow Matlab custom files to be used when compiled to a library.

% For now, the CPP custom files option still works, even when compiled to
% DLL etc