
#define NESTRUN __nested_MOD_nestrun

/***************************************** C Interface to MultiNest **************************************************/

extern void NESTRUN(int *, int *, int *, int *, double *, double *, int *, int *, int *, int *, int *, double *, 
char *, int *, int *, int *, int *, int *, int *, double *, int *, void (*Loglike)(double *, int *, int *, 
double *, void *), void (*dumper)(int *, int *, int *, double **, double **, double **, double *, 
double *, double *, double *, void *), void *context);

void run(int IS, int mmodal, int ceff, int nlive, double tol, double efr, int ndims, int nPar, int nClsPar, 
int maxModes, int updInt, double Ztol, char root[], int seed, int *pWrap, int fb, int resume, int outfile, 
int initMPI, double logZero, int maxiter, void (*LogLike)(double *, int *, int *, double *, void *), 
void (*dumper)(int *, int *, int *, double **, double **, double **, double *, double *, double *, double *, void *), 
void *context)
{
	int i;
	for (i = strlen(root); i < 100; i++) root[i] = ' ';

        NESTRUN(&IS, &mmodal, &ceff, &nlive, &tol, &efr, &ndims, &nPar, &nClsPar, &maxModes, &updInt, &Ztol,
        root, &seed, pWrap, &fb, &resume, &outfile, &initMPI, &logZero, &maxiter, LogLike, dumper, context);
}


