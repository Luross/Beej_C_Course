#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* readline(FILE*);
int main()
{
	/* -- Memory Allocation */
	// - The malloc() function -
	// Malloc takes a number of byte as paremeter and returns a void* to that block
	//Basics are simple : allocate memory to a pointer with sizeof(your_data_type), use the variable pointed to and free up the space once done :

	int* p = malloc(sizeof(int)); // allocation to the pointer must be done first
	// You can also use the name of your variable in sizeof
	p = malloc(sizeof *p); //p points to an in so size of *p is size of int
	*p = 12; // You can then dereference it to change its content
	printf("%d\n",*p);//Use the variable

	free(p); //FREEDOM FOR THE BYTES !

	// - Error Checking -
	// It is paramount to always add an exception to usage of malloc, because you never know if you will have enough memory available

	int* x;

	x = malloc(sizeof(int) * 10);
	// This exception is coded by checking the pointer for NULL value, which it will get if malloc failed
	if (x == NULL){
		printf("Error allocating 10 ints.\n");
		return 1;
	}
	*x = 33;
	printf("%d\n", *x);
	free(x);

	// -Allocation to arrays -
	//You can allocate to arrays by precising the number of bytes in the parameter

	char* s = malloc(33); //allocating 33 bytes to a char variable, that's called a string
	if (s == NULL){
		printf("Error allocating string.\n");
		return 1;
	}

	strcpy(s,"Ensemble au Clair-Obscur.\n"); //Assigning a value to an allocated string will result in an error when trying to free up space. writting s = "Ensemble au Claire-Obscure" is assigning a string literal to s, overwritting the memory allocation

	//That's why we usually use array notation s[] that automatically manages the memory allocation
	printf("%s", s);

	memset(s, 0, 10*sizeof(char)); //memset can be used to free up the memory

	// You can also use calloc, which resets the memory to 0 so it will work even if you didn't free up the memory before

	s = calloc(33, sizeof(char));
	
	if (s == NULL){
		printf("Error allocating string.\n");
		return 1;
	}
	strcpy(s, "Son souvenir dure.\n");
	printf("%s", s);
	// realloc can be used to change allocation size

	float* fp = malloc(sizeof *fp * 20);
	for(int i = 0; i<20; i++)
		fp[i] = i / 20.0; // this allocates all fractional values from 0 to 1 with 0.5 increments

	float* new_p = realloc(fp, sizeof *fp*40); 

	if (new_p == NULL) {
		printf("Error reallaocing\n");
		return 1;
	} 

	fp = new_p; // you can reassign the old point to the new. Using the equal sign actually "fuses" them, as they will both point to the same address which makes it so that you don't have to free them both at the end

	for (int i = 20; i < 40; i++)
		fp[i] = 1.0 + (i - 20) / 20.0;

	for (int i = 0; i < 40; i++)
		printf("%.2f\n", fp[i]);

	free(fp); // as explained above, this frees fp and new_p !

	FILE* file_pointer = fopen("foo.txt", "r");
	char* line;

	while ((line = readline(file_pointer)) != NULL){// using the function below, each line is read allocating the exact amount of memory needed !
		printf("%s\n", line);
		free(line);
	}


	return 0;
}
// This is a function that reads a line from a file of any size and adapts the buffer to the right size fitting the line

char* readline(FILE *fp)
{
	int offset = 0; // gives the index of the next char that goes into the buffer, initially 0
	int bufsize = 4; //arbitrary value, pref power of 2
	char* buf;// the buffer !
	int c; // the char being red

	buf = malloc(bufsize); // allocates initial buffer

	if (buf == NULL) //malloc error check
		return NULL;

	// main loop : reads until new line or EOF
	while (c = fgetc(fp), c != '\n' && c != EOF){

		//the loop checks if we are outof room for the buffer

		//basically offset == bufsize -1 means "if the line you are reading reach the size of the buffer, increase the size of the buffer"
		if (offset == bufsize -1){ //-1 account for '\0'
			bufsize *= 2;

			char *new_buf = realloc(buf, bufsize);//reallocs the new buff size

			if (new_buf == NULL) {// classic error check
				free(buf);
				return NULL;
			}
			buf = new_buf; //allocs the new size to our main pointer, remember that "fuses" them as they now point the same address

		} 
		buf[offset++] = c; //adds the byte into the buffer
	}



	if (c == EOF && offset == 0){
		free(buf);
		return NULL;
	}

	//shrinking part
	if (offset < bufsize -1){/*bufsize has been multplied by 
	2 as many times needed, might be 64 bytes right now 
	while the actual number of chars is 35. Offset counted 
	the number of bytes (-1) because it's the index number of bytes the array. So if offset is less than bufsize - 1 
	then... */
		char* new_buf = realloc(buf, offset + 1); //... then we realloc the buffer size to the offset value !

		if (new_buf != NULL) // errorcheck
			buf = new_buf; // and don't forget to pass this new value to the main point, again "fusing" them
	}

	buf[offset] = '\0'; // and we add the NUL terminator.
	 //As offset is the last index number,
	 // just add with buf[offset]
	return buf;

}