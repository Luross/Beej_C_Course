#include <stdio.h>

int main(void)
{
	int i = 2;
	int j;
	float f = 3.14;
	char *s = "Hello, ZA WARUDO";
	// bool operator is included by default in c23
	// it is actually a disguised int which is equal to 1 for true and 0 for false
	// although you cannot increment or decrement it, so be carefull !
	bool x = true;
	int y = 10;

	if (x)
	{
		printf("x is true !\n");
		printf("x = %d \n", x);
	}
	printf("%s i = %d and f = %f \n", s, i, f);

	// there is a short-form of the if statement using ? and : example:

	y += x > 10? 15: 35;

	// this expression means if x>10 y += 15, else y += 35
	// It does NOT mean if y + x > 10 then y == 15 else y == 35
	// this form is called "ternary operator"; 
	// it makes the code a bit more obtuse but more compact

	printf("y is equal to %d \n", y);

	// ternary operator can be used directly as an argument :

	printf("The number %d is %s \n", x, x == 0? "even":"odd");

	// équivaut à if x == 0 then "even" else "odd"

	// post and pre increment/decrement
	// You already know about post-increment eg i++
	// But you can also use pre-increment ++i
	// pre-increment will be added to the variable before it is evaluated


	i = 10;
	j = 5 + i++;
	// Compute 5 + i, _then_ increment i
	printf("%d, %d\n", i, j);
	// Prints 11, 15

	i = 10;
	j = 5 + ++i;
	// Increment i, _then_ compute 5 + i
	printf("%d, %d\n", i, j);
	// Prints 11, 16

	//comma is also an operator, it can be used to separate expression
	// this will be tackled later

	// already known : conditional operators eg == != < >
	// already known : boolean operators : && || ! 
	// note that boolean operator ! can be used as such :

	if (!(x < 12))
	printf("x is not less than 12\n");

	//sizeof you already know but it can be used with the with the specifier zu
	// sizeof output a size_t type %zu is it's specifier

	printf("X is %zu bytes\n", sizeof x);

	// if operator : you actually dont need to use {} to execute one line

	if (x == 10)
	printf("This happens if x is 10\n");
	printf("OUTSIDE OF IF LINE\n"); // this line is out of the if condition

	// same goes for else/switch/while/do-while
	// even though for while loop never do this !
	while (i < 15)
	{
		printf("????\n");
		i++;
	}

	// Already know : do-while/switch/for
	// don't forget to break at the end of your switch cases, though
	// not putting a break is called fall through, it can be useful sometimes
}