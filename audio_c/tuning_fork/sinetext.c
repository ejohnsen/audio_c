/* sinetext.c */
/* write sinewave as text */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* conditional compilation - is M_PI defined? */
#ifndef M_PI
#define M_PI (3.141592654)
#endif

/* define our program argument list */
enum {ARG_NAME, ARG_NSAMPS, ARG_FREQ, ARG_SR, ARG_NARGS};

int main(int argc, char** argv)
{
    int i, nsamps;
    double sample, freq, srate;
    double twopi = 2.0 * M_PI;
    double angleincr;
    
    if (argc != ARG_NARGS) {
        fprintf(stderr, "Usage: sinetext nsamps freq srate\n");
        return 1;
    }
    nsamps    = atoi(argv[ARG_NSAMPS]);
    freq      = atof(argv[ARG_FREQ]);
    srate     = atof(argv[ARG_SR]);
    angleincr = twopi * freq / srate;
                  
    for (i=0; i<nsamps;i++) {
        fprintf(stdout,"%.81f\n", sample);                        
    }

    fprintf(stderr,"done\n");
    return 0;
}
