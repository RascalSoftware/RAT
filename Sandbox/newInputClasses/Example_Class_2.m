classdef Example_Class_2 < standardParameters_new & matlab.mixin.CustomDisplay
    properties
        Property3
    end
    methods (Hidden)
        function value = properties( obj )
            propList = struct('Property3', obj.Property3,...
                'showPriors', obj.showPriors,...
                'T', obj.T);
            
%             if nargout == 0
%                 for i = 1:length(proplist)
%                     disp(propList{i});
%                 end
%             else
                value = propList;
            %end
        end
%         function value = fieldnames( obj )
%             value = sort( builtin( "fieldnames", obj ) );
%         end
    end
    methods (Access = protected)
       function group = getPropertyGroups( obj )
            props = properties( obj );
            group = matlab.mixin.util.PropertyGroup( props );
       end
       
       function displayScalarObject(obj)
           pr = properties(obj);
            array = obj.T;
            p = [1:size(array,1)];
            p = p(:);
            p = table(p);
            
            if ~obj.showPriors
                array = array(:,1:5);
            end
            all = [p array];
            disp(all);
        end
       
       
    end
end