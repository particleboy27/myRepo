#include <stdio.h>

short x = 5;
int y;

void main(void){
	//type conversions
	y = x * 2L;
	printf("x multiplied by 2(long) is %i\n", y);
	y = x/4;
	printf("5(short) divided by 4 is %i\n", y);
	y = x/4.0; 
	printf("5(short) divided by 4(float) is %i\n",y);

	//right way
	//declare the result first
	
	float f;
	f = x/4.0;
	printf("this should be the correct answer: %f\n", f);
		
		

}
