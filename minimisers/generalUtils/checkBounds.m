function out = checkBounds(problem)

out{1} = 'ok';

fitWhichParams = problem.fit;
fittingParams = problem.params(find(fitWhichParams));
fittingConstr = problem.constr(find(fitWhichParams),:);
fittingNames = problem.paramnames(find(fitWhichParams));

fitWhichBacks = problem.fitBackgrounds;
fittingBacks = problem.backs(find(fitWhichBacks));
fittingBacksConstr = problem.backgroundParamLimits(find(fitWhichBacks),:);
fittingBacksNames = problem.backgroundParamNames(find(fitWhichBacks));

fitWhichScales = problem.fitScalefactor;
fittingScales = problem.scalefac(find(fitWhichScales));
fittingScalesConstr = problem.scalefactorLimits(find(fitWhichScales),:);
fittingScalesNames = problem.scalefactorNames(find(fitWhichScales));

fitWhichShifts = problem.fitQzshift;
fittingShifts = problem.qzshifts(find(fitWhichShifts));
fittingShiftsConstr = problem.qzshiftLimit(find(fitWhichShifts),:);
fittingShiftsNames = problem.qzshiftNames(find(fitWhichShifts));

fitWhichNbas = problem.fitBulkIn;
fittingNbas = problem.bulkIn(find(fitWhichNbas));
fittingNbaConstr = problem.bulkInLimits(find(fitWhichNbas),:);
fittingNbaNames = problem.bulkInNames(find(fitWhichNbas));


fittingParams = [fittingParams(:) ; fittingBacks(:) ; fittingScales(:) ; fittingShifts(:) ; fittingNbas(:)];
fittingConstr = [fittingConstr ; fittingBacksConstr ; fittingScalesConstr ; fittingShiftsConstr ; fittingNbaConstr];
fittingNames = [fittingNames(:) ; fittingBacksNames(:) ; fittingScalesNames(:) ; fittingShiftsNames(:) ; fittingNbaNames(:)];

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
    

