%Read in the data
[h,dat] = hdrload('PLP001536.dat');

%..and split up the columns
q = dat(:,1);
r = dat(:,2);
e = dat(:,3);
dq = dat(:,4);

%Plot just to see what we have...
figure(1); clf
errorbar(q,r,e,'.-');
set(gca,'YScale','log','XScale','log');

%Get dq/q
res = dq./q;
