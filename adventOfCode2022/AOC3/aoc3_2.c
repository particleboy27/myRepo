#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

char find_common_char(char*, char*, char*);

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
    int ch_count=0;
    int line_count=0;
    int macro_line_count=0;
    int common_ch_value;
    int sum = 0;
    char ch_array1[100];
    char ch_array2[100];
    char ch_array3[100];
    char common_ch;
    for(int i = 0; i <= 100; i++){             //clear packs and line
        ch_array1[i] = '\0';
        ch_array2[i] = '\0';
        ch_array3[i] = '\0';
    }
/* variable declaration: End code*/

/* Scan for every character in the text file: start code*/
    while(i_ch != EOF){
        i_ch = getc(pfile);              //get character from file and store in i_ch

        if(i_ch != '\n'){                
            ch_count++;
            
            if(line_count == 0){
                ch_array1[ch_count-1] = i_ch;
            }else if(line_count == 1){
                ch_array2[ch_count-1] = i_ch;
            }else if(line_count == 2){
                ch_array3[ch_count-1] = i_ch;
            }
        }else{                           //do after getc scans a new line.
            line_count++;
            
            macro_line_count++;
            if(line_count == 3){
                //printf("array 1 is %s\n", ch_array1);
                //printf("array 2 is %s\n", ch_array2);
                //printf("array 3 is %s\n", ch_array3);
                common_ch = find_common_char(ch_array1, ch_array2, ch_array3);
                //printf("the common element is: %c\n\n", common_ch);

                if( common_ch >= 97 && common_ch <= 123){
                common_ch_value = common_ch - 96;
            }else if(common_ch >= 65 && common_ch <= 91){
                common_ch_value = common_ch - 38;
            }
            //printf("value for the common element is: %d\n\n", common_ch_value);
            sum = sum + common_ch_value;
            common_ch_value=0;
                line_count = 0;
                for(int i = 0; i <= 100; i++){             //clear packs and line
                ch_array1[i] = '\0';
                ch_array2[i] = '\0';
                ch_array3[i] = '\0';
            }
            }
            //printf("number of characters: %d\n", ch_count);
            
            ch_count = 0;
            
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

char find_common_char(char* char_array1, char *char_array2, char *char_array3){
    int size = 50;
    int l = 0;
    int m = 0;
    char common_12[size];
    char common_23[size];
    for(int i = 0; i <= size; i++){             //clear packs and line
        common_12[i] = 0;
        common_23[i] = 0;

    }
    for(int i = 0; i < size; i++){                  //compare elements in array 1 and array2
        for(int j = 0; j < size; j++){
            if(char_array1[i] == char_array2[j]){
                common_12[l] = char_array1[i];      //put common in an array common_12
                l++;
            }
            if(char_array2[j] == '\0'){            //if the array arrives at \0, counter = max
                j = size;
            }
            
        }
        if(char_array1[i] == '\0'){
            i = size;
        }
    }
    
    for(int i = 0; i < size; i++){                //compare elements in array 2 and 3
        for(int j = 0; j < size; j++){
            if(char_array2[i] == char_array3[j]){
                common_23[m] = char_array2[i];      //put common in another array common_23
                m++;
            }
            if(char_array3[j] == '\0'){
                j = size;
            }
            
        }
        if(char_array2[i] == '0'){
            i = size;
        }
    }
    
    for(int i = 0; i < size; i++){                  //compare the commons
        for(int j = 0; j < size; j++){
            if(common_12[i] == common_23[j]){       
                return common_12[i];                //return common in the 2 arrays
            }
            
        }
    }
}

