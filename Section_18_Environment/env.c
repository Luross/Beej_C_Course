#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char** environ;
// - ENVIRONMENTAL_VARIABLES -
// argc and argv are default parameters passed in command line exercution

int main(int argc, char* argv[]) //the last argv is always NULL
{//argv stands for argvalue, in contains the value of the strins

	for (int i = 0; i < argc; i++){ //you can increment until you hit argc value
		printf("arg %d: %s\n", i, argv[i]); 
	}

	//or you can increment untill Null
	int i = 1;
	for (char** p = argv +1; *p != NULL; i++, p++){
		printf("Argv %d : %s \n", i, *p);

	}

	// - OTHER_ENV_VARS - 
	// bash will have some env vars defined
	// you can use getenv(str VAR_NAME) to check for a variable

	char name[] = "ENOLA";
	char* val = getenv(name);

	if (val == NULL){
		printf("Cannot find variable named %s in the environment.\n", name);
		return EXIT_FAILURE;
	}//env variables can be defined with the Export command

	printf("Value of variable %s : %s\n", name, val);

	// you can also use the function setenv() to define a envvar
	setenv(name, "ULTRA GAY", 1);
	val = getenv(name); //redefine val to update change

	printf("Value of variable %s : %s\n", name, val);

	//finally you can also print all variables by using the extern variabl environ
	for(char** p =environ; *p != NULL; p++){
		printf("%s\n", *p);
	} //that's a whole bunch of variables !

	return 0;// btw, exit 0 is always implicitely added by default
	//you've been adding it for nothing ! :)
	// 0 = success, equivalent to EXIT_SUCCESS macro
	// but we can can add other exit, 1 means failure and can be summoned with EXIT_FAILURE
	// you can also add other numbers for debugging like 2 3 4, so you can know where the program failed
}