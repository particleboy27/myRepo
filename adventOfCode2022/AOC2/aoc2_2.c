#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int score_round(char);
char round_to_input(char, char);
int score_input(char);

void main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);

    char i_ch;
    long input_point=0;
    long round_point=0;
    long match_point = 0;
    long total_points = 0;
    char elf_input;
    char my_input;


    FILE * pfile;
    pfile = fopen("input.txt", "r");
    if (pfile == NULL){ 
    printf("File does not exist\n");
    }
    
    while(i_ch != EOF){
        i_ch = getc(pfile);
        if(i_ch != '\n'){                               //if not newline..
            if(i_ch == 'A'||i_ch == 'B'||i_ch == 'C'){
                elf_input = i_ch;
            }else if(i_ch == 'X'|| i_ch == 'Y'|| i_ch == 'Z'){              
                round_point = score_round(i_ch);
                my_input = round_to_input(elf_input, i_ch);
                input_point = score_input(my_input);
            }
        }else{
            
            match_point = round_point + input_point;
            total_points = total_points + match_point;
            
        }
        
    } 
    
    printf("my total points is %d\n", total_points);

    fclose(pfile);

    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 -
                        start.tv_sec - start.tv_usec / 1e6; // in seconds

    printf("time program took %f seconds to execute\n", time_taken);
    
}

char round_to_input(char elf_input, char match){
    if(elf_input == 'A' && match == 'X'){
        return 'Z';
    }else if(elf_input == 'A' && match == 'Y'){
        return 'X';
    }else if(elf_input == 'A' && match == 'Z'){
        return 'Y';
    }else if(elf_input == 'B' && match == 'X'){
        return 'X';
    }else if(elf_input == 'B' && match == 'Y'){
        return 'Y';
    }else if(elf_input == 'B' && match == 'Z'){
        return 'Z';
    }else if(elf_input == 'C' && match == 'X'){
        return 'Y';
    }else if(elf_input == 'C' && match == 'Y'){
        return 'Z';
    }else if(elf_input == 'C' && match == 'Z'){
        return 'X';
    }else{
        printf("invalid match\n");
    }
}

int score_input(char input){
    if(input == 'X'){
        return 1;
    }else if(input == 'Y'){
        return 2;
    }else if(input== 'Z'){
        return 3;
    }
}


int score_round(char input){
    if(input == 'X'){
        return 0;
    }else if(input == 'Y'){
        return 3;
    }else if(input =='Z'){
        return 6;
    }else{
        printf("Invalid input!\n");
    }
}