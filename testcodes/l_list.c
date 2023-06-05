#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


struct node{            //self referential structure
    int data;
    struct node* next;
};

struct node* build_linked_list(int);
int Length(struct node*);

void main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int n_nodes ;
    int mylength;

    printf("Enter the number of your nodes:");
    scanf("%d", &n_nodes);
    struct node* my_linked_list = build_linked_list(n_nodes);

    mylength = Length(my_linked_list);

    printf("there are %d nodes in your linked list\n", mylength);

    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 -
                        start.tv_sec - start.tv_usec / 1e6; // in seconds

    printf("time program took %f seconds to execute\n", time_taken);
 

}

int Length(struct node* head){
    struct node* current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

struct node* build_linked_list(int list_size){
    int size = list_size;
    struct node* node[size];
    for(int i = 0; i < size; i++){
        node[i] = NULL;
    }
    
    for(int i = 0; i < size; i++){
        node[i] = malloc(sizeof(struct node));
    }

    for(int i = 0; i < size; i++){
        if(i < (size-1)){
            node[i]->next = node[i+1];
        }else {
            node[i]->next = NULL;
        }
    }
    return node[0];
}
