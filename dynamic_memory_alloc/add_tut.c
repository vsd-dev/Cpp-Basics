#include <stdio.h>
#include <stdlib.h>


void printme(){
printf("Hello World! \n");
}

int *add(int *a, int *b)
	{
	
	int *c = (int*)malloc(sizeof(int));
	*c = (*a) + (*b);
	return c;

	}

int main(){

int a = 4;
int b = 6;
printme();
int *c = add(&a,&b);
printf("4 + 6 = %d\n", *c);


return 0;

}
