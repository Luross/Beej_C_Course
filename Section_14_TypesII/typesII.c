#include<stdio.h>
#include<limits.h>
#include<float.h>

int main ()
{
	// -- Types II -- 

	// - intger types -
	// integers can be signed or unsigned
	// by default ints are signed thus those three are equivalent:
	int a;
	signed int ab;
	signed ac;

	unsigned int b;
	unsigned c;

	// types long and short are used to have bigger ints. Int type by default is short (65536 values)

	short s; // same as int s

	// Longs have 4,3 billions values

	long l; // same as long int l;

	// If you need 8 times more data, just add another long

	long long ll; // same as long long int ll;

	//And of course you can sign/usign

	unsigned long long ull; // same as unsigned long long int ull;

	// - char types -

	// chars are actually ints
	char ca = 'B';
	printf("%c\n", ca); // -> B
	printf("%d\n", ca); // -> 66

	// this means you can add or substract them

	char cb = 10, cc = 20, cd = 'K';
	printf("%d\n", cb + cc); // prints "30"
	// Each character also has a numeric value thus you can also add or subtract letters
	// Usually the value table for char is unicode but nothing prevents using a custom one !
	printf("Value of char %c is %d.\n", cd, cd);
	printf("%d\n", cb + cc + cd); // 30 + 75 = 105
 	
 	// - float types - 
	// float, double and long double can be used to store floats
	float f = 1.234567891 ; // 4 bytes
	double df; // 8 bytes
	long double ldf; // 16 bytes

	//The library float.h contains macros that will tell you how many digits can be stored in each type for your system, since it's not obvious how many digits a 16 bytes variable my hold :

	printf("You can store %d digits for float types\n", FLT_DIG);
	printf("You can store %d digits for double types\n", DBL_DIG);
	printf("You can store %d digits for long double types\n", LDBL_DIG);

	printf("%.5f\n", f); // works !
	printf("%.15f\n", f); // doesn't, significant digits exceeded ! random numbers are printed

	// -constants types -

	int hex_a = 0x1A2B; // if you lead a number with 0x it reads as hexadecimal
	int hex_b = 0x1a2b; // not case sensitive
	
	printf("%x\n", hex_a); // printed with %x
	int oct_a = 012; //if you start a number with 0 it reads as an octal
	printf("%o\n", oct_a); // printed with %o
 	printf("%d\n", FLT_RADIX);

 	// you can force an integer to be a certain type by using a suffix

 	int z = 1234L; // z becomes a Long Int (L), constant
 	//other suffixes include LL, UL, ULL etc.

 	float zz = 1.25L; // for float they have their own suffixes. L is for Long Double. By default, floats are double type ! Floats are suffixed by F !

	double scientific_int = 35668488000;

 	printf("%e\n", scientific_int); //you can display scientific notation with %e, but beware, it needs to be a float not an int !


 	printf("%d\n", z);
	return 0;
}