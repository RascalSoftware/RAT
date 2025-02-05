function output_data = readOrso(filename)
% Read data from an .ort file. 
% 
% Parameters
% ----------
% filename : string
%   The path to the .ort file.
%
% Returns
% -------
% output_data : array
%   The data array from the .ort file.

  text = fileread(filename);
  % match any line that doesn't start with '#'
  % i.e. remove the header
  expr = '^[^#].+';

  match = regexp(text, expr, 'match', 'lineanchors');
  output_data = str2num(match{1});
end

