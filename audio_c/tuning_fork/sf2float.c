/* sf2float.c : convert soundfile to floats */
#include <stdio.h>
#include <stdlib.h>
#include <portsf.h>

enum {ARG_PROGNAME, ARG_INFILE, ARG_OUTFILE, ARG_NARGS };

int main(int argc, char** argv)
{
    PSF_PROPS props;
    long framesread, totalread;
    /* init all resource vars to default states */
    int ifd = -1,ofd = -1;
    int error = 0;
    psf_format outformat = PSF_FMT_UNKNOWN;
    PSF_CHPEAK* peaks = NULL:
    float* frame = NULL;
    
    printf("SF2FLOAT: convert soundfile to float formats\n");
    
    if (argc<ARG_NARGS) {
        printf("insufficient arguments.\n"
               "usage:\n\tsf2float infile outfile\n");
        return 1;
    }
    
    /* we need to initialize portsf */
    if (psf_init()) {
        printf("unable to start portsf\n");
        return 1;
    }
    
    ifd = psf_sndOpen(argv[ARG_INFILE],&props,0);
    if (ifd<0) {
        printf("Error: unable to open infile %s\n",
               argv[ARG_INFILE]);
        return 1;
    }
    
    /* we now have a resource, so we use goto hereafter on hitting any errors */
    /* tell the user if source file is already floats */
    if (props.samptype == PSF_SAMP_IEEE_FLOAT) {
        printf("info: infile is already in floats format.\n");
    }
    /* check outfile extension is one we know about */
    outformat = psf_getFormatExt(argv[ARG_OUTFILE]);
    if (outformat == PSF_FMT_UNKNOWN) {
        printf("outfile name %s has unknown format.\n"
                "Use any of .wav, .aiff, .aif, .afc, .aifc\n",
                argv[ARG_OUTFILE]);
        error++;
        goto exit;
    }
}
