#include <stdio.h>

int main()
{	
	// files are open with the file pointer type FILE*
	FILE* fp;

	fp = fopen("hello.txt", "r");

	int c = fgetc(fp);
	printf("%c\n", c);
	fclose(fp);
	return 0;
}