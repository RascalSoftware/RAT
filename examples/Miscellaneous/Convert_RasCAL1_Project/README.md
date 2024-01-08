### Converting a RasCAL 1 Project

If you have projects from RasCAL1, there is a simple utility supplied with
the toolbox that makes converting between formats easy.

Suppose the project is called 'myProject.mat'. Simply navigate to the project
ditectory and, at the Matlab prompt, enter..

```
problem = r1ToProjectClass('myProject.mat');

```

..and that's it! The whole R1 project will now be in a projectClass called
'problem', and can be analysed as usual (note that if you want to move it to a
 different directory, remember to copy any custom model codes, and the reveant datafiles also!)

In this folder, a quick demo of the use of this function is provided
in the worksheet 'convertRascal.mlx'.

 
 