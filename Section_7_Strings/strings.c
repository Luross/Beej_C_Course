#include <stdio.h>
#include <string.h>

int my_strlen(char* s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;

	return count;

}
int main()
{	
	//Strings are always noted by double not single quotes

	char* s = "Hello World!\n";

	// That's called a stringl literal, which cannot be modified

	// You can still print a full string with %s
	printf("%s", s);

	// Array notation can therefore be used
	// Array notation are string variable and can be modified

	char ss[] = "Hello, world!\n";
	for (int i = 0; i<14; i++)
		printf("%c", ss[i]);

	// Trying to modify a string literal initalized as a pointed will fail
	/* s[0] = 'G';
	printf("%s", s); */

	// but not if its initialized as array
	ss[0] = 'G';
	printf("%s", ss);


	// the <string.h> library has a function to get the len of a string : strlen(string)

	printf("The String is %zu bytes long. \n", strlen(s));

	// string end with the NUL character \0
	// It is therefore possible to create a strlen function that counts all chracter until \0 is reached
	printf("The String is %zu bytes long. \n", my_strlen(s));

	char c[] = "SBR";
	char* t;
	// you CAN NOT use the equal sign to copy a string
	t=c;
	//This results in copying a pointer to the first char of string 

	printf("t is equal to %d\n", t); // prints a memory adress in decimal with %d or in ex with %p
	printf("c is %s\n",c);
	// It checks if you modify it content, it will modify the content at address c[0]
	t[0] = 'Z';

	char k[100]; // you need to create an array with enough space to perfom a copy
	//creating a char* will result in a crash
	printf("c is now %s\n",c);

	// you can copy a string with the strcpy function of the string.h library, using char pointers in each arguments
	printf("k is %s\n",k);
	strcpy (k, c); // arg one is array to copy to, arg two is array to copy from
	printf("k is now %s after using strcpy\n",k);


	return 0;
}