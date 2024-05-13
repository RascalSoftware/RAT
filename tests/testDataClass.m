classdef testDataClass < matlab.unittest.TestCase   
    
    properties
        data
        datasets
    end

    methods(TestMethodSetup)
        function createData(testCase)
            testCase.datasets = {
                    %  Name            data          data range  simulation range 
                    'Bilayer / D2O',   [],          [],        [];
                    'Bilayer / SMW',   repmat(-1:1, 3, 1)',   [-1, 1],       [-2, 2];
                    'Bilayer / H2O',   ones(5, 3),    [0.2, 0.9],    [-3, 6];
                };
            testCase.data = dataClass();
        end
    end
    methods
        function addDataSets(testCase)
            % Adds datasets for the tests
            for i = 1:size(testCase.datasets, 1)
                testCase.data.varTable(i+1, :) = {testCase.datasets(i, 1), {testCase.datasets(i, 2)},...
                                                   {testCase.datasets(i, 3)}, {testCase.datasets(i, 4)}};
            end
        end
    end

    methods (Test)
        function testCreation(testCase)
            % Tests data class can be created and the first dataset is set correctly 
            newData = dataClass();
            default = {"New data 1", {[]}, {[]}, {[0.0050, 0.7000]}};
            for i = 1:4
                testCase.verifyEqual(newData.varTable{1, i}, default{i}, 'Data default not set correctly');
            end
            testCase.verifySize(newData.varTable, [1, 4], 'Data has wrong dimension');
            
            newData = dataClass(testCase.datasets{2, :});
            default = {"Bilayer / SMW", {repmat(-1:1, 3, 1)'}, {[-1, 1]}, {[-2, 2]}};
            for i = 1:4
                testCase.verifyEqual(newData.varTable{1, i}, default{i}, 'Data default not set correctly');
            end
            testCase.verifySize(newData.varTable, [1, 4], 'Data has wrong dimension');
        end

        function testGetNames(testCase)
            % Tests getNames returns correctly  
            names = testCase.data.getNames();
            testCase.verifyEqual(names, "New data 1", 'Start data not set correctly');
            testCase.verifySize(names, [1, 1], 'data has wrong dimension');

            testCase.addDataSets();
            names = testCase.data.getNames();
            testCase.verifyEqual(names, ["New data 1"; convertCharsToStrings(testCase.datasets(:, 1))], 'Start data not set correctly');
            testCase.verifySize(names, [size(testCase.datasets, 1)+1, 1], 'data has wrong dimension');
        end

        function testAddData(testCase)
            % Checks that data can be added                    
            testCase.data.addData('Sim 2', ones(4, 3));
            testCase.verifySize(testCase.data.varTable, [2, 4], 'data has wrong dimension');
            testCase.verifyEqual(testCase.data.varTable{:, 1}, ["New data 1"; "Sim 2"], 'addData method not working');
            testCase.data.addData('Sim 3');
            testCase.verifySize(testCase.data.varTable, [3, 4], 'data has wrong dimension');
            testCase.verifyEqual(testCase.data.varTable{:, 1}, ["New data 1"; "Sim 2"; "Sim 3"], 'addData method not working');
            testCase.data.addData(testCase.datasets{2, :});
            testCase.verifySize(testCase.data.varTable, [4, 4], 'data has wrong dimension');
            testCase.verifyEqual(testCase.data.varTable{:, 1}, ["New data 1"; "Sim 2"; "Sim 3"; "Bilayer / SMW"], 'addData method not working');
            testCase.verifyError(@() testCase.data.addData('Sim 2'), exceptions.duplicateName.errorID);  % duplicates not allowed
            testCase.verifyError(@() testCase.data.addData(1), exceptions.invalidType.errorID);  % name should be string
            testCase.verifyError(@() testCase.data.addData('Another Sim', 'data'), exceptions.invalidType.errorID);  % data should not string
            testCase.verifyError(@() testCase.data.addData('Another Sim', zeros(4, 3), [-1, 1]), exceptions.invalidNumberOfInputs.errorID); % argument should be 1, 2 or 4
            testCase.verifyError(@() testCase.data.addData('Another Sim', zeros(4, 3), [-1, 1, 6], [-0.5, 0.5]), exceptions.invalidType.errorID);  % range should be length 2
            testCase.verifyError(@() testCase.data.addData('Another Sim', zeros(4, 3), [-1, 1], [-0.5, 2, 0.5]), exceptions.invalidType.errorID);  % range should be length 2
            testCase.data.addData();
            testCase.verifySize(testCase.data.varTable, [5, 4], 'data has wrong dimension');
            testCase.verifyEqual(testCase.data.varTable{:, 1}, ["New data 1"; "Sim 2"; "Sim 3"; "Bilayer / SMW"; "New data 5"], 'addData method not working');
            testCase.verifyError(@() testCase.data.addData('Another Sim', repmat(1:-1:-1, 3, 1)'), exceptions.invalidValue.errorID);
            % addRow changes the ranges to match the data and throws warning
            testCase.verifyWarning(@() testCase.data.addData('Another Sim', zeros(4, 3), [-1, 1], [0, 0]), '');  
            testCase.verifyEqual(testCase.data.varTable{end, 3}, {[0, 0]}, 'addData method not working');
            testCase.verifyWarning(@() testCase.data.addData('d2', zeros(4, 3), [0, 0], [1, -1]), '');
            testCase.verifyEqual(testCase.data.varTable{end, 4}, {[0, 0]}, 'addData method not working');
            testCase.verifyWarning(@() testCase.data.addData('d3', zeros(4, 3), [1, -1], []), '');
            testCase.verifyEqual(testCase.data.varTable{end, 3}, {[0, 0]}, 'addData method not working');    
        end
        
        function testSetdata(testCase)
            % Checks that data can be modified
            testCase.addDataSets();
            names = testCase.data.setData(1, 'name', 'Sim 1', 'data', zeros(4, 3), 'dataRange', [0, 1],'simRange', [1, 2]);
            expected = {"Sim 1", {zeros(4, 3)}, {[0, 0]}, {[0, 2]}};
            for i = 1:4
                testCase.verifyEqual(testCase.data.varTable{1, i}, expected{i}, 'setData method not working');
            end
            testCase.verifyEqual(names.oldName, "New data 1", 'setData returned incorrect data');
            testCase.verifyEqual(names.newName, 'Sim 1', 'setData returned incorrect data');
            names = testCase.data.setData('Bilayer / SMW', 'name', 'Sim 2', 'data', ones(4, 3), 'dataRange', [-1, 1],'simRange', [1, 3]);
            expected = {"Sim 2", {ones(4, 3)}, {[1, 1]}, {[1, 3]}};
            for i = 1:4
                testCase.verifyEqual(testCase.data.varTable{3, i}, expected{i}, 'setData method not working');
            end
            testCase.verifyEqual(names.oldName, string(testCase.datasets{2, 1}), 'setData returned incorrect data');
            testCase.verifyEqual(names.newName, 'Sim 2', 'setData returned incorrect data');
            testCase.verifyError(@() testCase.data.setData(1, 'name'), exceptions.invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.data.setData('5', 'name', 'data_name'), exceptions.nameNotRecognised.errorID);
            testCase.verifyError(@() testCase.data.setData(5, 'name', 'data_name'), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.data.setDataName(1, 56), exceptions.invalidType.errorID);
            testCase.verifyError(@() testCase.data.setDataName(1, 'Sim 2'), exceptions.duplicateName.errorID);
            names = testCase.data.setDataName(1, 'Sim 3');
            testCase.verifyEqual(testCase.data.varTable{1, 1}, "Sim 3", 'setDataName method not working');
            testCase.verifyEqual(names.oldName, "Sim 1", 'setData returned incorrect data');
            testCase.verifyEqual(names.newName, 'Sim 3', 'setData returned incorrect data');
         end

        function testDisplayTable(testCase)
            % Check that the content of the data table are printed
            actualHeader = {'Name', 'Data', 'Data Range', 'Simulation Range'};
            
            display = evalc('testCase.data.displayTable()');
            testCase.verifyNotEmpty(display, 'displayTable method not working');
            
            displayArray = textscan(display,'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            % display table should be height of data table plus header and divider row
            testCase.verifyLength(displayArray, height(testCase.data.varTable) + 2);
            % Remove html tags used to format header then split table when
            % 2 or more spaces are found to avoid splitting names with single space
            displayHeader = eraseBetween(displayArray{1}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, actualHeader);
            actualRow = ["New data 1", "No Data", "-", "[ 0.0050 , 0.7000 ]"];
	        row = regexp(displayArray{3}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(actualHeader));
            testCase.verifyEqual(row, string(actualRow), 'displayTable method not working')
                   
            testCase.data.varTable(2, :) = {testCase.datasets(2, 1), testCase.datasets(2, 2), testCase.datasets(2, 3), []};
            display = evalc('testCase.data.displayTable()');
            displayArray = textscan(display,'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            testCase.verifyLength(displayArray, height(testCase.data.varTable) + 2);
            displayHeader = eraseBetween(displayArray{1}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, actualHeader);
            actualRow = ["Bilayer / SMW", "Data array: [3 x 3]", "[ -1.0000 , 1.0000 ]", "-"];
	        row = regexp(displayArray{4}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(actualHeader));
            testCase.verifyEqual(row, string(actualRow), 'displayTable method not working');
        end
    end
end
