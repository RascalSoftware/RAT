function out = checkBounds(problem)

out{1} = 'ok';

fitWhichParams = problem.fit;
fittingParams = problem.params(find(fitWhichParams));
fittingConstr = problem.constr(find(fitWhichParams),:);
fittingNames = problem.paramnames(find(fitWhichParams));

fitWhichBackgroundParam = problem.fitBackgroundParam;
fittingBackgroundParam = problem.backs(find(fitWhichBackgroundParam));
fittingBackgroundParamConstr = problem.backgroundParamLimits(find(fitWhichBackgroundParam),:);
fittingBackgroundParamNames = problem.backgroundParamNames(find(fitWhichBackgroundParam));

fitWhichScales = problem.fitScalefactor;
fittingScales = problem.scalefac(find(fitWhichScales));
fittingScalesConstr = problem.scalefactorLimits(find(fitWhichScales),:);
fittingScalesNames = problem.scalefactorNames(find(fitWhichScales));

fitWhichBulkIns = problem.fitBulkIn;
fittingBulkIns = problem.bulkIn(find(fitWhichBulkIns));
fittingBulkInConstr = problem.bulkInLimits(find(fitWhichBulkIns),:);
fittingBulkInNames = problem.bulkInNames(find(fitWhichBulkIns));


fittingParams = [fittingParams(:) ; fittingBackgroundParam(:) ; fittingScales(:) ; fittingBulkIns(:)];
fittingConstr = [fittingConstr ; fittingBackgroundParamConstr ; fittingScalesConstr ; fittingBulkInConstr];
fittingNames = [fittingNames(:) ; fittingBackgroundParamNames(:) ; fittingScalesNames(:) ; fittingBulkInNames(:)];

if isempty(fittingParams)
    out{1} = 'fail';
    beep
    disp('No parameters selected!');
end


loBounds = fittingConstr(:,1);
hiBounds = fittingConstr(:,2);

%Distinct Bounds Check..
areEqual = find(hiBounds==loBounds);
if ~isempty(areEqual)
    out{1} = 'fail';
    beep
    disp('Bounds must be distinct for ');
    for i = 1:length(areEqual)
        disp(fittingNames{areEqual(i)});
    end
end

%Out of range check....
outOfRange = find(fittingParams(:) < loBounds(:) | fittingParams(:) > hiBounds(:));
if ~isempty(outOfRange)
    out{1} = 'fail';
    beep
    disp('Parameter must be between bounds for ');
    for i = 1:length(outOfRange)
        disp(fittingNames{outOfRange(i)});
    end
end
    

