[A,ffn,nh,SR,hl,fpos] = txt2mat('ParaDRAM_run_20210908_101834_809_process_1_chain.txt');

chain = A(:,8:end);

figure(1); clf
thisChain = chain(:,end-3);
histogram(thisChain,'Normalization','probability')
