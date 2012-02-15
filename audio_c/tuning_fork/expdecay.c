/* expdecay.c */
/* implements formula x[t] = a* exp(-k/T) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char**argv)
{
    int i, nsteps;
    double step, x, a, T, k;
    double dur;
    
    dur = atof(argv[1]);
    T = atof(argv[2]);
    nsteps = atoi(argv[3]);
    
    k = dur/nsteps; // the constant time increment
    a = exp(-k/T);  // calculate the constant ratio value
    x = 1.0;        // starting value for the decay
    
    step = 0.0;
    for (i=0; i<nsteps; i++) {
        printf("%.41f\t%.81f\n", step, x);
        x = a * x;
        step += k;
    }
    return 0;
}