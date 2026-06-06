#include <stdio.h>
#include <stdlib.h>
#define MAX_CAPACITY 10
#include <stddef.h>
// -Nested structs-

// structs can be nest

struct soda_can{
	int volume;
	char* brand;
};

struct vending_machine {
	int money;
	struct soda_can sc;
};

struct better_vending_machine {
	int money;
	struct soda_can sc[MAX_CAPACITY];
};

//- Self-referential structs -
// C supports self-reference which is actually very useful for data and modelisation

struct node {
	int data;
	struct node *next;
};

//flexible array size
//you can alllocate an array of flexible size at the end of the struct:

struct len_str {
	int length;
	char data[]; //leave [] empty
};

// the course went into more deets about how to do this "manually", but in C99+ [] is acceptable
//but only at the end of the struct, otherwise it will overflow to the next data type !


struct foo{
	int a;
	char b;
	int c;
	char d;
};
int main()
{
	struct vending_machine my_machine = {
		.money = 25,
		.sc.volume = 33,
		.sc.brand = "Enola Soda"
	};

	//another more compact way to write it is :

	struct vending_machine another_machine = {
		.money = 33,
		.sc ={
			.volume = 33,
			.brand = "EGG Soda"
		}
	};

	printf("Money : %d, soda : %s, soda volume : %d\n", my_machine.money, my_machine.sc.brand, my_machine.sc.volume);
	printf("Money : %d, soda : %s, soda volume : %d\n", another_machine.money, another_machine.sc.brand, another_machine.sc.volume);

	// this is nice but with this structure you can only define one soda can per vending machine, not very efficient
	// forutnately you can initialize an array of structs !

	struct better_vending_machine egg_machine = {
		.money = 150,
		.sc = {
			//[index_number].methode_name: 
			[0].brand = "Enola Soda",
			[0].volume = 33,
			// more compact writing 
			[1] = {.brand = "EGG Soda", .volume = 25},
		}
		

		
	};

	for (int i = 0; i < MAX_CAPACITY; i++)
		if (egg_machine.sc[i].brand != NULL)
			printf("Soda %d : %s\n", i+1, egg_machine.sc[i].brand);

	struct node* head;
	head = malloc(sizeof(struct node));
	head -> data = 11;
	head -> next = malloc(sizeof(struct node));
	head -> next -> data = 22;
	head -> next -> next = malloc(sizeof(struct node));
	head -> next -> next -> data = 33;
	head->next->next->next = NULL;
	for (struct node *current = head; current != NULL; current = current->next) {printf("%d\n", current->data);}

	// - Padding bytes- 
	// compiler adds padding bytes as it sees fit:
	printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char)); // o : 10
	printf("%zu\n", sizeof(struct foo)); // o : 16
	// same type component, different size. This can be relevant for optimization
	// tip : there is a function in <stddef.h> that measures this padding : offsetstoff:*

	printf("%zu\n", offsetof(struct foo, a)); // 0
	printf("%zu\n", offsetof(struct foo, b)); // 4
	printf("%zu\n", offsetof(struct foo, c)); // 8
	printf("%zu\n", offsetof(struct foo, d)); // 12

	// indicates we use 4 bytes per data type, which is weird because int is only 1 byte, so there is 3 padding bytes that compiler adds for optimization

	// -Fake OOP-
	// TBC...
	return 0;
}