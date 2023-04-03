classdef testProjectClassToR1 < matlab.unittest.TestCase

    properties
        inputStandardProjectClass
        inputStandardStruct
        outputStandardStruct
        defaultProject
        outputCustomStruct
        inputCustomProjectClass
        modelFile
        fullPath
    end

    methods(TestClassSetup)
        function defineVariables(testCase)
            testCase.inputStandardProjectClass = "originalDSPCBilayerProjectClass.mat";
            testCase.inputStandardStruct = "originalDSPCBilayerStructInput.mat";
            testCase.outputStandardStruct = "originalDSPCBilayerStructOutput.mat";
            testCase.defaultProject = "defaultProject.mat";
            testCase.outputCustomStruct = "monolayerVolumeModel.mat";
            testCase.inputCustomProjectClass = "monolayerVolumeModelProjectClass.mat";
            testCase.modelFile = "Model_IIb.m";
        end
    end

    methods(TestMethodSetup)
        function setWorkingFolder(testCase)
            root = getappdata(0,'root');
            testCase.fullPath = [root filesep 'tests' filesep 'testProjectClassToR1Conversion'];
            import matlab.unittest.fixtures.CurrentFolderFixture
            testCase.applyFixture(CurrentFolderFixture(testCase.fullPath))
        end
    end 

     methods(TestMethodTeardown)
        function testCleanUp(testCase)
            cd (testCase.fullPath)
            if exist('newDirectory','dir')
                rmdir('newDirectory', 's')
            end
        end
    end 

    methods (Test)

        function testFilesExists(testCase)
            testCase.verifyEqual(exist(testCase.outputStandardStruct,'file'), 2);
            testCase.verifyEqual(exist(testCase.inputStandardProjectClass,'file'), 2);
            testCase.verifyEqual(exist(testCase.inputStandardStruct,'file'), 2);
            testCase.verifyEqual(exist(testCase.defaultProject,'file'), 2);
            testCase.verifyEqual(exist(testCase.outputCustomStruct,'file'), 2);
            testCase.verifyEqual(exist(testCase.inputCustomProjectClass,'file'), 2);
            testCase.verifyEqual(exist(testCase.modelFile,'file'), 2);
        end

        function testCompareProjectClassToR1(testCase)
            expected = load(testCase.outputStandardStruct).problem;

            pClass = load(testCase.inputStandardProjectClass).thisProjectClass; 
            result = projectClassToR1(pClass, "saveProject", false);

            testCase.verifyEqual(result.name, expected.name);
            testCase.verifyEqual(result.numberOfContrasts, expected.numberOfContrasts);
            testCase.verifyEqual(result.module.type, expected.module.type);
            testCase.verifyEqual(result.module.name, expected.module.name);
            testCase.verifyEqual(result.module.calculation_type, expected.module.calculation_type);
            testCase.verifyEqual(result.module.experiment_type, expected.module.experiment_type);
            testCase.verifyEqual(result.paramnames, expected.paramnames);
            testCase.verifyEqual(result.constr, expected.constr);
            testCase.verifyEqual(result.params, expected.params);
            testCase.verifyEqual(result.fityesno, expected.fityesno);
            testCase.verifyEqual(result.fiterrs, expected.fiterrs);
            testCase.verifyEqual(result.numberOfLayers, expected.numberOfLayers);
            testCase.verifyEqual(result.layersDetails, expected.layersDetails);
            testCase.verifyEqual(result.numberOfBacks, expected.numberOfBacks);
            testCase.verifyEqual(result.backgrounds_fityesno, expected.backgrounds_fityesno);
            testCase.verifyEqual(result.backsNames, expected.backsNames);
            testCase.verifyEqual(result.backs_constr, expected.backs_constr);
            testCase.verifyEqual(result.backs, expected.backs);
            testCase.verifyEqual(result.numberOfShifts, expected.numberOfShifts);
            testCase.verifyEqual(result.shifts_fityesno, expected.shifts_fityesno);
            testCase.verifyEqual(result.shiftsNames, expected.shiftsNames);
            testCase.verifyEqual(result.shifts_constr, expected.shifts_constr);
            testCase.verifyEqual(result.shifts_horisontal, expected.shifts_horisontal);
            testCase.verifyEqual(result.numberOfScales, expected.numberOfScales);
            testCase.verifyEqual(result.scalefac_fityesno, expected.scalefac_fityesno);
            testCase.verifyEqual(result.scalesNames, expected.scalesNames);
            testCase.verifyEqual(result.scale_constr, expected.scale_constr);
            testCase.verifyEqual(result.scalefac, expected.scalefac);
            testCase.verifyEqual(result.numberOfNbas, expected.numberOfNbas);
            testCase.verifyEqual(result.nbairs_fityesno, expected.nbairs_fityesno);
            testCase.verifyEqual(result.nbaNames, expected.nbaNames);
            testCase.verifyEqual(result.nbairs_constr, expected.nbairs_constr);
            testCase.verifyEqual(result.nba, expected.nba);
            testCase.verifyEqual(result.numberOfNbss, expected.numberOfNbss);
            testCase.verifyEqual(result.nbsubs_fityesno, expected.nbsubs_fityesno);
            testCase.verifyEqual(result.nbsNames, expected.nbsNames);
            testCase.verifyEqual(result.nbsubs_constr, expected.nbsubs_constr);
            testCase.verifyEqual(result.nbs, expected.nbs);
            testCase.verifyEqual(result.numberOfResolutions, expected.numberOfResolutions);
            testCase.verifyEqual(result.resolution_fityesno, expected.resolution_fityesno);
            testCase.verifyEqual(result.resolNames, expected.resolNames);
            testCase.verifyEqual(result.resolution_constr, expected.resolution_constr);
            testCase.verifyEqual(result.resolution, expected.resolution);
            testCase.verifyEqual(result.contrastTypes, expected.contrastTypes);
            testCase.verifyEqual(result.contrastFileTypes, expected.contrastFileTypes);
            testCase.verifyEqual(result.forceReload, expected.forceReload);
            testCase.verifyEqual(result.simLimits, expected.simLimits);
            testCase.verifyEqual(result.dataLimits, expected.dataLimits);
            testCase.verifyEqual(result.fitlowrange, expected.fitlowrange);
            testCase.verifyEqual(result.fithirange, expected.fithirange);
            testCase.verifyEqual(result.repeatLayers, expected.repeatLayers);
            testCase.verifyEqual(result.datapath, expected.datapath);
            testCase.verifyEqual(result.contrastFiles, expected.contrastFiles);
            testCase.verifyEqual(result.contrastNames, expected.contrastNames);
            testCase.verifyEqual(result.contrastBacks, expected.contrastBacks);
            testCase.verifyEqual(result.contrastScales, expected.contrastScales);
            testCase.verifyEqual(result.contrastShifts, expected.contrastShifts);
            testCase.verifyEqual(result.contrastResolutions, expected.contrastResolutions);
            testCase.verifyEqual(result.contrastNbas, expected.contrastNbas);
            testCase.verifyEqual(result.contrastNbss, expected.contrastNbss);
            testCase.verifyEqual(result.contrastLayers, expected.contrastLayers);
            testCase.verifyEqual(result.contrastsNumberOfLayers, expected.contrastsNumberOfLayers);
            testCase.verifyEqual(result.ogDetails, expected.ogDetails);
            testCase.verifyEqual(result.data, expected.data);
            testCase.verifyEqual(result.include_data, expected.include_data);
            testCase.verifyEqual(result.dataPresent, expected.dataPresent);
            testCase.verifyEqual(result.calculations, expected.calculations);
            testCase.verifyEqual(result.algorithm, expected.algorithm);
            testCase.verifyEqual(result.eb, expected.eb);
            testCase.verifyEqual(result.plotType, expected.plotType);
            testCase.verifyEqual(result.dataShiftValue, expected.dataShiftValue);
            testCase.verifyEqual(result.q4, expected.q4);
            testCase.verifyEqual(result.useReducedChiSquared, expected.useReducedChiSquared);
            testCase.verifyEqual(result.simNPoints, expected.simNPoints);
            testCase.verifyEqual(result.resolType, expected.resolType);
            testCase.verifyEqual(result.backgrounds, expected.backgrounds);
            testCase.verifyEqual(result.qshifts, expected.qshifts);
            testCase.verifyEqual(result.scalefactors, expected.scalefactors);
            testCase.verifyEqual(result.nbairs, expected.nbairs);
            testCase.verifyEqual(result.nbsubs, expected.nbsubs);
            testCase.verifyEqual(result.resolutions, expected.resolutions);
            testCase.verifyEqual(result.fitpars, expected.fitpars);
            testCase.verifyEqual(result.otherpars, expected.otherpars);
            testCase.verifyEqual(result.fitconstr, expected.fitconstr);
            testCase.verifyEqual(result.otherconstr, expected.otherconstr);
            testCase.verifyEqual(result.fitNames, expected.fitNames);
            testCase.verifyEqual(result.shifted_data, expected.shifted_data);
            testCase.verifyEqual(result.which_contrast, expected.which_contrast);
            testCase.verifyEqual(result.update, expected.update);
            testCase.verifyEqual(result.update_params, expected.update_params);
            testCase.verifyEqual(result.maxiter, expected.maxiter);
            testCase.verifyEqual(result.Update, expected.Update);
            testCase.verifyEqual(result.calcFun, expected.calcFun);
            testCase.verifyEqual(result.resample, expected.resample);
            testCase.verifyEqual(result.calcSLD, expected.calcSLD);
            testCase.verifyEqual(result.resampleNLayers, expected.resampleNLayers);
            testCase.verifyEqual(result.resampleAngle, expected.resampleAngle);
            testCase.verifyEqual(result.priors, expected.priors);
            testCase.verifyEqual(result.reslution_constr, expected.reslution_constr);
        end

        function testProjectClassConversionWithModification(testCase)
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;

            pClass.layers.layersTable.("Hydrate with")(1) = hydrationTypes.BulkIn.value;
            pClass.contrasts.contrasts{1}.data = 'Simulation';

            result = projectClassToR1(pClass, "saveProject", false);

            testCase.verifyEqual(result.layersDetails{1}{6}, char(pClass.layers.layersTable.("Hydrate with")(1)));
            testCase.verifyEqual(result.contrastTypes{1}, pClass.contrasts.contrasts{1}.data);
        end

        function testR1ProblemInput(testCase)
            expected = load(testCase.inputStandardStruct).problem;

            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;

            result = projectClassToR1(pClass, "r1Problem", expected, "saveProject", true);

            testCase.verifyEqual(result.numberOfContrasts, expected.numberOfContrasts);
            testCase.verifyEqual(result.module.calculation_type, expected.module.calculation_type);
            testCase.verifyEqual(result.paramnames, expected.paramnames);
            testCase.verifyEqual(result.constr, expected.constr);
            testCase.verifyEqual(result.params, expected.params);
            testCase.verifyEqual(result.fityesno, expected.fityesno);
            testCase.verifyEqual(result.fiterrs, expected.fiterrs);
            testCase.verifyEqual(result.numberOfLayers, expected.numberOfLayers);
            testCase.verifyEqual(result.layersDetails, expected.layersDetails);
            testCase.verifyEqual(result.numberOfBacks, expected.numberOfBacks);
            testCase.verifyEqual(result.backgrounds_fityesno, expected.backgrounds_fityesno);
            testCase.verifyEqual(result.backs_constr, expected.backs_constr);
            testCase.verifyEqual(result.backs, expected.backs);
            testCase.verifyEqual(result.numberOfShifts, expected.numberOfShifts);
            testCase.verifyEqual(result.shifts_fityesno, expected.shifts_fityesno);
            testCase.verifyEqual(result.shifts_horisontal, expected.shifts_horisontal);
            testCase.verifyEqual(result.numberOfScales, expected.numberOfScales);
            testCase.verifyEqual(result.scalefac_fityesno, expected.scalefac_fityesno);
            testCase.verifyEqual(result.scalesNames, expected.scalesNames);
            testCase.verifyEqual(result.scale_constr, expected.scale_constr);
            testCase.verifyEqual(result.scalefac, expected.scalefac);
            testCase.verifyEqual(result.numberOfNbas, expected.numberOfNbas);
            testCase.verifyEqual(result.nbairs_fityesno, expected.nbairs_fityesno);
            testCase.verifyEqual(result.nbaNames, expected.nbaNames);
            testCase.verifyEqual(result.nbairs_constr, expected.nbairs_constr);
            testCase.verifyEqual(result.nba, expected.nba);
            testCase.verifyEqual(result.numberOfNbss, expected.numberOfNbss);
            testCase.verifyEqual(result.nbsubs_fityesno, expected.nbsubs_fityesno);
            testCase.verifyEqual(result.nbsNames, expected.nbsNames);
            testCase.verifyEqual(result.nbsubs_constr, expected.nbsubs_constr);
            testCase.verifyEqual(result.nbs, expected.nbs);
            testCase.verifyEqual(result.numberOfResolutions, expected.numberOfResolutions);
            testCase.verifyEqual(result.resolution_fityesno, expected.resolution_fityesno);
            testCase.verifyEqual(result.resolution_constr, expected.resolution_constr);
            testCase.verifyEqual(result.contrastTypes, expected.contrastTypes);
            testCase.verifyEqual(result.contrastFileTypes, expected.contrastFileTypes);
            testCase.verifyEqual(result.repeatLayers, expected.repeatLayers);
            testCase.verifyEqual(result.datapath, expected.datapath);
            testCase.verifyEqual(result.contrastFiles, expected.contrastFiles);
            testCase.verifyEqual(result.ogDetails, expected.ogDetails);
            testCase.verifyEqual(result.include_data, expected.include_data);
            testCase.verifyEqual(result.dataPresent, expected.dataPresent);
            testCase.verifyEqual(result.algorithm, expected.algorithm);
            testCase.verifyEqual(result.eb, expected.eb);
            testCase.verifyEqual(result.plotType, expected.plotType);
            testCase.verifyEqual(result.dataShiftValue, expected.dataShiftValue);
            testCase.verifyEqual(result.q4, expected.q4);
            testCase.verifyEqual(result.useReducedChiSquared, expected.useReducedChiSquared);
            testCase.verifyEqual(result.simNPoints, expected.simNPoints);
            testCase.verifyEqual(result.resolType, expected.resolType);
            testCase.verifyEqual(result.backgrounds, expected.backgrounds);
            testCase.verifyEqual(result.qshifts, expected.qshifts);
            testCase.verifyEqual(result.scalefactors, expected.scalefactors);
            testCase.verifyEqual(result.nbairs, expected.nbairs);
            testCase.verifyEqual(result.nbsubs, expected.nbsubs);
            testCase.verifyEqual(result.resolutions, expected.resolutions);
            testCase.verifyEqual(result.fitpars, expected.fitpars);
            testCase.verifyEqual(result.otherpars, expected.otherpars);
            testCase.verifyEqual(result.fitconstr, expected.fitconstr);
            testCase.verifyEqual(result.otherconstr, expected.otherconstr);
            testCase.verifyEqual(result.fitNames, expected.fitNames);
            testCase.verifyEqual(result.update, expected.update);
            testCase.verifyEqual(result.update_params, expected.update_params);
            testCase.verifyEqual(result.maxiter, expected.maxiter);
            testCase.verifyEqual(result.Update, expected.Update);
            testCase.verifyEqual(result.resample, expected.resample);
            testCase.verifyEqual(result.calcSLD, expected.calcSLD);
            testCase.verifyEqual(result.resampleNLayers, expected.resampleNLayers);
            testCase.verifyEqual(result.resampleAngle, expected.resampleAngle);
            testCase.verifyEqual(result.priors, expected.priors);
        end

        function testR1ProblemException(testCase)
            expected = load(testCase.outputStandardStruct).problem; % wrong r1 format
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            testCase.verifyError(@() projectClassToR1(pClass, "r1Problem", expected, "saveProject", false), unrecognizedR1Problem.errorID);
        end

        function testR1ProblemExtension(testCase)
            expected = load(testCase.inputStandardStruct).problem;
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            result = projectClassToR1(pClass, "fileName", 'test');

            testCase.verifyEqual(exist("test.mat",'file'), 2);
        end

        function testR1ProblemWithCustomLayers(testCase)
            expected = load(testCase.outputCustomStruct).problem;
            pClass = load(testCase.inputCustomProjectClass).thisProjectClass;
            result = projectClassToR1(pClass, "saveProject", true);

            testCase.verifyEqual(exist(testCase.modelFile,'file'), 2);
        end
    end
end




