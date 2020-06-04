classdef newBgTest
    
    
    properties
        nBackgrounds = 1;
        backgrounds = {1 'Background 1' 'constant' [1e-6] [1e-7] [1e-5] [1]};
        
    end
    
    
    methods
        
        function obj = set.nBackgrounds(obj,nBacks)
            if (isnan(nBacks) || isinf(nBacks) || mod(nBacks,1) ~= 0)
                error('nParams must be real integer');
            end
            obj.nBackgrounds = nBacks;
            obj = obj.resizeBackgrounds(nBacks);
        end
        
        
        function obj = disp(obj,val)
            %Show nBackgrounds
            fprintf('nBackgrounds: %d',obj.nBackgrounds);
            fprintf('\n');
            fprintf('\t Name \t \t Type \t\t Val \t\t Min \t\t Max \t\t Fit? \n')
            for i = 1:obj.nBackgrounds
                thisName = obj.backgrounds{i,2};
                thisType = obj.backgrounds{i,3};
                thisVal = obj.backgrounds{i,4};
                thisMin = obj.backgrounds{i,5};
                thisMax = obj.backgrounds{i,6};
                thisFYN = obj.backgrounds{i,7};
                
                fprintf(['%d \t''' thisName '''\t''' thisType '''\t %d \t %d \t %d \t %d \n'],...
                    i,thisVal,thisMin,thisMax,thisFYN);
            end
            fprintf('\n')
        end
        
        function obj = set.backgrounds(obj,val)
            
            disp('debug');
            
        end
        
        
    end
    
    methods (Access = private)
        
        function obj = resizeBackgrounds(obj,nBacks)
            currentSize = size(obj.backgrounds,1);
            if nBacks > currentSize
                numberToAdd = nBacks - currentSize;
                for i = 1:numberToAdd
                    backNum = currentSize + i;
                    thisBackName = ['Background ' num2str(backNum)];
                    thisCell = {backNum thisBackName 'constant' 1e-6 1e-7 1e-8 0};
                    obj.backgrounds((currentSize + i),:) = thisCell;
                end
                
            end
        end
        
    end
end


