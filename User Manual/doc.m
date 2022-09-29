function    doc( varargin )
    
    persistent mdc
    if isempty( mdc )
      wch = which('doc.m','-all'); 
      isf = contains( wch, matlabroot ); % there should only be one
      wch = wch{isf};
      pth = fileparts( wch );
      old = cd( pth ); 
      mdc = str2func('doc');  % create a function-handle
      cd( old ); 
    end    
    
    switch varargin{1}
        case 'rat'
            web('index.html', '-new')
        otherwise
            mdc( varargin{:} )
    end
end