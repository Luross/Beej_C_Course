#include <stdio.h>
#include <stdlib.h>
int my_strlen(char*);
void* my_memcpy(void*, void*, int);
int compar(const void*, const void*);

struct animal {
	char* name;
	int leg_count;
};
int main ()
{
	// -- Pointer arithmetics --
	// - Addition -

	int a[] = {11, 22, 33, 44, 55};
	char test_string[] = "MELODY";
	int* pa = &a[0];
	// Dereferenced pointers can be accessed using + operator :
	printf("%d\n", *(pa)); // prints 11
	printf("%d\n", *(pa+1)); // prints 22
	printf("%d\n", *(pa+2)); // Alicia !

	// You can use this trick to iterate through an array

	for (int i = 0; i < 5; i++)
	{
		*(pa+i) == 33? printf("Sciel, fait gaffe !\n"):printf("%d\n", *(pa+i));
	}

	int b[] = {11, 22, 33, 44, 55, 777};

	int* pb = &b[0];
	// Adding (or subtracting) from a pointer directly also iterates
	while (*pb != 777){
		printf("%d\n", *pb);
		pb++;
	}
	printf("Le string %s fait %d charactères.\n", test_string, my_strlen(test_string));

	// -Array/Pointer equivalence-
	// The fundamental equivalence is a[b] == *(a + b)
	// For iterating an array, various equivalences can be used
	int c[] = {11, 22, 33};
	int* pc = c;

	for (int i = 0; i < 5; i++)
		printf("%d\n", c[i]);
	for (int i = 0; i < 5; i++)
		printf("%d\n", pc[i]);
	for (int i = 0; i < 5; i++)
		printf("%d\n", *(c+i));
	for (int i = 0; i < 5; i++)
		printf("%d\n", *(pc+i));
	for (int i = 0; i < 5; i++)
		printf("%d\n", *(pc++));
	//Those five iterations are doing the exact same thing
	// And because array and pointers are equivalent, functions calls which require a pointer can work with an array and vice versa :
	char* g = "???";

	printf("%d\n", my_strlen(g));

	// - Void Pointers - 

	/* Void* pointers are pointers that do not need to know the type of the variable to operate. Its limitation comes from the fact that you need to know the size of the data type pointed to. It results that you cannot dereference or do pointer arithmectic with it */
	// If you want to dereference a void* you need to first convert it to a known type pointer. From my understanding you can just do it to any known typer pointer because it will give the byte size to the system. Here we use a char* but could be a int* (I THINK)

	char k = 'k';
	void* pk = &k;
	char* q = pk;

	printf("%c\n", *q);
	// printf("%c\n", *pk) would not compile because *pk is still a void*

	char A[1024] = "Alicia";
	char M[1024] = "Maelle";

	printf("Alicia est %s, Maelle est %s.\n", A, M);
	my_memcpy(A, M, 10); // int byte_count doesnt have to be as big as the array size, just big enough to encompass all the indices you want to modify
	printf("Alicia est devenue %s.\n", A); // it works ! bitch !

	struct animal anim[4] = {
		{.name = "Dog", .leg_count=4},
		{.name = "Monkey", .leg_count=2},
		{.name = "Antelope", .leg_count=4},
		{.name = "Snek", .leg_count=0}
	};
	qsort(anim, 4, sizeof(struct animal), compar); // the struct array is sorted !

	for (int i = 0; i < 4; ++i)
	{
		printf("%d : %s\n", anim[i].leg_count, anim[i].name);
	} // Proof !
	return 0;
}

// This is an application of the description of void* Creating a function that copies a variable to another using void*

void* my_memcpy(void* dest, void* src, int byte_count)
{
	char *s = src, *d = dest;
	while (byte_count--){ //note the elegant way to use -- to say "while byte_count > 0, add 1 to *d and *s"
		*d++ = *s++;
	}

	return dest;
}

// Void* can be used to compare any data type, including parameters of structs. This is useful because the function qsort from stdlib require a compar function that compares 2 elements and return 1 or -1 depending of which value is higher :

int compar(const void* elem1, const void* elem2)
{
	const struct animal *animal1 = elem1;
	const struct animal *animal2= elem2;

	if (animal1 -> leg_count > animal2 -> leg_count)
		return 1;
	if (animal1->leg_count < animal2 -> leg_count)
		return -1;
}
// - Substraction -
/* You can substract pointers in order to get the diffrence between them. This can be used to efficiently measure the length of an array. The function below first creates a copy of the first index of a string, then measures the difference between the copy and the index 0 by adding to the copy until the NUL char is reached */
// Important note : this substraction only makes sens if the pointers point to the same array. They have to be copies of each other
int my_strlen(char* s)
{
	char* p = s;

	while(*p != '\0')
		p++;
	return p -s;
} 