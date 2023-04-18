#include <stdio.h> /*include library header standard input ouput library header that is included in compiler*/

int main(){
	//understanding literals in c
	//Integers Floating point Characters Strings
	/*integers example 1 2 3 4*/
	/*floutingpoint ex. 3.1415 or 2.56e-5*/
	/*characters are a, @, \n ' ' (space)*/
	/*strings are "Kippikayay", "hello!\n"*/

	char h[]= "Hexidecimal"; //h is a character array so it's a string
	printf("Integers that starts with 0x are %s\n", h); //instead of %c, i use %s because h is a string, i was corrected by gcc lol
	printf("and it includes the digits 0 to 9 and A-F(or a-f)\n"); //additional text description
	
	printf("enter binary integer literals\n");
	char b[]= "Binary"; //b is another character array thus it's a string
	printf("%s integer literals must begin with 0b (or 0B)\n",b);
	printf("obviously it exclusively include digits 0 and 1\n");
	
	char i[]= "integers";
	char f[]= "Floating Point";
	printf("%s is like %s, but decimal point is allowed\n", f, i);
	printf("and its notation is ke +-n where n specifies the exponent\n");

	//qualifiers section
	
	printf("U or u is used for unsigned literals\n");
	printf("L or l is used for long literans instead\n");
	printf("and F or f is used for float\n");


	
	return 0;
}

