#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// i want to create a vector with n elements
// why define a vector such as: something that has a magnitude and a direction?
//why not define a vector such as a list or an array?
/*
so writing down characteristics of a list, i deduced that in a list of n elements, the elements themselves are not necessarily ordered. however, their indeces should!
the head index which is the index of the first element in the list is index 0 floowing by 1 2... and so forth until index n-1. 
*/

//typedef struct __array{                                          

//}_array_;

/*
void array_insert(int n, int *a);
        //function to make an array of n elements
*/

int scan_mode(char *);
int n_i_comparator(int *, int *);

void main(){

    int size, i, n_i, _array[size], sum = 0, out_scanmode;
    char mode, write_array;
    //char local_fill = 'P';
    //char sequence_fill = 'S';
    printf("you are here to create a vector of n elements!.\n");
    printf("please type the number of elements of your vector!\n");
    scanf("%d", &size);


    printf("you have now generated a vector of %d elements: \n", size);
    for(int i= 0; i <= size; i++){
        printf("[*]\n");
    }


    for(int i = 0; i<= size; i++){                                      //the variable size in memory is in array[size] that's why size = 0; what the fuck
        _array[i] = 0;                                                  // i shall touch the forbidden magic memory allocation
        printf("[%d]\n", _array[i]);
    }
   
    printf("All Elements of the array has now been set to zero\n");
    printf("Please Choose mode: Fill local or Fill sequence.\n");
    printf("Enter P to access a location in the vector.\n");
    printf("Enter S to fill the vector from the start till end.\n");
    scanf(" %c", &mode);
    printf("mode = %c\n", mode);

    if(mode == 'p'){
        printf("Please Enter the index.\n Max index: %d\n", size);             //enter index in array within n range
        scanf(" %d", &i);
        printf("v[%d] is %d\n", i, _array[i]);

        n_i = n_i_comparator(&size, &i);                                       //compare if index does not exceed n range

        if(n_i == 1){                                                       //if i is valid enter an integer in the vector on index i
            printf("Please Enter your integer in index %d\n", i);
            
            scanf("%d", &_array[i]);
            printf("v[%d] is %d\n", i, _array[i]);
            printf("i is = %d, size is = %d\n", i, size);
            printf("end debug\n");
        }

        printf("here is your array\n");

        for(i=0; i<size; i++){                                               //print [array0] \n [array1] \n ... [arrayn]
            printf("[%d]\n", _array[i]);
        }

        printf("would you like to add another Element in the array?\n");
        scanf(" %c", &write_array);

        while(write_array == 'y'){
            printf("Please Enter the index.\n Max index: %d\n", size);
            scanf(" %d", &i);
            n_i = n_i_comparator(&size, &i);
            if(n_i == 1){
                printf("Please Enter your integer in index %d\n Max index = %d\n", i, size);
                scanf(" %d", _array[i]);
            }
            printf("here is your array\n");
            for(i=0; i<size; i++){
                printf("[%d]\n", _array[i]);
            }
            printf("would you like to add another Element in the array?\n");
            printf("Type y to insert element otherwise type n\n");
            scanf(" %c", &write_array);
        }

    }else if(mode == 's'){
        printf("please Enter your integers for the following indeces\n");
        
        for(i=0; i<=size; i++){
            printf("Index: %d\n", i);
            scanf("%d", &_array[i]);
        }
        printf("Done!\n");
        printf("Here is your Vector\n");
        for(int i=0; i < size; i++){
            printf("[%d]\n", _array[i]);
        }
        
    }else {
        printf("invalid mode.\n");
    }

    //out_scanmode = scan_mode(&mode);
    /*
    if(out_scanmode == 0){
        printf("Please Enter the index.\n");
        scanf("%d", i);
        n_i = n_i_comparator(&n, &i);
        if(n_i == 1){
            printf("Please Enter your integer in index %d\n", i);
            scanf("%d", &_array[i]);
        }
    }
    */

    /*
    if(out_scanmode == 1){
        printf("please Enter your integers for the following indeces\n");
        
        for(i=0; i<=n; i++){
            printf("Index: %d\n", i);
            scanf("%d", &_array[i]);
        }
        printf("Done!");
        printf("Here is your Vector");
        for(int i=0; i < n; i++){
            printf("[%d]\n", _array[i]);
        }
    }
    */
    

}



int scan_mode(char *mode){
    if(*mode != ('P'||'S')){
        printf("Invalid Mode. Please Try Again\n");
        printf("Please Choose mode: Fill local or Fill sequence.\n");
        printf("Enter P to access a location in the vector.\n");
        printf("Enter S to fill the vector from the start till end.\n");
    }else if(*mode == 'P'){
        return 0;
    }else{
        return 1;
    }

}

int n_i_comparator(int *n, int*i){
    if(i>n ){
        printf("Invalid Index!\n");
    }else {
        return 1;
    }
}