#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    char *copy = malloc(1024*sizeof(char));
    int len = strlen(s);
    int i = 0;
    for(i=0;i <len ;i++) {
        copy[i]=s[i];  //copy characters               
    }
    copy[i] = '\0'; 
    //printf("%s", copy);
    i = 0;
    while(copy[i] != '\0'){
        if(copy[i] != ' '){
            printf("%c", copy[i]);
        }else if(copy[i] == ' '){
            printf("\n");
        }
        i++;
    }
    
    //Write your logic to print the tokens of the sentence here.
    return 0;
}