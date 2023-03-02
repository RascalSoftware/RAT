function [DREAMPar] = setDREAMParam(DREAMPar)
% Sets up sequential / parallel

% global DREAM_dir EXAMPLE_dir;

% Now create the function handle

% Currently using a function handle for RAT - AVH
% if isa(Func_name,'function_handle')
%     f_handle = Func_name;
% else
%     f_handle = eval(['@(x)',char(Func_name),'(x)']);
% end

% Now check if we want parallel execution of chains or not?
if strcmp(DREAMPar.parallel,'no')

    % We use 1 CPU (processor)
    DREAMPar.CPU = 1;
else
    DREAMPar.CPU = 0;% Treat this now as a flag - 0 is parfor.        currenPool.NumWorkers;


    % If input/output writing is done we need directories for each worker
    %     if strcmp(DREAMPar.IO,'yes'),
    %
    %         % Go to directory with problem files
    %         cd(EXAMPLE_dir)
    %
    %         % Create first part of copy expression
    %         a = strcat('copy "');
    %
    %         % Create the directories
    %         for ii = 1:min(DREAMPar.CPU,DREAMPar.N),
    %
    %             % Create the directories
    %             mkdir(strcat(num2str(ii)));
    %
    %             % And copy the files
    %             b = strcat(a,EXAMPLE_dir,'\*.*"',{' '},'"',EXAMPLE_dir,'\',strcat(num2str(ii)),'"'); dos(char(b));
    %
    %         end;
    %
    %         cd(DREAM_dir);
    %
    %     end;

end

% Now print to screen all the settings 
disp('------------------ Summary of the main settings used ------------------');
DREAMPar
disp('-----------------------------------------------------------------------');
