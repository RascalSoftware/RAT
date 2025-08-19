classdef testORSOValidation < matlab.unittest.TestCase
    %%
    % Runs ORSO Validations.
    % (For now, we exclude test 4 and test 5, as these test resolution
    % functions which will diverge until phase 2 of the resolution calculations
    % is implemented)

    properties
        orsoTolerance = 1.0e-10;
    end

    properties (TestParameter)
        layersFile = {'test0.layers', 'test1.layers', 'test2.layers', 'test3.layers', 'test6.layers', 'test7.layers'}
        dataFile = {'test0.dat', 'test1.dat', 'test2.dat', 'test3.dat', 'test6.dat', 'test7.dat'}
        % layersFile = {'test0.layers', 'test1.layers', 'test2.layers', 'test3.layers', 'test0.layers', 'test1.layers', 'test6.layers', 'test7.layers'}
        % dataFile = {'test0.dat', 'test1.dat', 'test2.dat', 'test3.dat', 'test4.dat', 'test5.dat', 'test6.dat', 'test7.dat'}
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
        function out = orsoTest2(layersFile,dataFile)
            orso_info = struct();
            orso_info.SubstrateRoughness = 3;
            orso_info.BulkInSLD = 2.07e-7;
            orso_info.BulkOutSLD = 6e-6;
            orso_info.LayerThickness = [100,200];
            orso_info.SLD_real = [3.45e-6, 5e-6];
            orso_info.SLD_img =  [1.e-7, 1e-8];
            orso_info.LayersRoughness =  [3, 1];
            orso_info.BulkOut_Roughness = 5;
            orso_info.Data =  readmatrix(dataFile);
            orso_info.Data =  [orso_info.Data,zeros(size(orso_info.Data,1),1)];

            % set up generic project parameters
            problem = createProject(name = 'Test 1',  absorption = true);
            problem.bulkIn.removeParameter('SLD Air');
            problem.bulkOut.removeParameter('SLD D2O');
            problem.addParameter('Background 1',0);
            %problem.setScalefactor('Scalefactor 1','value',1.0);

            % set test specific parameters
            problem.addBulkIn('Test 1 BulkIn', orso_info.BulkInSLD);
            problem.addBulkOut('Test 1 BulkOut', orso_info.BulkOutSLD);
            for i=1:numel(orso_info.LayerThickness)

                problem.addParameterGroup({ ...
                    {sprintf('Layer %d Thickness',i ),orso_info.LayerThickness(i)},...
                    {sprintf('Layer %d SLD real',i ),orso_info.SLD_real(i)},...
                    {sprintf('Layer %d SLD imaginary',i ),orso_info.SLD_img(i)},...
                    {sprintf('Layer %d Roughness',i ),orso_info.LayersRoughness(i)}});
                problem.addLayer( ...
                    sprintf('Layer %d',i),...
                    sprintf('Layer %d Thickness',i ),...
                    sprintf('Layer %d SLD real',i ),...
                    sprintf('Layer %d SLD imaginary',i ),...
                    sprintf('Layer %d Roughness',i ));
            end
            problem.addData('Test 1 Data', orso_info.Data);
            problem.addContrast('name', 'Test 1 Data',...
                'BulkIn', 'Test 1 BulkIn',...
                'BulkOut', 'Test 1 BulkOut',...
                'background','Background 1',...
                'scalefactor','Scalefactor 1',...
                'resolution','Resolution 1',...
                'data', 'Test 1 Data');

            controls = controlsClass();
            [out_proj,results] = RAT(problem,controls);

            fh = figure;
            clOb = onCleanup(@()close(fh));
            plotRefSLD(out_proj,results);

            total_error = sum((results.reflectivity{1}(:, 1) - results.shiftedData{1}(:, 1)).^2);
            out = total_error<1.e-10;
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