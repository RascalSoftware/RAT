fid = fopen('testfile1');
a = cell(1,1);
a(1) = {fgetl(fid)};
fclose(fid);