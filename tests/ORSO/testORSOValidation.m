classdef testORSOValidation < matlab.unittest.TestCase
    %%
    % Runs ORSO Validations.

    properties
        orsoTolerance = 1.0e-10;
        orso_ref_data; % store
    end

    properties (TestParameter)
        layersFile = {'test0.layers', 'test1.layers', 'test2.layers', 'test3.layers', 'test6.layers', 'test7.layers'}
        dataFile = {'test0.dat', 'test1.dat', 'test2.dat', 'test3.dat', 'test6.dat', 'test7.dat'}
        % layersFile = {'test0.layers', 'test1.layers', 'test2.layers', 'test3.layers', 'test0.layers', 'test1.layers', 'test6.layers', 'test7.layers'}
        % dataFile = {'test0.dat', 'test1.dat', 'test2.dat', 'test3.dat', 'test4.dat', 'test5.dat', 'test6.dat', 'test7.dat'}
    end
    methods
        function obj = testORSOValidation(varargin)
            if isfile('orso_reference_data.mat')
                ld = load('orso_reference_data.mat');
                obj.orso_ref_data = ld.orso_ref_data;
            else
                this_folder = fileparts(mfilename('fullpath'));
                ref_data_location = fullfile(this_folder);
                obj = obj.construct_orso_ref_data(ref_data_location );
            end
        end
        function obj = construct_orso_ref_data(obj,ref_data_location)
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
            ref_data(4).LayerThickness = repmat(2.5,1,2001);
            ref_data(4).SLD_real = 6.36e-6*(erf((ii-BF(1))/BF(2))+1)/2;
            ref_data(4).SLD_img =  [];
            ref_data(4).LayersRoughness =  zeros(1,2001);

            for i=1:4
                ref_data(i).Data = readmatrix(fullfile(ref_data_location,obj.dataFile{i}));
                if size(ref_data(i).Data,2)==2
                    % expand data if necessary as RAT needs 3 column data
                    ref_data(i).Data = [ref_data(i).Data,zeros(size(ref_data(i).Data,1),1)];
                end
            end

            obj.orso_ref_data = ref_data;
        end

    end

    methods (Test, ParameterCombination='sequential')

        function testORSO(testCase, layersFile, dataFile)
            testCase.verifyLessThanOrEqual(testORSOValidation.orsoTest(layersFile, dataFile), testCase.orsoTolerance, 'ORSO test has failed');
        end

    end

    methods (TestClassTeardown)
        function clear(~)
            close all  % Close figure after run
        end
    end

    methods (Static)

        function total_error = orsoTest2(orso_info)

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
            problem.resolution.resolutionParams.setParameter('Resolution par 1','value',0,'min',0,'max',0)


            % set test specific parameters related to enviroment
            problem.addBulkIn([proj_name,' BulkIn'], orso_info.BulkInSLD);
            problem.addBulkOut([proj_name,' BulkOut'], orso_info.BulkOutSLD);
            sr = orso_info.SubstrateRoughness;
            problem.setParameter('Substrate Roughness','value',sr,'min',sr,'max',sr);
            layer_name = cell(1,numel(orso_info.LayerThickness));
            use_param = true(1,4);
            param_val_names = {'LayerThickness','SLD_real','SLD_img','LayersRoughness'};
            if ~use_absorption
                use_param(3) = false;
            end
            param_val_names = param_val_names(use_param);
            % set up test specific parameters related to model
            for i=1:numel(orso_info.LayerThickness)
                layer_name{i} = sprintf('Layer %d',i);
                param_names = {[layer_name{i},' Thickness'],...
                    [layer_name{i},' SLD real'],[layer_name{i},' SLD imaginary'],[
                    layer_name{i},' Roughness']};
                if ~use_absorption
                    param_names = param_names(use_param);
                end
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

            fh = figure;
            clOb = onCleanup(@()close(fh));
            plotRefSLD(out_proj,results);

            total_error = sum((results.reflectivity{1}(:, 2) - results.shiftedData{1}(:, 2)).^2);
        end

        function out = orsoTest(layersFile, dataFile)

            layers = dlmread(layersFile);

            % Change the units to Å
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
        % orso_project.contrasts.set_fields(
        %     "ORSO Contrast",
        %     data=f"Data {test_index}",
        %     bulk_in=f"Bulk In {test_index}",
        %     bulk_out=f"Bulk Out {test_index}",
        %     model=layer_model,
        % )
        %
        % controls = RAT.Controls(procedure="calculate")
        % output_project, results = RAT.run(orso_project, controls)
        %
        % plot_ref_sld(output_project, results)
        %
        % total_error = sum((results.reflectivity[0][:, 1] - results.shiftedData[0][:, 1]) ** 2)
        %
        % assert total_error < 1e-10
    end
end