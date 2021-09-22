function problem = backsorts(problem)

%Distributes the background and shift values 
%Among the relevant datasets.
global R1_DEBUG R1_DEBUGVARS 

for i = 1:problem.numberOfContrasts
    thisBack = problem.contrastBacks(i);
    problem.backgrounds(i) = problem.backs(thisBack);

    thisShift = problem.contrastShifts(i);
    problem.qshifts(i) = problem.shifts_horisontal(thisShift);

    thisScale = problem.contrastScales(i);
    problem.scalefactors(i) = problem.scalefac(thisScale);

    thisNbair = problem.contrastNbas(i);
    problem.nbairs(i) = problem.nba(thisNbair);

    thisNbsub = problem.contrastNbss(i);
    problem.nbsubs(i) = problem.nbs(thisNbsub);
    
    thisResol = problem.contrastResolutions(i);
    problem.resolutions(i) = problem.resolution(thisResol);
end

if R1_DEBUG
    R1_DEBUGVARS.backsorts.backgrounds = problem.backgrounds;
    R1_DEBUGVARS.backsorts.qshifts = problem.qshifts;
    R1_DEBUGVARS.backsorts.scalefactors = problem.scalefactors;
    R1_DEBUGVARS.backsorts.nba = problem.nbairs;
    R1_DEBUGVARS.backsorts.nbs = problem.nbsubs;  
    R1_DEBUGVARS.backsorts.resolutions = problem.resolutions;
end


    

