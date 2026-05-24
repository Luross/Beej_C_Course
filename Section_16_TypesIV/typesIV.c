#include <stdio.h>



void counter(void);
int main()
{
	extern int ext;
	// -- Type Qualifiers --
	// qualifiers are "extra types" that define a type
	// most common is const for constants

	const int x = 2;
	printf("%d\n", x);

	// const and pointers
	// you can't change the value the pointer points to;

	int y[] = {10, 20};
	const int* p = y;

	p++; // p can't be modified
	// *p = 30 won't work because you trying to modify the content at adress p
	// there is a trick to constantify the pointer itelf though:

	int z = 10;
	int *const const_pointer = &z; //compiles
	// const_pointer ++; woudln't compile !
	// you can also double constantify

	char *const *const ultra_constant; //can't modify the pointer nor the content 

	/* restrict is a optimization qualifier that prevents data to be accessed by any
	other pointer than the one restrict is apply to */

	/* volatile is another opitmization thing that tells the value its pointing to might change
	outside of the code logic like an hardware clock. A volatile variable won't be logged when updated
	this creates a gain useful when working on small hardware like arduino */

	// --Storage class specifiers --
	// specifiers give more infos to the compiler on the type
	// auto is the defualt int a: is equialent to auto int a;
	// auto defines the scope behavior,an auto vatiable will exist within scope and dellaocated
	// when scope is exited

	// -static-

	// static can be use to make function called variable persistants
	// because the count variable in the counter function is static, it's instance will be saved after function exits

	counter();
	counter();
	counter();
	counter();
	// on the file scope, the static keyword will globalize the variable, more later

	// -extern-

	//extern is useful as it allows to refer to variables in other files

	printf("External int : %d\n", ext); // works but the other files needs to be specified in the compiling script
	
	// -register-
	// regitser is an optimization specifier that puts a variable in the register
	// this allows for easier access, and thus optimizes the program for variables that are often used
	// this is mostly done automatically by modern compiler
	// it also prevents you can't access the adress of the register
	// this is because in order to optimize usage, the compiler "depointerizes it", they are not stored in RAM but CPU register !
	// CPu registers are even faster access memory bits !
	// needless to say a beginner coder should NOT use register !


	//-_Thread_local-
	// this is used to say the variable scope will be restricted to the local thread
	// this is used in multithreading optimization, which will be covered in the threads section
	
	return 0;
}

void counter(void)
{
	static int count = 1;
	printf("This has been called %d times\n", count);
	count ++;
}