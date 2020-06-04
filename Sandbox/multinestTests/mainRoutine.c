
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include "multinest.h"
/*#include "mainRoutine.h"*/
#include "LogLike.h"
#include "dumper.h"


int mainRoutine(int argc, char *argv[]);


int mainRoutine(int argc, char *argv[])
{
	int i;
	
	/* set the MultiNest sampling parameters*/
	
	
	int IS = 1;					/* do Nested Importance Sampling? */
	
	int mmodal = 0;					/* do mode separation?*/
	
	int ceff = 0;					/* run in constant efficiency mode?*/
	
	int nlive = 1000;				/* number of live points*/
	
	double efr = 1.0;				/* set the required efficiency */
	
	double tol = 0.1;				/* tol, defines the stopping criteria */
	
	int ndims = 2;					/* dimensionality (no. of free parameters) */
	
	int nPar = 2;					/* total no. of parameters including free & derived parametersm */
	
	int nClsPar = 2;				/* no. of parameters to do mode separation on */
	
	int updInt = 0;				/* after how many iterations feedback is required & the output files should be updated*/
							/* note: posterior files are updated & dumper routine is called after every updInt*10 iterations */
	
	double Ztol = -1E90;				/* all the modes with logZ < Ztol are ignored */
	
	int maxModes = 100;				/* expected max no. of modes (used only for memory allocation) */
	
	int pWrap[ndims];				/* which parameters to have periodic boundary conditions? */
	for(i = 0; i < ndims; i++) pWrap[i] = 0;
	
	char root[130] = "/home/arwel/Documents/RascalDev/RAT/Sandbox/multinestTests/chains/";

	
	int seed = -1;					/* random no. generator seed, if < 0 then take the seed from system clock */
	
	int fb = 0;					/* need feedback on standard output? */
	
	int resume = 0;					/* resume from a previous job? */
	
	int outfile = 0;				/* write output files? */
	
	int initMPI = 0;				/* initialize MPI routines?, relevant only if compiling with MPI*/
							/* set it to F if you want your main program to handle MPI initialization */
	
	double logZero = -DBL_MAX;			/* points with loglike < logZero will be ignored by MultiNest */
	
	int maxiter = 0;				/* max no. of iterations, a non-positive value means infinity. MultiNest will terminate if either it */
							/* has done max no. of iterations or convergence criterion (defined through tol) has been satisfied */
	
	void *context = 0;				/* not required by MultiNest, any additional information user wants to pass */

	


	/* calling MultiNest*/
	
	
	run(IS, mmodal, ceff, nlive, tol, efr, ndims, nPar, nClsPar, maxModes, updInt, Ztol, root, seed, pWrap, fb, resume, outfile, initMPI, 
	logZero, maxiter, LogLike, dumper, context);
}

/***********************************************************************************************************************/
