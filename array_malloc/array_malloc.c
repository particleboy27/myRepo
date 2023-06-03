#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int scan_mode(char);
int size_index_comparator(int*, int*);
void sequence_fill(int*, int*);
void local_fill(int*, int*, int*);

void main(){
    int size, index, out_scanmode, n_i, _comparator;                                 
    char mode, array_edit;
    

    printf("please insert size of array!\n");
    scanf("%d", &size);                                 //using scanf my input stream is the number i typed + \n
    
    int *dynamic_array = malloc(size*(sizeof(int)));            //allocate piece of memory for my array
    
    //printf("Here is your array!\n");
    printf("All Elements of the array has now been set to zero\n");

    for(index = 0; index < size; index++){                  //make every element of the array zero
        dynamic_array[index] = 0;
        //printf("[%d]\n", dynamic_array[index]);
    }
    
    printf("Please Choose mode: Fill local or Fill sequence.\n");
    printf("Enter P to access a certain index in the vector.\n");
    printf("Enter S to fill the vector from the start till end.\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF){}                                //flush input stream
    mode = fgetc(stdin);
    out_scanmode = scan_mode(mode);                                              //scan_mode returns an integer 0 or 1 or 3 and store it in out_scanmode

    while(out_scanmode != 1 && out_scanmode != 0){                  //if outscanmode is 1 or 0 go out of the loop
        while((c = getchar()) != '\n' && c != EOF){}                //flush stdin
        mode = fgetc(stdin);                                        //re enter mode in input
        out_scanmode = scan_mode(mode);                             //re evaluate out_scanmode by feeding the new mode
    }

    //printf("outscanmode is %d\n", out_scanmode);

    if(out_scanmode == 0){
        array_edit = 'y';
        
        while(array_edit == 'y'|| array_edit == 'Y'){
            printf("Please Enter the index.\nMax Index: %d\n", size - 1);

            while((c = getchar()) != '\n' && c != EOF){}   
            scanf("%d", &index);

            _comparator = size_index_comparator(&size, &index);

            while(_comparator != 1){
            printf("Please RE-enter the index.\nMax Index: %d\n", size - 1);
            while((c = getchar()) != '\n' && c != EOF){}   
            scanf("%d", &index);
            _comparator = size_index_comparator(&size, &index);
            }

            local_fill(dynamic_array, &index, &size);  
        
            printf("Do you want to insert another Element at a certain index in the array?\n");
            printf("Type Y or N\n");       
        
            while((c = getchar()) != '\n' && c != EOF){}                //flush stdin
            array_edit = fgetc(stdin);
        }

        
    }
    
    if(out_scanmode == 1){
        sequence_fill(dynamic_array, &size);
    }


    free(dynamic_array);
}

int scan_mode(char mode){                                       //function to choose mode to fill the array,
    if(mode != 'p' && mode != 's'){                                  // if mode is is not either p or s, it's invalid, print stuff and return 3
        printf("Invalid Mode. Please Try Again\n");                         
        printf("Please Choose mode: Fill local or Fill sequence.\n");
        printf("Enter P to access a location in the vector.\n");
        printf("Enter S to fill the vector from the start till end.\n");
        return 3;
    }else if(mode == 'p'){                                                  //if mode is 'p' return 0

        return 0;
    }else {                                                  //if mode is 's' return 1
        return 1;
    }

}

int size_index_comparator(int*size, int*index){
    if(*index > *size - 1){
        printf("Invalid Index!\n");
        return 0;
    }else if(*index <= *size -1){
        return 1;
    }
}


void sequence_fill(int*_array, int *size){
    int size_array = *size;
    for(int i = 0; i < size_array; i++){
         printf("Index: %d\n", i);
            int c;
            while(( c = getchar()) != '\n' && c != EOF){}   
            scanf("%d", &_array[i]);
    }

    printf("Done! ");
    printf("Here is your Vector\n");
    for(int i=0; i < size_array; i++){
        printf("[%d]\n", _array[i]);
    }

}

void local_fill(int*_array, int*index, int*size){
    int size_array = *size;
    int i = *index;
    int c;
    char array_edit;

    printf("Please Enter your integer at index %d\n", i);
    while((c = getchar()) != '\n' && c != EOF){}   
    scanf("%d", &_array[i]);
    

    printf("Here is your Array: \n");
    for(i = 0; i < size_array; i++){
        printf("[%d]\n", _array[i]);
    }
}
