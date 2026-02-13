#include <stdio.h>

void increment(int* p)
{
	*p=*p+1;
}

int main (void)
{
	int i = 10;
	int* p; // htis is a point to an int
	

	p = &i; // p is now assigned the address of i

	/* note that int* p and int *p are exactly the same. I prefer int* p to 
	avoid confusion with dereferencing. It makes more sens that way. But 
	remember that this is incorrect from a computer perspective, the data 
	type remains int ! It can be confusing if declaring multiple pointers 
	in a single line eg: */

	int a, b, c, *d, *e, f, *g;

	/* Thus we created 4 interger variables (a, b, c, f) and 3 pointers
	to an integer variable (d, e and g). Writting int* would NOT make
	all the declared variables pointers, only the first one. I'll still
	stick to int* for now when declaring a single pointer. */

	printf("The value of p is %p\n", p);

	// And you can address the value stored at address p with * !
	// Thus those two expression are the same :

	printf("The value of i is %d\n", *p);
	printf("The value of i is %d\n", i);

	/* this usage of the asterix to access the value of a variable is called 
	"dereferencing", basically "depointering" the pointer value to give the 
	variable stored there. It causes confusing because it uses the same 
	asterix as the pointer while basically doing the exact opposite... */

	// & is the "adress-of operator"
	/* (void*) is a cast which prevents the compiler to throw a warning 
	(more on that later) */

	printf("And its address is %p\n", (void*)&i);


	// As you know, pointer can be used to modify a variable with functions

	printf("i is equal to %d\n",i);
	increment(p);
	increment(&i);
	printf("i has been incremented twice and is now equal to %d\n", i);

	//This is a null pointer
	int* q = NULL;
	//Using dereferencing on a null point will cause a crash don't do it
	/* *q = 12 <-- don't do that !! */
	// But as you know, it will happen a lot accidentally.

	// Also remember size of pointer and of int differ:

	printf("The size of pointer p is %zu bytes.\n", sizeof(p));
	printf("The size of an int is %zu bytes. \n", sizeof(int));

	//Addressed are big number, makes sens they take more bytes to be stored!

	return 0;
}