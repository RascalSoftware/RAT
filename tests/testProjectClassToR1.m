classdef testProjectClassToR1 < matlab.unittest.TestCase

    properties
        inputProjectClass
        inputStruct
        output
    end

    methods(TestClassSetup)
        function defineIO(testCase)
            testCase.inputProjectClass = "originalDSPCBilayerProjectClass.mat";
            testCase.inputStruct = "originalDSPCBilayerStructInput.mat";
            testCase.output = "originalDSPCBilayerStructOutput.mat";
        end

        function setWorkingFolder(testCase)
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
        end

    end

    methods (Test)

        function testFileExists(testCase)
            % verify output file exists with .m extension
            testCase.verifyEqual(exist(testCase.output,'file'), 2);

            % verify inputProjectClass exists with .m extension
            testCase.verifyEqual(exist(testCase.inputProjectClass,'file'), 2);

            % verify inputStruct exists with .m extension
            testCase.verifyEqual(exist(testCase.inputStruct,'file'), 2);
        end

        function testCompareProjectClassToR1(testCase)

            % Load expected R1 struct
            expected = load(testCase.output).problem;

            % Create the R1 struct result
            pClass = load(testCase.inputProjectClass).thisProjectClass; %loads project class
            result = projectClassToR1(pClass, "saveProject", false);

            % verify ALL the field of result and expected match
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

            % Load Project Class
            pClass = load(testCase.inputProjectClass).thisProjectClass;

            % Modify Project Class
            pClass.layers.layersTable.("Hydrate with")(1) = "bulk in";
            pClass.contrasts.contrasts{1}.data = 'Simulation';

            % Create R1 struct result
            result = projectClassToR1(pClass, "saveProject", true);

            % Verify changes
            testCase.verifyEqual(result.layersDetails{1}{6}, char(pClass.layers.layersTable.("Hydrate with")(1)));
            testCase.verifyEqual(result.contrastTypes{1}, pClass.contrasts.contrasts{1}.data);

        end

        function testR1ProblemInput(testCase)

            % Load R1 struct
            expected = load(testCase.inputStruct).problem;

            % Load Project Class
            pClass = load(testCase.inputProjectClass).thisProjectClass;

            % Create R1 struct result
            result = projectClassToR1(pClass, "r1Problem", expected);

            % verify MOST of the field of result and expected match
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

            % Load wrong R1 struct
            expected = load(testCase.output).problem;

            % Load Project Class
            pClass = load(testCase.inputProjectClass).thisProjectClass;

            % Verify exception raised
            testCase.verifyError(@() projectClassToR1(pClass, "r1Problem", expected), 'RAT:unrecognizedR1Problem');

        end
    end
end




