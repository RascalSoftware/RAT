function [fx] = evaluateModel(x,DREAMPar,Meas_info,ratInputs)
% This function computes the likelihood and log-likelihood of each d-vector
% of x values
%
% Code both for sequential and parallel evaluation of model ( = pdf )
%
% Written by Jasper A. Vrugt

% Check whether to store the output of each model evaluation (function call)
% if DREAMPar.modout && ( Meas_info.N > 0 )
%     
%     % Create initial fx of size model output by DREAMPar.N
%     fx = NaN(Meas_info.N,DREAMPar.N);
%     
% end

% Now evaluate the model
fx = zeros(1,DREAMPar.N);
if ( DREAMPar.CPU == 1 )         % Sequential evaluation

    % Loop over each d-vector of parameter values of x using 1 worker
    for ii = 1:DREAMPar.N
        % Execute the model and return the model simulation
        %fx(:,ii) = f_handle(x(ii,:), ratInputs);
        fx(:,ii) = DREAMWrapper(x(ii,:),ratInputs);
    end

else     % Parallel evaluation

    % If IO writing with model --> worker needs to go to own directory
    %     if DREAMPar.IO
    %         % Minimise network traffic by checking in example dir is needed.
    %         % Tim Peterson 2016
    %         if ~isempty(EXAMPLE_dir)
    %
    %             % Loop over each d-vector of parameter values of x using N workers
    %             parfor ii = 1:DREAMPar.N
    %                 % Determine work ID
    %                 t = getCurrentTask();
    %
    %                 % Go to right directory (t.id is directory number)
    %                 evalstr = strcat(EXAMPLE_dir,'\',num2str(t.id)); cd(evalstr)
    %
    %                 % Execute the model and return the model simulation
    %                 %fx(:,ii) = f_handle( [ x(ii,:) t.id ], ratInputs );
    %                 fx(:,ii) = DREAMWrapper( [ x(ii,:) t.id ],ratInputs );
    %             end
    %
    %         else
    %             % Loop over each d-vector of parameter values of x using N workers
    %             parfor ii = 1:DREAMPar.N
    %                 % Execute the model and return the model simulation
    %                 %fx(:,ii) = f_handle( [ x(ii,:) t.id ], ratInputs );
    %                 fx(:,ii) = DREAMWrapper( [ x(ii,:) t.id ],ratInputs );
    %             end
    %
    %         end
    %     else

    % Loop over each d-vector of parameter values of x using N workers
    parfor ii = 1:DREAMPar.N
        % Execute the model and return the model simulation
        %fx(:,ii) = f_handle(x(ii,:), ratInputs);
        fx(:,ii) = DREAMWrapper(x(ii,:),ratInputs);
    end

end

end
