//creating a linked list and learning more about comnbination of structs and pointers
//copied from the internet for reference

#include <stdio.h>
#include <stdlib.h>
#define PRODUCT_NAME_LEN 64

typedef struct data_structure{
        int product_code;
        char product_name[PRODUCT_NAME_LEN];
        int product_cost;
    }data_struct;

typedef struct list{
        struct list *head;      //variable that stores an address called head
        struct list *tail;      
        struct list *next;
        struct list *current_node;
        data_struct *data;
    }list_t;

void add(list_t *list, int code, char name[], int cost); 

void main(){
    list_t *list = NULL;
    list = initialize(list);
    add(list, 1001, "Dell Inspiron 2.66", 1299);

    add(list, 1002, "Macbook Pro 2.66", 1499);

    clean_up(list);

    getchar();

    return 0;
}



void add(list_t *list, int code, char name[], int cost){
    /* Allocate memory for the new product */
    data_struct *product = (data_struct*) calloc(1, sizeof(*product));
    if(!product){
        fprintf(stderr, "Cannot allocate memory.");
        exit(1);
    }

    /* This is the first item in the list */
    product->product_code = code;
    product->product_cost = cost;
    strncpy(product->product_name, name, sizeof(product->product_name));
    product->product_name[PRODUCT_NAME_LEN - 1] = '\0';

    if(!list->head)
    {
        /* Assign the address of the product. */
        list = (list_t*) product;   
        /* Set the head and tail to this product */
        list->head = (list_t*) product;
        list->tail = (list_t*) product;
    }
    else
    {
        /* Append to the tail of the list. */
        list->tail->next = (list_t*) product;
        list->tail = (list_t*) product;
    }

    /* Assign the address of the product to the data on the list. */
    list->data = (list_t*) product;
}