#include <stdio.h>
#include <stdlib.h>


int size_r;
int size_c;
struct two_coordinate{
    int x;
    int y;
};

void print_dot_matrix(int *, int *);           //print dot matrix funtion
struct two_coordinate generate_fruit(int *, int *);             //select a[i,j] random position for the fruit 


///////////////////////////////////////////////////


void main(void) {

printf("Select number of Rows: \n");
scanf("%d", &size_r);
size_r;

printf("Select number of Columns: \n");
scanf("%d", &size_c);
size_c;

printf("You have now created a %dx%d matrix\n", size_r, size_c);


print_dot_matrix(&size_r, &size_c);
int row[size_r];                                //make an array of size_r
int column[size_c];                             //make an array of size_c

struct two_coordinate my_fruit = generate_fruit(&size_r, &size_c);

printf("fruit coordinate is: %d, %d \n", my_fruit.x, my_fruit.y);
/*
size_t a = sizeof(row)/sizeof(int);
size_t b = sizeof(column)/sizeof(int);
printf("size of row is: %d\n", a);
printf("size of column is: %d\n", b);
*/



}

void print_dot_matrix(int *rows, int *columns){
    int s_r = *rows;
    int s_c = *columns;
    for(int i = 0; i <= s_r; i++){
        for(int j = 0; j <= s_c; j++){
            printf("*  ");    
        }
        printf("\n");
    }
}

struct two_coordinate generate_fruit(int *rows, int *columns){
    struct two_coordinate fruit;
    fruit.x = rand() % (*rows + 1);
    fruit.y = rand() % (*columns + 1);

    return fruit;

}