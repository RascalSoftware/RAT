clear
figure(1); clf

chain = load('chain');
chain = chain.chain;

x = chain(:,1);
y = chain(:,2);

data = [x(:) y(:)];





[bandwidth,density,X,Y]=kde2d(data);


clf

contour(X,Y,density,50)

%N = hist3(data);

% [~,~,p.ess]=eacorr(m);
% p.ess=mean(p.ess);
%contour(N,'k-')



% [~,N,X,Y] = kde2d(data,2^9);
% 
% N=N/sum(N(:));
% NS=sort(N(:));
% %levels = interp1q(cumsum(NS))'; %HDI LEVELS
% contourf(X,Y,N);
