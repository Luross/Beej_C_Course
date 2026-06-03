#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	float total = 0;
	for (int i = 1; i<argc; i++)
	{
		float value = atof(argv[i]);
		total += value;
	}

	int temp = total;
	if (total - temp == 0)
	{
		printf("%d\n", temp);
	}

	else{
		printf("%.1f\n", total);
	}

}