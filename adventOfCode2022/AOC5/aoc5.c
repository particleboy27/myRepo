#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);

    FILE *pfile;
    pfile = fopen("test.txt", "r");
    if(pfile == NULL){
        printf("File does not exist");
    }

    
    const int stack_index_max = 8;
    const int size_stack_max = 10;
    int stack_index = 0;
    char **stack = malloc(stack_index_max*sizeof(char*));                   //array of strings to store essential elements..
    for(stack_index = 0; stack_index <= stack_index_max; stack_index++ ){   //the Letters and the empty spaces
        stack[stack_index] = malloc(size_stack_max*sizeof(char));
    }

    const int o_stack_index_max = 8;
    const int o_size_stack_max = 90;
    int o_stack_element_index;
    char **oriented_stack = malloc(o_stack_index_max*sizeof(char*));            //array of strings to represent the stacks..
    for(stack_index = 0; stack_index <= o_stack_index_max; stack_index++ ){     //from input.txt
        oriented_stack[stack_index] = malloc(o_size_stack_max*sizeof(char));    //a string needs to be 90 char long because..
    }                                                                           //what if i need to put every character..
    for(int u = 0; u < o_stack_index_max; u++){                                 //in a single string
        for(int v = 0; v < o_size_stack_max; v++){
            oriented_stack[u][v] = '\0';                                        //the strings are filled with null '\0'
        }
    }

    /*My function to scan the input.txt for each character ther is*/
    char ch_array[40];
    char floor[10];
    int floor_index = 0;
    char ch;
    int i = 1;
    int index = 0;
    stack_index = 0;
    while(ch != '1'){
        ch = getc(pfile);
        if(ch != '\n'){
            ch_array[index] = ch;                   //ch_array contains chars from a single line
            index++;
        }else{
            while(i < 35){                          //after newline do this..
                floor[floor_index] = ch_array[i];   //pass the line of characters to floor eliminating brackets
                i += 4;
                floor_index++;
            }
            strcpy(stack[stack_index], floor);      //pass the string of essential elements to the char array
            floor_index = 0;                        //the elements have indeces so i can orient them, i hope
            stack_index++;
            index = 0;
            i = 1;
        }

    }
    
    // at this point, all the necessary elements (letters and spaces) are in the stack
    // i need to orient them to another array of string oriented stack

    // for(int k = 0; k<= stack_index_max; k++){
    //     printf("%s\n", stack[k]);
    // }
    for(int i = 0; i < 8; i++){
    printf("%s\n", stack[i]);   // test if my oriented array works
    }

    for(int t = 0; t < 9; t++){
    int r = 7;
    int s = 0;
     while(r != -1){
      oriented_stack[t][s]= stack[r][t];
       r--;
       s++;
      }
      for(int u = s; u <= o_size_stack_max; u++){
      oriented_stack[t][u] = '\0';
      }
    }

    printf("\n");
    for(stack_index = 0; stack_index <= stack_index_max; stack_index++ ){
        free(stack[stack_index]);
    }
    free(stack);

    for(int i = 0; i < 9; i++){
    printf("%s\n", oriented_stack[i]);   // test if my oriented array works
    }

    

    for(stack_index = 0; stack_index <= stack_index_max; stack_index++ ){
        free(oriented_stack[stack_index]);
    }
    free(oriented_stack);


    fclose(pfile);


    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 -
                        start.tv_sec - start.tv_usec / 1e6; // in seconds

    printf("time program took %f seconds to execute\n", time_taken);

}

