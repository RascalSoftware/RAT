function parseTest2()

%myarea = findArea('rectangle',3,5)

%pars = {'shape','rectangle','dim1',[1 3 5]};%,'dim2',{[1 5]}};
p = findArea('shape','rectangle','dim1',[1 3]);

end


function p = findArea(varargin)
   
   
   p = inputParser;
   
   isDims = @(x)all(size(x)==[1,2]);

   addParameter(p,'shape','',@(x) ischar(x))
   addParameter(p,'dim1',[1 2], @(x) isnumeric(x) && isDims(x))
   addParameter(p,'dim2',[],  @(x) isnumeric(x) && isDims(x))
   parse(p,varargin{:});
 
   p.Results 
   
end