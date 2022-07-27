#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>
#include <string.h>


int doInit = 1;
int doSum = 1;
int doOuterLoop = 0;

void handleOpts(int argc, char ***argv) {
  char **args = *argv;
  if (argc == 0 || args[0][0] != '-') return;
  if (strcmp(args[0], "-no-init") == 0) doInit = 0;
  if (strcmp(args[0], "-just-init") == 0) { doInit = 1; doSum = 0; }
  if (strcmp(args[0], "-with-outer-loop") == 0) { doOuterLoop = 1; }
  (*argv)++;
  handleOpts(argc - 1, argv);
}

int main(int argc, char **argv) {
        struct timeval startTime, stopTime;
        double elapsed;
        argv++; argc--;
        handleOpts(argc, &argv);
        printf("doInit: %d, doSum: %d, doOuterLoop: %d\n", doInit, doSum, doOuterLoop);

        long arraySize = atol(argv[0]);
        int stride = atoi(argv[1]);
        int reps = atoi(argv[2]);
        printf("arraySize: %ld, stride: %d\n", arraySize, stride);

        long *a = (long *) malloc (sizeof(long) * arraySize);
        long i, j, k, outloop;

        if (doInit)
        for (i = 0; i < arraySize; i++)
                a[i] = i;


        long long total = 0;
        if (doOuterLoop) outloop = stride; else outloop = 1;

        gettimeofday(&startTime, NULL);
        if (doSum)
        for (k = 0; k < reps; k++)
        for (j = 0; j < outloop; j++)
        for (i = arraySize-1; i >= 0; i-=stride)
                total = total + a[i];
        gettimeofday(&stopTime, NULL);

        //printf("%lld\n", total);
        elapsed = ((stopTime.tv_sec - startTime.tv_sec)*1000000 + (stopTime.tv_usec-startTime.tv_usec));
        printf("%f\n", elapsed);
        return 0;        
}

