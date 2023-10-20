imax = 100;
prog = 0;
fprintf(1,'Computation Progress: %3d%%\n',prog);
for k = 1:1:imax
	prog = ( 100*(k/imax) );
	fprintf(1,'\b\b\b\b%3.0f%%',prog);  % Deleting 4 characters (The three digits and the % symbol)
    pause(0.1)
    drawnow
end
fprintf('\n');