#include <stdio.h> 

// structs are data types which old multiple pîeces of datas : 
struct car {
	char *name;
	float price;
	int speed;
};

// You often declare structs globally
// you can then declare a variable of the struct type :
struct car saturn;
// The variable can be declared globally or locally

void set_price (struct car*, float);

int main()
{
	// sub data type can be defined with the . operator

	saturn.name = "Saturn SL/2";
	saturn.price = 15999.99;
	saturn.speed = 175;
	printf("Name:%s\n", saturn.name);
	printf("Price (USD):%f\n", saturn.price);
	printf("Top Speed (km): %d\n", saturn.speed);

	// structs can also be initialized with some value under {}

	struct car jupiter = {"Jupiter SL/2", 15000.99, 155};

	printf("Name:%s\n", jupiter.name);
	printf("Price (USD):%f\n", jupiter.price);
	printf("Top Speed (km): %d\n", jupiter.speed);
	
	// initialization can also be named as kwargs satrting with . so that they don't have to be in order
	// This makes the declaration clearer

	struct car uranus = {.speed= 140, .name="Uranus SL/2", .price=12000.99};

	printf("Name:%s\n", uranus.name);
	printf("Price (USD):%f\n", uranus.price);
	printf("Top Speed (km): %d\n", uranus.speed);

	// don't forget the & to modify the content pointed to
	set_price(&uranus, 799.99);

	printf("Price (USD):%f\n", uranus.price);
	
	// structs can also be copied as any variable
	struct car mars;
	mars = uranus;

	printf("Name:%s\n", mars.name);
	printf("Price (USD):%f\n", mars.price);
	printf("Top Speed (km): %d\n", mars.speed);

	
	return 0;
}

/* You can pass a struct to a function, but as per other datatype passing
the struct will only pass a copy of the variable. If you want to modify
the struct itself you will have to use pointers as such */

void set_price(struct car* c, float new_price)
{
	// !!- to modify sub data type via pointer you need to derefernce by putting parenthesis and *:
	(*c).price = new_price;

	// !!- another way to dereference the pointer is to use an arrow ->

	c -> price = new_price;

	//The two lines are the same, the arrow just looks cleaner

	printf("Price of car %s has been set to %f.\n", (*c).name, (*c).price);
}