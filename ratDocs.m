% Opens the documentation in the System browser.
versionRegex = ['(0|[1-9]\d*)\.(0|[1-9]\d*)\.(0|[1-9]\d*)' ...
                 '(?:-((?:0|[1-9]\d*|\d*[a-zA-Z-][0-9a-zA-Z-]*)' ...
                 '(?:\.(?:0|[1-9]\d*|\d *[a-zA-Z-][0-9a-zA-Z-]*))*))?' ...
                 '(?:\+([0-9a-zA-Z-]+(?:\.[0-9a-zA-Z-]+)*))?'];

version = {};
url = 'https://rascalsoftware.github.io/RAT/';
versionURL = '';

try
   versionText = fileread('version.txt');
   tokens = regexp(versionText, versionRegex, 'tokens');
   versionURL = [url, tokens{1}{1}, '.', tokens{1}{2}, '/'];
   webread(versionURL);  % Check the page can be found
   url = versionURL;
catch ME
     switch ME.identifier
        case 'MATLAB:webservices:HTTP404StatusCodeError'
            fprintf('Loading %s\n', url);
        otherwise
            fprintf('Something happened when trying to load %s\n: %s\n', versionURL, ME.message);
     end
end    

web(url);
