classdef testORSOValidation < matlab.unittest.TestCase
    %%
    % Runs ORSO Validations.
    %
    % (For now, we exclude test 4 and test 5, as these test resolution
    % functions which will diverge until phase 2 of the resolution calculations
    % is implemented)    

    properties
        orsoTolerance = 1.0e-10;
        orso_ref_data; % holder for orso reference data structure
        plot_test_results = false; % change to true if want to plot test
        % result as tests are progressing. Should set up break-point in the
        % test to see the images
    end

    properties (TestParameter)
        layersFile = {'test0.layers', 'test1.layers', 'test2.layers', 'test3.layers', 'test6.layers', 'test7.layers'}
        dataFile = {'test0.dat', 'test1.dat', 'test2.dat', 'test3.dat', 'test6.dat', 'test7.dat'}
        sample_number = num2cell(1:6);
        % layersFile = {'test0.layers', 'test1.layers', 'test2.layers', 'test3.layers', 'test0.layers', 'test1.layers', 'test6.layers', 'test7.layers'}
        % dataFile = {'test0.dat', 'test1.dat', 'test2.dat', 'test3.dat', 'test4.dat', 'test5.dat', 'test6.dat', 'test7.dat'}
    end
    methods
        function obj = testORSOValidation(varargin)
            if isfile('orso_reference_data.mat')
                ld = load('orso_reference_data.mat');
                obj.orso_ref_data = ld.ref_data;
            else
                this_folder = fileparts(mfilename('fullpath'));
                ref_data_location = fullfile(this_folder,'ORSO');
                obj = obj.construct_orso_ref_data(ref_data_location );
            end
        end

        function obj = construct_orso_ref_data(obj,ref_data_location)
            % Construct reference data structure for all ORSO datasets
            % and read reference datafiles
            %
            % Inputs:
            % ref_data_location -- folder containing reference datasets
            %
            % Returns:
            % obj               -- test file which contains initialized
            %                      reference information.
            %                      (in orso_ref_data property)
            % Stores reference structure in the test folder for rapid
            % recovery if the structure is not present
            % 
            ref_data = struct();

            % Test 0
            ref_data.name = 'Test 0';
            ref_data.BulkInSLD = 2.07e-6;
            ref_data.BulkOutSLD = 6e-6;
            ref_data.SubstrateRoughness = 5; % BulkOut roughness
            % layers model
            ref_data.LayerThickness = [100,200];
            ref_data.SLD_real = [3.45e-6, 5e-6];
            ref_data.SLD_img =  [1.e-7, 1e-8];
            ref_data.LayersRoughness =  [3, 1];
            % ref data
            ref_data.Data  = [];
            ref_data = repmat(ref_data,1,numel(obj.dataFile));
            %
            %
            ref_data(2).name = 'Test 1';
            ref_data(2).BulkInSLD  = 0;
            ref_data(2).BulkOutSLD = 2.0704e-6;
            ref_data(2).SubstrateRoughness = 0; % BulkOut roughness
            % layers model
            ref_data(2).LayerThickness = repmat([30,70],1,10);
            ref_data(2).SLD_real = repmat([-1.9493e-6,9.4245e-6],1,10);
            ref_data(2).SLD_img =  [];
            ref_data(2).LayersRoughness =  zeros(1,20);
            %
            %
            ref_data(3).name = 'Test 2';
            ref_data(3).BulkInSLD  = 0;
            ref_data(3).BulkOutSLD = 6.36e-6;
            ref_data(3).SubstrateRoughness = 3; % BulkOut roughness
            % layers model
            ref_data(3).LayerThickness = 0;
            ref_data(3).SLD_real = 0;
            ref_data(3).SLD_img =  [];
            ref_data(3).LayersRoughness =  0;
            %
            %
            ref_data(4).name = 'Test 3';
            ref_data(4).BulkInSLD  = 0;
            ref_data(4).BulkOutSLD = 6.36e-6;
            ref_data(4).SubstrateRoughness = 3; % BulkOut roughness
            % layers model
            BF =  [1001   1e+03*0.169705623424947]; % ~100*sqrt(3)
            ii = 1:2001;
            ref_data(4).LayerThickness = repmat(2.5e-2,1,2001);
            ref_data(4).SLD_real = 6.36e-6*(erf((ii-BF(1))/BF(2))+1)/2;
            ref_data(4).SLD_img =  [];
            ref_data(4).LayersRoughness =  zeros(1,2001);
            %
            %
            ref_data(5).name = 'Test 6';
            ref_data(5).BulkInSLD  = 2.07e-6;
            ref_data(5).BulkOutSLD = 6.36e-6;
            ref_data(5).SubstrateRoughness = 3; % BulkOut roughness
            % layers model
            ref_data(5).LayerThickness = 1200;
            ref_data(5).SLD_real = 4.66e-6;
            ref_data(5).SLD_img =  1.6e-8;
            ref_data(5).LayersRoughness =  10;
            %
            %
            ref_data(6).name = 'Test 7';
            ref_data(6).BulkInSLD  = 0;
            ref_data(6).BulkOutSLD = 6.36e-6;
            ref_data(6).SubstrateRoughness = 3; % BulkOut roughness
            % layers model
            ref_data(6).LayerThickness = 1200;
            ref_data(6).SLD_real = 4.66e-6;
            ref_data(6).SLD_img =  1.6e-8;
            ref_data(6).LayersRoughness =  10;

            for i=1:6
                ref_data(i).Data = readmatrix(fullfile(ref_data_location,obj.dataFile{i}));
                if size(ref_data(i).Data,2)==2
                    % expand data if necessary as RAT needs 3 column data
                    ref_data(i).Data = [ref_data(i).Data,zeros(size(ref_data(i).Data,1),1)];
                end
            end
            save('orso_reference_data.mat','ref_data');
            obj.orso_ref_data = ref_data;
        end

        function total_error = orsoWorkflowTest(obj,test_number)
            % retrieve particular orso reference data
            orso_info = obj.orso_ref_data(test_number);

            % set up common for orso tests project parameters and change
            % default project parameters to suppress default values not
            % used in ORSO data
            proj_name = orso_info.name;
            use_absorption = ~isempty(orso_info.SLD_img)&&any(orso_info.SLD_img>0);

            problem = createProject(name = proj_name,  absorption = use_absorption);
            problem.bulkIn.removeParameter('SLD Air');
            problem.bulkOut.removeParameter('SLD D2O');
            problem.background.backgroundParams.setParameter('Background Param 1','value',0,'min',0,'max',0);
            problem.scalefactors.setParameter('Scalefactor 1','value',1,'min',1,'max',1);
            problem.resolution.resolutionParams.setParameter('Resolution par 1','value',0,'min',0,'max',0);


            % set test specific parameters related to the enviroment
            problem.addBulkIn([proj_name,' BulkIn'], orso_info.BulkInSLD);
            problem.addBulkOut([proj_name,' BulkOut'], orso_info.BulkOutSLD);
            sr = orso_info.SubstrateRoughness;
            problem.setParameter('Substrate Roughness','value',sr,'min',sr,'max',sr);

            % define different set of layer parameters depending on
            % accounting for adsorbtion.
            use_param = true(1,4);
            param_val_names = {'LayerThickness','SLD_real','SLD_img','LayersRoughness'};
            layer_par_names = {' Thickness',' SLD real',' SLD imaginary',' Roughness'};
            if ~use_absorption
                use_param(3) = false;
            end
            param_val_names = param_val_names(use_param);
            layer_par_names = layer_par_names(use_param);

            % set up test specific parameters related to the model
            % (standard layers model only)
            layer_name = cell(1,numel(orso_info.LayerThickness));
            for i=1:numel(orso_info.LayerThickness)
                layer_name{i} = sprintf('Layer %d',i);
                param_names= cellfun(@(par_name)[layer_name{i},par_name],layer_par_names,'UniformOutput',false);

                idx = 1:numel(param_names);
                name_value_par = arrayfun(@(ii)({param_names{ii},orso_info.(param_val_names{ii})(i)}),idx,'UniformOutput',false);

                problem.addParameterGroup(name_value_par);
                problem.addLayer([layer_name{i};param_names(:)]);
            end
            % set up test data (used as reference data)
            problem.addData([proj_name,' Data'], orso_info.Data);
            % define theoretical contrast
            problem.addContrast('name', [proj_name,' Data'],...
                'BulkIn', [proj_name,' BulkIn'],...
                'BulkOut', [proj_name,' BulkOut'],...
                'background','Background 1',...
                'backgroundAction','add',...
                'scalefactor','Scalefactor 1',...
                'resolution','Resolution 1',...
                'model',layer_name,...
                'data', [proj_name,' Data']);

            % run model simulation
            controls = controlsClass();
            [out_proj,results] = RAT(problem,controls);

            % plot results
            if obj.plot_test_results
                fh = figure;
                clOb = onCleanup(@()close(fh));
                plotRefSLD(out_proj,results);
            end

            total_error = sum((results.reflectivity{1}(:, 2) - results.shiftedData{1}(:, 2)).^2);
        end


    end

    methods (Test, ParameterCombination='sequential')

        % function testORSO(testCase, layersFile, dataFile)
        %     testCase.verifyLessThanOrEqual(testORSOValidation.orsoTest(layersFile, dataFile), testCase.orsoTolerance, 'ORSO test has failed');
        % end
        function testORSOWorkflow(testCase,sample_number)
            testCase.verifyLessThanOrEqual(testCase.orsoWorkflowTest(sample_number), testCase.orsoTolerance, 'ORSO workflow test has failed');
        end

    end

    methods (TestClassTeardown)
        function clear(~)
            close all  % Close figure after run
        end
    end

    methods (Static)

        function out = orsoTest(layersFile, dataFile)
            % old orso validation test, not currently used and left for
            % references only
            % The reference data for this test are stored in ORSO folder
            layers = dlmread(layersFile);

            % Change the units to Å^-2
            layers(:,2) = layers(:,2) .* 1e-6;
            layers(:,3) = layers(:,3) .* 1e-6;

            % Read in the data.....
            data = dlmread(dataFile);

            % Group the Layers
            thick = layers(:,1);
            sld = complex(layers(:,2),layers(:,3));
            rough = layers(:,4);

            % Calculate reflectivity...
            q = data(:,1);
            N = size(layers,1);
            ref = abelesSingle(q,N,thick,sld,rough);

            % Plot the comparison....
            figure(1); clf
            semilogy(q,ref,'k-','LineWidth',2)
            hold on
            plot(data(:,1),data(:,2),'r.')

            % Calculate the output....
            out = sum(sum((data(:,2) - ref).^2));

        end
    end
end