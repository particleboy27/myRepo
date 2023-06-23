
#ifndef GRABFILE
#define GRABFILE
#include <stdio.h>
#include <unitypes.h>
FILE* grab_filex(FILE *pfile){
pfile = fopen("test.txt", "r");
if (pfile == NULL){ 
    printf("File does not exist\n");
    }
return pfile;
}

#endif