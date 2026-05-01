#include <stdio.h>


//File scope
// any variable defined outside of block has file scope

int expedition = 35;
int main(){

	int obscur = 33;
	//block scope, variables included inside curly braces
	if (obscur == 33){
		int clair = 66;//only exists in this if block !
		printf("%d %d\n", clair, obscur);
	}

	printf("%d\n", obscur);//valid because the variable is in the main function block
	//printf("%d\n", clair); -> this would crash

	// variable hiding: you can have two variable identically named in differnt scopes. It's not recommended because it leads to confusion but if you do, the one defined in the narrowest scope takes precendence
	printf("Expedition %d\n", expedition);
	int expedition = 34;

	{
		int expedition = 33;
		printf("Expedition %d\n", expedition);//uses variable inside block

	}

	printf("Expedition %d\n", expedition); //use the outside variable
	// loop-scope
	// You used it a lot, but one thing to know is that variable declared to define a loop won't interfer with variable with the same name

	for(int i = 0; i < 5; i++){
		int i = 33;
		printf("Expedition %d\n", i); // will print i inside the block, not affected by modification of i for the loop
	}

	return 0;
}