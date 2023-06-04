#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int score_round(char, char);
int score_input(char);

void main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);

    char i_ch;
    int input_point = 0;
    int round_point = 0;
    int match_point = 0;
    int total_points = 0;
    char elf_input;
    char my_input;


    FILE * pfile;
    pfile = fopen("input.txt", "r");
    if (pfile == NULL){ 
    printf("File does not exist\n");
    }
    
     while(i_ch != EOF){
        i_ch = getc(pfile);
        if(i_ch != '\n'){                               
 
            
            if(i_ch == 'A'||i_ch == 'B'||i_ch == 'C'){
                elf_input = i_ch;
            }else if(i_ch == 'X'||i_ch == 'Y'||i_ch == 'Z'){
                my_input = i_ch;
                input_point = score_input(i_ch);
            }
            
        }else{
            round_point = score_round(elf_input, my_input);
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

int score_round(char elf_input, char my_input){
    if(elf_input == 'A' && my_input == 'X'){
        return 3;
    }else if(elf_input == 'B' && my_input == 'Y'){
        return 3;
    }else if(elf_input == 'C' && my_input == 'Z'){
        return 3;
    }else if(elf_input == 'A' && my_input == 'Z'){
        return 0;
    }else if(elf_input == 'B' && my_input == 'X'){
        return 0;
    }else if(elf_input == 'C' && my_input == 'Y'){
        return 0;
    }else if(elf_input == 'A' && my_input == 'Y'){
        return 6;
    }else if(elf_input == 'B' && my_input == 'Z'){
        return 6;
    }else if(elf_input == 'C' && my_input == 'X'){
        return 6;
    }else{
        printf("Invalid Round\n");
    }
}

int score_input(char input){
    if(input == 'X'){
        return 1;
    }else if(input == 'Y'){
        return 2;
    }else if(input =='Z'){
        return 3;
    }else{
        printf("Invalid input!\n");
    }
}