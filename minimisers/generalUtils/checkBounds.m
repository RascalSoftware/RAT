function out = checkBounds(problem)

out{1} = 'ok';

fitWhichParams = problem.fit;
fittingParams = problem.params(find(fitWhichParams));
fittingConstr = problem.constr(find(fitWhichParams),:);
fittingNames = problem.paramnames(find(fitWhichParams));

fitWhichBacks = problem.fitBackgrounds;
fittingBacks = problem.backs(find(fitWhichBacks));
fittingBacksConstr = problem.backs_constr(find(fitWhichBacks),:);
fittingBacksNames = problem.backsNames(find(fitWhichBacks));

fitWhichScales = problem.fitScales;
fittingScales = problem.scalefac(find(fitWhichScales));
fittingScalesConstr = problem.scale_constr(find(fitWhichScales),:);
fittingScalesNames = problem.scalesNames(find(fitWhichScales));

fitWhichShifts = problem.fitShifts;
fittingShifts = problem.shifts_horisontal(find(fitWhichShifts));
fittingShiftsConstr = problem.shifts_constr(find(fitWhichShifts),:);
fittingShiftsNames = problem.shiftsNames(find(fitWhichShifts));

fitWhichNbas = problem.fitNbairs;
fittingNbas = problem.nba(find(fitWhichNbas));
fittingNbaConstr = problem.nbairs_constr(find(fitWhichNbas),:);
fittingNbaNames = problem.nbaNames(find(fitWhichNbas));


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
    

