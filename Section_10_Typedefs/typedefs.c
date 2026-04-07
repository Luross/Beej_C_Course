#include <stdio.h>

int main()
{

	// -- Typedefs aliaseses --
	// You can create aliases for simple types using typedef
	typedef int antelope;
	// From this line onward you can create new ints with the antelope type
	// A single typedef can contain more than one alias
	antelope x =10;
	typedef int bagel, mushroom;
	
	bagel y = 15;
	mushroom z = 30;


	printf("%d, %d, %d \n",x, y, z);

	// -- Useful Typedefs --
	// This has limited utility however. Lets see the more usfull stuff
	// You can create typedef for structs

	struct animal {
		char* name;
		int number_of_games_played;
	};

	// with this def, we can use the animal struct with only "animal" instead of "struct animal"
	typedef struct animal animal;

	// both are equivalent :
	struct animal k;
	animal v;

	// You can mash it together in one single block :

	typedef struct planet {
		char* name;
		int size;
	} planet; // alias defined here

	// Better even, you can create an anonymous struct and name it aftewards

	typedef struct { // struct not names initially
		char* name;
		int x, y;
	} point; // named after its definition


	point p = {.x=20, .y=40};

	printf("%d, %d\n", p.x, p.y);

	/* Creating aliases also have utility. For example if you
	defined a type for float at the beginning of code, then
	you can change the type of all your custom float to another 
	type by just changing the typedef instead of all its
	instances */

	typedef float my_float; // change float to double

	my_float f1, f2, f3; // and those three all become doubles

	/* Typedef can be used for arrays and pointers but Beej recommends
	against it because it obfuscate the fact that you are dealing with an array
	or a pointer */
	return 0;
}