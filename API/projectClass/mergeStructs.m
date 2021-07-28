function outStruct = mergeStructs(varargin)

outStruct = struct();

for i = 1:length(varargin)
    thisStruct = varargin{i};
    outStruct = cell2struct([struct2cell(outStruct) ; struct2cell(thisStruct)],...
        [fieldnames(outStruct); fieldnames(thisStruct)]);
end


end