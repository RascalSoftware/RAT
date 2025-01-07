
layersFile = {'test0.layers', 'test1.layers', 'test2.layers', 'test3.layers', 'test6.layers', 'test7.layers'};
dataFile = {'test0.dat', 'test1.dat', 'test2.dat', 'test3.dat', 'test6.dat', 'test7.dat'};


for i = 1:length(layersFile)

            layers = layersFile{i};
            layers = dlmread(layers);
    
            % Change the units to Å
            layers(:,2) = layers(:,2) .* 1e-6;
            layers(:,3) = layers(:,3) .* 1e-6;
    
            % Read in the data.....
            data = dlmread(dataFile{i});
    
            % Group the Layers
            thick = layers(:,1);
            sld = complex(layers(:,2),layers(:,3));
            rough = layers(:,4);
    
            % Calculate reflectivity...
            q = data(:,1);
            N = size(layers,1);
            ref = abelesSingle(q,N,thick,sld,rough);
    
            % Plot the comparison....
            figure(1); clf
            semilogy(q,ref,'k-','LineWidth',2)
            hold on
            plot(data(:,1),data(:,2),'r.')
    
            % Calculate the output....
            out = sum(sum((data(:,2) - ref).^2));





end