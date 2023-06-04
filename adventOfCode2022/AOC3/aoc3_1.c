#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

char find_common_char(char*, char*);

void main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);
/**********Code start******************/

/* OPEN FILE INPUT: Start code*/

    FILE * pfile;
    pfile = fopen("input.txt", "r");
    if (pfile == NULL){ 
    printf("File does not exist\n");
    }

/* OPEN FILE INPUT: End code*/

/* Variable declaration: Start code*/

    char i_ch;                      //individual char variable
    int ch_count = 0;
    int nth_line = 0;
    int index = 0;
    int size = 100;
    int half_pack = 0;
    char common_ch;
    int common_ch_value;
    int sum = 0;

    char line[size];
    char pack_1[100];
    char pack_2[100];
    for(int i = 0; i <= size; i++){
        line[i] = '\0';
        pack_1[i] = '\0';
        pack_2[i] = '\0';
    }
    
/* variable declaration: End code*/

/* Scan for every character in the text file: start code*/

    while(i_ch != EOF){
        i_ch = getc(pfile);              //get character from file and store in i_ch

        if(i_ch != '\n'){                
            ch_count++;
            line[index] = i_ch;
            index++;
        }else{                           //do after getc scans a new line.
            nth_line++;                           
            half_pack = ch_count/2;

            for(int i = 0; i < half_pack; i++){
                pack_1[i] = line[i];
            }

            for(int i = half_pack; i < ch_count; i++){
                pack_2[i-half_pack] = line[i];
            }

            common_ch = find_common_char(pack_1, pack_2);
            
            if( common_ch >= 97 && common_ch <= 123){
                common_ch_value = common_ch - 96;
            }else if(common_ch >= 65 && common_ch <= 91){
                common_ch_value = common_ch - 38;
            }
            sum = sum + common_ch_value;
            common_ch_value=0;
            ch_count = 0;
            index = 0;

            for(int i = 0; i <= size; i++){             //clear packs and line
                pack_1[i] = '\0';
                pack_2[i] = '\0';
                line[i] = '\0';
            }
            

        }
        
    }

/* Scan for every character in the text file: end code*/

printf("sum is %d\n", sum);

    fclose(pfile);

/**********Code end******************/
    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 -
                        start.tv_sec - start.tv_usec / 1e6; // in seconds

    printf("time program took %f seconds to execute\n", time_taken);
    
}

char find_common_char(char* char_array1, char *char_array2){
    int size = 50;
    int i = 0;
    int j = 0;
    
    for(i = 0; i < size; i++){
        
            for(j= 0; j < size; j++){
                if(char_array1[i] == char_array2[j]){
                    return char_array1[i];
            
                }
            }
        
    }

}