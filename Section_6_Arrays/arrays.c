#include <stdio.h>
#define COUNT 5

void times2(int*, int );
void times3(int* , int );
void times4(int* , int);
void double_array(int*, int);
void print_2D_array(int[][3]); // Prototype of a 2d array function needs the dimensions of the array except the first one

int main(void)

{
	int i;

	// arrays can be initalized blank
	float f[3];
	// and defined later
	f[0] = 0.54;
	f[1] = 1.57;
	f[2] = 2.54;

	//But they can also be initalized immeditaly

	int a[5] = {25, 23, 22, 13, 15};

	/*The code will not compule if you have more elements than the array size
	but it will if you have fewer items, with the remainder items being initalized as 0s
	This way you can initialize an full array of 0 like that :*/

	int zero[100] = {0}; // An array of a hundred 0s !

	// you can also skip index during initialization

	int b[7] = {12, 25, [4] = 40, 70}; // initalizes {12, 25, 0, 40, 70, 0, 0}

	// Constants can be taped into as well

	int c[COUNT] =  {[COUNT - 2]=3, 2}; // {0, 0, 0, 3, 2}

	// if size is left blank the array will have the size of the initializer

	int d[] = {2, 3, 4}; // size of array d is 3

	for (i = 0; i<3; i++){
		printf("%f\n", f[i]);
	}

	// C doestn stop you from printing arrays out of bounds, beware !

	printf("OOB array :\n");
	for (i = 0; i<10; i++){
		printf("%d\n", a[i]);
	}
	/* tip : you can get the length of an array by dividing its sizeof by 
	size of is data type */
	printf("Array f is of size %zu.\n", sizeof f/sizeof(float));

	/* This will not work however if the array is passed to a function
	because it only passes a pointer to the first element of the array */

	// Multi dimensional arrays

	int ab[2][5] = {
		// Initialize a 2D array
		{0, 1, 2, 3, 4},
		{5, 6, 7, 8, 9}
		};
	int row, col;
	for (row = 0; row < 2; row++) {
	for (col = 0; col < 5; col++) {
	printf("(%d,%d) = %d\n", row, col, ab[row][col]);
	}
	}

	//Pointers to array
	int* p;

	// the name of the array refers to a pointer to its first index thus those are the same:
	p = &a[0];
	p=a;

	return 0;
}

//Passing array to a function requires a pointer
//So both notations are possible :

void times2(int* a, int len)
{
	for (int i = 0; i< len; i++)
		printf("%d\n", a[i]*2);
}

void times3(int a[], int len)
{
	for (int i = 0; i< len; i++)
		printf("%d\n", a[i]*3);
}

void times4(int a[5], int len)
{
	for (int i = 0; i< len; i++)
		printf("%d\n", a[i]*4);
}

// the notation int* a is the most common

// array can be modified via pointer in a function
void double_array(int* a, int len)
{
	for (int i = 0; i<len; i++)
		a[i] *=2; //modifies number of a at index i
}

// !! for multidimentionsal array, C needs to know the dimensions except the first one !!

void print_2D_array(int a[2][3]) //[2][3] are necessary 
{
	for (int row = 0; row < 2; row++) {
	for (int col = 0; col < 3; col++)
	printf("%d ", a[row][col]);
	printf("\n");
}
}