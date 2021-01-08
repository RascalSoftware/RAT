function [ pname,page ] = persontest( name,age )
%#codegen

page = int32(0);
coder.varsize('pname',[1,1024],[0,1]);
pname = char(zeros(1,1024));
mypersonptr = coder.opaque('persontype','HeaderFile','personwrapper.h');
mypersonptr = coder.ceval('person_constructor');
coder.ceval('set_name_wrapper',mypersonptr,name);
coder.ceval('set_age_wrapper',mypersonptr,age);
coder.ceval('get_name_wrapper',mypersonptr,coder.wref(pname(1)));
page = coder.ceval('get_age_wrapper',mypersonptr);
coder.ceval('person_destructor',mypersonptr);
end

