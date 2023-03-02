function stop = DREAMCheck(DREAMPar,Par_info,Meas_info)
% Check for setup errors

% Assign stop to be No
stop = 'no';

% First close all files
fclose('all');


% ----------------------REMOVE warning file - AVH
% open an output file with warnings
%fid = fopen('warning_file.txt','w');
%fprintf(fid,'-------------- DREAM warning file --------------\n');
% ------------------------------------------------

% Check number of chains
if DREAMPar.N < (2 * DREAMPar.delta) + 1
    % Error -- not enough chains to do sampling -- increase number of chains!
    stop = 'yes';
    error('DREAM ERROR: Inufficient number of chains -> Use at least DREAMPar.N = %1g chains \n',((2 * DREAMPar.delta) + 1));
end

% Check parameter ranges
if strcmp(Par_info,'latin')
    % Error -- if lhs is used -> requires explicit parameter ranges
    if ( sum(isinf(Par_info.min)) == DREAMPar.d )
        stop = 'yes';
        error('DREAM ERROR: Latin hypercube sampling selected but parameter ranges not defined -> Set Par_info.min and Par_info.max!!\n');
    end
end

% % Check prior distribution
% if ( strcmp(lower(DREAMPar.prior),'yes') ) || ( strcmp(lower(Par_info),'prior') ),
%     % Error -- if explicit prior is used --> marginals need to be defined
%     if ~isfield(Par_info,'prior_marginal');
%         evalstr = char('DREAM ERROR: Prior chosen but no marginal distribution specified to sample from -> Define Par_info.prior_marginal!!\n');
%         % Now print warning to screen and to file
%         fprintf(evalstr); fprintf(fid,evalstr);
%         % Stop DREAM
%         stop = 'yes';
%     end;
% end;

% Check whether we specified measurement sigma correctly
% if ( DREAMPar.lik == 12 || DREAMPar.lik == 13 ) && ( isfield(Meas_info,'Sigma') == 0 )
%     % Error -- Meas_info.Sigma needs to be specified!!
%     error('DREAM ERROR: Meas_info.Sigma needs to be specified either as inline function or one or multiple numerical values!!\n');
% end

% Check whether the length of the user specified sigma is correct
if ( isfield(Meas_info,'Sigma') == 1 ) && ( isfield(Meas_info,'n') == 0 )
    if (prod(size(Meas_info.Sigma)) ~= prod(size(Meas_info.MeasData))) && ( prod(size(Meas_info.Sigma)) > 1 )
        % Error -- Meas_info.Sigma incorrect length!!
        error('DREAM ERROR: Heteroscedastic error, but length of Meas_info.Sigma is not equal to that of the observations!!\n');
    elseif ( sum(Meas_info.Sigma<=0) > 0 )
        % Error -- Meas_info.Sigma is negative!!
        error('DREAM ERROR: At least one value of the specified Meas_info.Sigma is negative or zero!!\n');
    end
end