#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
//malloc an n by m array

const int max_stack = 5;
const int max_char = 30;
char **stack = malloc(max_stack*sizeof(char*)); //5 strings
    for(int i = 0; i < max_stack; i++){
        stack[i] = malloc(max_char*sizeof(char));
    }

char shit[10] = "BULLSHIT";
strcpy(stack[1], shit);
printf("\n%s\n", stack[1]);

for(int i = 0; i < max_stack; i++){
        free(stack[i]);
    }
free(stack);


}
