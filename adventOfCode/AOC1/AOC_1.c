#include <stdio.h>
#include <stdlib.h>

void main(){
    
    FILE * pfile;
    pfile = fopen("code_input.txt", "r");
    int size = 300;
    int num_ch = 0;
    char i_ch;
    char ch[20];
    int index_ch = 0;
    int index_elf = 0;
    int count_elf = 0;
    int tot_callories;
    int max_callories = INT_MIN;
    int second_max = INT_MIN;
    int third_max = INT_MIN;
    int elf1, elf2, elf3;
    
    if (pfile == NULL){ 
    printf("File does not exist\n");
    }

    int *callories_elf_list = malloc(size*(sizeof(int)));
    for(int j = 0; j > size; j++){
        callories_elf_list[j] = 0;
    }
    
    //fgets(ch, 20, pfile);
    //printf(ch);
    //printf("\n%d", num_ch);

    index_ch = 0;
    count_elf = 0;
    tot_callories = 0;

    do{
        i_ch = getc(pfile);                             //scan each letter

        if(i_ch != '\n'){                               //if not newline..
            ch[index_ch] = i_ch;                        //put letter on an array
            index_ch++;                                 //next index for the array


        }else if(i_ch == '\n' || i_ch == EOF) {                                         //if encounter a newline
            num_ch = atoi(ch);                          //convert character array to int
            if(num_ch != 0){   
                tot_callories = tot_callories + num_ch;                        
                //printf("%d", num_ch);
                //printf(" - %d\n", tot_callories);
            }else {
                count_elf++;
                //printf("%dth elf\n", count_elf);
                callories_elf_list[index_elf] = tot_callories;
                tot_callories = 0;
                index_elf++;
            }
            for(int i = 0; i <20; i++){
                ch[i]=0;
            }
            index_ch = 0;
            
        }
    } while(i_ch != EOF);

    count_elf++;
    //printf("%dth elf\n", count_elf);
    callories_elf_list[index_elf] = tot_callories;
    fclose(pfile);
    printf("total number of elves: %d\n", count_elf);

    
    //for(int s = 0; s < count_elf; s++){
    //   printf("%dth elf carries %d Callories\n", (s+1), callories_elf_list[s]);
    //}
    
    for (int t = 0; t < count_elf; t++) {
        if (callories_elf_list[t] > max_callories) {
            third_max = second_max; 
            second_max = max_callories; 
            max_callories = callories_elf_list[t];
            elf1 = t+1;
        }else if (callories_elf_list[t] > second_max){
            third_max = second_max; 
            second_max = callories_elf_list[t];
            elf2 = t+1;
        }else if(callories_elf_list[t] > third_max) {
            third_max = callories_elf_list[t];
            elf3 = t+1;
        }
        
    }
     
    printf("Elf no. %d is the most gigachad of them all and he carries %d callories\n", elf1, max_callories);
    printf("Elf no. %d is the second gigachad of them all and he carries %d callories\n", elf2, second_max);
    printf("Elf no. %d is the third gigachad of them all and he carries %d callories\n", elf3, third_max);
    int tot_cal = max_callories + second_max + third_max;
    printf("The three gigachads carries %d callories together\n", tot_cal);

    free(callories_elf_list);

}