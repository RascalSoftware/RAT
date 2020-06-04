#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
/*#include "multinest.h"*/

void LogLike(double *Cube, int *ndim, int *npars, double *lnew, void *context);

/* ******************************************* loglikelihood routine ****************************************************/

/* Now an example, sample an egg box likelihood

// Input arguments
// ndim 						= dimensionality (total number of free parameters) of the problem
// npars 						= total number of free plus derived parameters
// context						void pointer, any additional information
//
// Input/Output arguments
// Cube[npars] 						= on entry has the ndim parameters in unit-hypercube
//	 						on exit, the physical parameters plus copy any derived parameters you want to store with the free parameters
//	 
// Output arguments
// lnew 						= loglikelihood */

void LogLike(double *Cube, int *ndim, int *npars, double *lnew, void *context)
{
	double chi = 1.0;
	int i;

	for(i = 0; i < *ndim; i++)
	{
		double x = Cube[i]*10.0*M_PI;
		chi *= cos(x/2.0);
		Cube[i] = x;
	}
	*lnew = powf(chi + 2.0, 5.0);
}

/***********************************************************************************************************************/