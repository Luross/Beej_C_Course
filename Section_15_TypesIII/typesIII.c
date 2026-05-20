#include <stdio.h>
#include <stdlib.h>

int compar(const void*,const void*);

int main()
{
	// -String conversions-
	char s[10];
	float f = 3.14159;
	snprintf(s, 10, "%f", f); // this funciton converts values into string
	printf("String value : %s\n", s); //see can be used as string with %s 
	// atoi are function from <stdlib.h> that convert string to other types
	// atoi converts string to int
	char* pi = "3.14159";
	float fpi;
	fpi = atof(pi); //atof converts string to float
	printf("%f\n", fpi);

	// atoi are convenient because they only take one arguments but handle errors poorly
	//if you use atoi with a character string, you'll crash
	// for better error handling we use strtol functions (strtof, strtod etc)

	char* str = "3490";
	unsigned long int x = strtoul(str, NULL, 10); // arg 3 is the base !
	printf("%lu\n", x); //3490

	char* str_bin = "101010";
	unsigned long int x_bin = strtoul(str_bin, NULL, 2); // se you can use binary
	printf("%lu\n", x_bin);// prints 42 !

	//but what does arg 2 does ? It's the error output, in case the conversion can't be done
	// let's try with an unconvertable string
	char* str_bad = "30X";
	char* badchar;

	unsigned long int x_bad = strtoul(str_bad, &badchar, 10); //dumps the bad char in the badchar variable
	printf("bad char : %lu\n", x_bad); //will print 30
	printf("Invalid char : %c\n", *badchar); // will print X

	//if badchar == "\0", then its a success. You can use it for if conditional

	// -char conversion-

	// chars are int using the UTF table, I think i know that by now. 
	// they can be used for math yadiyadi yada

	// --Implicit conversions--

	// if you use char characters into a int, the char gets promoted to an int
	char k = 10, kk = 20;
	int i = k + kk; //k and kk are now ints

	// -Explicit conversion and casting-
	// you can change any expression by putting new type in parenthesis in front
	// you saw it before, it's called casting. Usually done with pointer but can be done with any type

	int cast_x = 10;
	long int cast_y = (long int)cast_x + 12; //cast_x became a long int


	return 0;
}

int compar(const void* elem1, const void* elem2)
{ //for example here we use explicit conversion to convert void* to int*
	if (*((const int*)elem2) > *((const int*)elem1)) return 1;
	if (*((const int*)elem2) < *((const int*)elem1)) return -1;
	return 0;
}