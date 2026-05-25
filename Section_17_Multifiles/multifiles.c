#include <stdio.h>

//functions from other files can be included by declaring the protoype in the main file
// but you usually use a header file:

#include "functions.h" // contains the prototypes we need

// while you can add the c files containing the functions in the execution line
// you can also simply add #include "functions.c" in the header

#include "functions.c" // or in the main file !
int main()
{
	printf("%d\n", add(2,3));
	return 0;
}