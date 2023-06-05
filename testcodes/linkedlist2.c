#include <stdio.h>
#include <stdlib.h>

struct node{            //self referential structure
    int data;
    int  data_1;
    struct node* next;
};

void main(){

struct node *head = NULL;               //make a pointer of type node "head"
head = (struct node *)malloc(sizeof(struct node));      //allocate a memory of size struct node...
                                                        // of type struct node in the pointer head
head->data = 45;                                        //access the member data of the node head = 45
head->next = NULL;                                      //access the member next of the node head = null
printf("%d\n", head->data);
free(head);

}