function fx = ratEvaluate_model(x,DREAMPar,Meas_info,ratInputs)

% RAT function evaluation

% Check whether to store the output of each model evaluation (function call)
if strcmpi(DREAMPar.modout,'yes') && (Meas_info.N > 0)
    % Create initial fx of size model output by DREAMPar.N
    fx = NaN(Meas_info.N,DREAMPar.N);
end

% Now evaluate the model
if ( DREAMPar.CPU == 1 )         % Sequential evaluation

    % Loop over each d-vector of parameter values of x using 1 worker
    for ii = 1:DREAMPar.N
        % Execute the model and return the model simulation
        fx(:,ii) = ratDreamWrapper(x(ii,:), ratInputs);
    end
else

    % Loop over each d-vector of parameter values of x using N workers
    parfor ii = 1:DREAMPar.N
        % Execute the model and return the model simulation
        fx(:,ii) = ratDreamWrapper(x(ii,:), ratInputs);
    end
end


end
