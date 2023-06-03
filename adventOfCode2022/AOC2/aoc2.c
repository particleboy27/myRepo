#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);


    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 -
                        start.tv_sec - start.tv_usec / 1e6; // in seconds

    printf("time program took %f seconds to execute\n", time_taken);
    
}