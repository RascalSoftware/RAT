% Confusing input types!!!!


% % 1 No input at all.
% p.addContrast()
% varargin =
%     1×1 cell array
%     {0×0 cell}
% 
% -   length(varargin) = 1
%     isempty(varargin) = logical 0
%   
%     varargin{:} - 0x0 empty cell array
%     length(varargin{:}) = 0
%     isempty(varargin{:}) - logical 1
% 
% 
%   
%  % 2. Just name string
%  p.addContrast('my contrast')
%  varargin =
%     1×1 cell array
%     {1×1 cell}
%     
%     length(varargin) = 1
%     isempty(varargin) = logical 0
%   
%     varargin{:} - 1×1 cell array - {'my contrast'}
%     length(varargin{:}) = 1
%     isempty(varargin{:}) - logical 1
%   
%   
%  % Longer input
%  p.addContrast('name','my contrast','backround','background 1')
%  
%  varargin = 
%     1×1 cell array
%     {1×4 cell}
%     
%     length(varargin) = 1
%     isempty(varargin) = logical 0
%     
%     varargin{:} = 1×4 cell array  - {'name'}    {'my contrast'}    {'backround'}    {'background 1'}
%     length(varargin{:}) = 4
%     isempty(varargin{:}) - logical 0
    
    
    