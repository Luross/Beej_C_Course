//#include are the most basic preprocessor
#include<stdio.h> //<> are used for system wide includ
//local include use "" :
#include <stdlib.h>
#include "test.c"
#include <math.h>
// -macros
//you can use the preprocessor to define macros
#define HELLO "Hello, world"
#define CRUSH "Sophie"
#define ENOLA_SCORE 1

int main(){

	// -conditional compulation -


	// you can add some conditions that will ignore blocks of codes or not
	#ifdef CRUSH
	printf("hey salut %s, tu vas bien :)?\n", CRUSH );
	#endif

	#ifdef ENOLA
	printf("GAY !!\n");
	// conditional are added or removed at compile time
	//this means the code is deleted if the macro is undefined
	// this can be extremely useful for debugging
	#elif ENOLA_SCORE == 1
	printf("Building some enolaness...\n");
	#else
	printf("Missing the best part of the code...\n");
	#endif

	// you can also undefine macro
	#undef CRUSH

	#ifdef CRUSH
	printf("hey salut %s, tu vas bien :)?\n", CRUSH );
	#endif

	//standard macro have been evoked a few times
	//those are system defined macros:

	printf("This function: %s\n", __func__);
	printf("This file: %s\n", __FILE__);
	printf("This line: %d\n", __LINE__);
	printf("Compiled on: %s %s\n", __DATE__, __TIME__);
	printf("C Version: %ld\n", __STDC_VERSION__);

	// you can add arguments to macro

	#define SQR(x) (x)*(x) //parenthesis added for operation order

	printf("The square root of 12 is %d\n", SQR(12));

	// you can add several arguments
	#define TRIANGLE_AREA(w,h) (0.5*(w)*(h))

	// you can even nest them :
	#define QUADP(a, b, c) ((-(b) + sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
	#define QUADM(a, b, c) ((-(b) - sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
	#define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c) // multiple output !

	printf("2*x^2 + 10*x + 5 = 0\n");

	printf("x = %f or x = %f\n", QUAD(2, 10, 5)); //outputs two floats !

	// any arg can be stringfied by preceding it with #

	#define PRINT_INT_VAL(x) printf("%s = %d\n", #x/*stringified */, x)
	int a = 10;
	PRINT_INT_VAL(a);

	//you can concatenate them by doing ##
	#define CAT(a, b) a ## b
	printf("%d\n", CAT(3,2));

	//- assert macros -
	// assert macros can be used to check is a variable has a certain value
	// here it checks under condition c, and if not met, outputs msg m	
	#define ASSERT(c, m) \
	do { \
	if (!(c)) { \
	fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", \
	__LINE__, #c, m); \
	exit(1); \
	} \
	} while(0)

	int x = 10;

	ASSERT(x<20,"x must be under 20");

	//#error is used to prevent compilation if a cond is not met

	//#warning also work
	#if __STDC_VERSION__ != 201709
	#warning "!!! wrong C version !!!"
	#endif

	//error breaks compilation but I wont include it here to leave my code runnable
	/* there is a whole new section about the #embed directive
	which was added with C23 and allow to get value from external iles
	I honestly doubt I will use it anytime soon so I'll leave it at that */

	//same goes with #pragma, I feel it's just not described enough to be useful
	//good to know it exists though
	return 0;
	}
}