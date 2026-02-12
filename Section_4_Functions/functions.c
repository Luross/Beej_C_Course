#include <stdio.h>

// if a function prototype is called the function can be defined after main
// this is bad practice though, functions should be in separate files.

int plus_one(int);
int enola_func(void);
// As you know, unless pointers are used, variables are copied when called in function
// Those copied variables are called parameters !

int main(void)
{
	int k = 12;
	k = plus_one(k);
	k = plus_one(k);
	printf("k = %d\n", k);

	//when the function is called though, reindicating void in the arguments will just result in compilation error.

	k = enola_func();

	printf("k = %d\n", k);
	return 0;
}

int plus_one(int n)
{
	return n+1;
}

// It is good practice to indicate void in the parameter if the function takes no argument
//The reasons being that doing that saves the compiler from performing type checks, saving processing time for free.

int enola_func(void)
{
	return 3900;
}
