#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdint.h>

int either_range_cointained_in_other(uint32_t a1, uint32_t a2, uint32_t b1, uint32_t b2) {
    return a1 >= b1 && a2 <= b2 || a1 <= b1 && a2 >= b2;
}

int ranges_overlap(uint32_t a1, uint32_t a2, uint32_t b1, uint32_t b2) {
    // First two conditions are fairly self-explanatory: they check if either of the first
    // range's boundaries lie within the second range.
    // This does not, however, include the case when second range is contained within the first,
    // That's why the third condition is neccessary.
    return a1 >= b1 && a1 <= b2 || a2 >= b1 && a2 <= b2 || either_range_cointained_in_other(a1, a2, b1, b2);
}


int main(){
	struct timeval start, end;
    gettimeofday(&start, NULL);

	FILE *pfile = fopen("test.txt", "r");
	if (pfile == NULL){ 
    printf("File does not exist\n");
    }

	uint32_t a1;
    uint32_t a2;
    uint32_t b1;
    uint32_t b2;

    uint32_t contained_ranges = 0;
    uint32_t overlapping_ranges = 0;

    while(fscanf(pfile, "%u-%u,%u-%u", &a1, &a2, &b1, &b2) == 4) {
        contained_ranges += either_range_cointained_in_other(a1, a2, b1, b2);
        overlapping_ranges += ranges_overlap(a1, a2, b1, b2);
    }

    printf("%u\n", contained_ranges);
    printf("%u\n", overlapping_ranges);

    fclose(pfile);
    


	gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 -
                        start.tv_sec - start.tv_usec / 1e6; // in seconds

    printf("time program took %f seconds to execute\n", time_taken);
	return 0;

}
