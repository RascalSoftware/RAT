function mySmallFunc(priors)

fprintf('Hello world!');

names = priors.priorNames;
vals = priors.priorVals;

parPos = find(strcmp(names,'Substrate Roughness'));

coder.varsize('newPos',[1,1],[0,0]);
newPos = 1;
if length(parPos) > 1
    newPos = parPos(1);
elseif isempty(parPos)
    newPos = 1;
end
    

value = str2double(vals{newPos,3})

end