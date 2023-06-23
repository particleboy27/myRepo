#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int either_range_cointained_in_other(int, int, int, int);
int ranges_overlap(int, int, int, int);

void main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);

	FILE *pfile = fopen("input.txt", "r");
	if (pfile == NULL){ 
    printf("File does not exist\n");
    }
    int a1, a2, b1, b2;
    int contained_ranges = 0;
    int overlapping_ranges = 0;

    while(fscanf(pfile, "%d-%d,%d-%d", &a1, &a2, &b1, &b2) == 4){
        contained_ranges+=either_range_cointained_in_other(a1,a2,b1,b2);
        overlapping_ranges += ranges_overlap(a1, a2, b1, b2);
    }
    printf("%d\n", contained_ranges);
    printf("%d\n", overlapping_ranges);


    fclose(pfile);
    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 -
                        start.tv_sec - start.tv_usec / 1e6; // in seconds

    printf("time program took %f seconds to execute\n", time_taken);
	

}

int either_range_cointained_in_other(int a1, int a2, int b1, int b2) {
    return a1 >= b1 && a2 <= b2 || a1 <= b1 && a2 >= b2;        
}

int ranges_overlap(int a1, int a2, int b1, int b2) {
    // First two conditions are fairly self-explanatory: they check if either of the first
    // range's boundaries lie within the second range.
    // This does not, however, include the case when second range is contained within the first,
    // That's why the third condition is neccessary.
    return a1 >= b1 && a1 <= b2 || a2 >= b1 && a2 <= b2 || either_range_cointained_in_other(a1, a2, b1, b2);
}