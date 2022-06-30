function SLD = customModelWrapper(params,bulk_in,bulk_out,contrast,domain)

switch domain
    case 1
        
        % Use the value for SLD up
        params = params(1:end-1);
        
    otherwise
        
        % Use the down value for alloy..
        params(6) = params(end);
        params = params(1:end-1);
end

% Call the main function...

    
SLD = alloy_gold_twoGaussSam_non_polarised(params,bulk_in,bulk_out,contrast);

end