#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;
    float x;
    float y;
    
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a+b, a-b);
    scanf("%f %f", &x, &y);
    printf("%0.1f %0.1f\n", x+y, x-y);
    return 0;
}