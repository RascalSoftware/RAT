

% RAT Model File for 20nM_data 
% Created by RasCAL 07-Jul-2022 
problem = projectClass('20nM_data'); 

problem.ModelType = 'standard layers'; 
problem.Geometry = 'air/substrate'; 



%% Setting of Parameters Block

problem.addParam({'Tails thick',	12,	18.77,	20,	true}); 
problem.addParam({'Deuterated tails SLD',	5e-06,	6.936e-06,	9e-06,	true}); 
problem.addParam({'Tails roughness',	3,	3,	7,	true}); 
problem.addParam({'Hydrogenated tails SLD',	-6e-07,	-2.191e-07,	-2e-07,	true}); 
problem.addParam({'Head thickness',	7,	7,	12,	true}); 
problem.addParam({'Deuterated head SLD',	3e-06,	5.855e-06,	6e-06,	true}); 
problem.addParam({'Head roughness',	3,	3,	7,	true}); 
problem.addParam({'Hydrogenated head SLD',	1e-06,	1.808e-06,	2e-06,	true}); 
problem.addParam({'Head hydration',	0,	9.337,	20,	true}); 



%% Setting of Layers Block

Layer1 = {  
	'Deuterated tails',...	%Layer Name 
	'Tails thick',...
	'Deuterated tails SLD',...
	'Tails roughness',...
	 NaN,...
	'bulk in',...
	}; 


Layer2 = {  
	'Hydrogenated tails',...	%Layer Name 
	'Tails thick',...
	'Hydrogenated tails SLD',...
	'Tails roughness',...
	 NaN,...
	'bulk in',...
	}; 


Layer3 = {  
	'Deuterated heads',...	%Layer Name 
	'Head thickness',...
	'Deuterated head SLD',...
	'Head roughness',...
	'Head hydration',...
	'bulk out',...
	}; 


Layer4 = {  
	'Hydrogenated heads',...	%Layer Name 
	'Head thickness',...
	'Hydrogenated head SLD',...
	'Head roughness',...
	'Head hydration',...
	'bulk out',...
	}; 


LayersGroup = {Layer1;	Layer2;	Layer3;	Layer4;	};
problem.addLayerGroup(LayersGroup)

%% Setting of BulkIn Block

problem.setBulkIn(1,'name','Air','min',0,'value',0,'max',0,'fit',false); 


%% Setting of BulkOut Block

problem.setBulkOut(1,'name','D2O','min',6.3e-06,'value',6.35e-06,'max',6.4e-06,'fit',false); 
problem.addBulkOut('ACMW',-5e-07,3.4929e-08,5e-07,false); 

%% Setting of Scalefactors Block

problem.setScalefactor(1,'name','Scalefactor 1','min',0.1,'value',0.23251,'max',0.4,'fit',true); 


%% Setting of Backgrounds Block

problem.setBacksPar(1,'name','Backs parameter 1','min',1e-07,'value',2.8895e-06,'max',7e-06,'fit',true); 
problem.addBacksPar('Backs parameter 2',1e-07,5.1729e-06,7e-06,true); 

