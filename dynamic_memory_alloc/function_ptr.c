#include <stdio.h>
#include <stdlib.h>



void printHello(char *name){

printf("Hello %s\n", name);
}



int main(){
	
	void (*ptr)(char *);
	ptr = printHello;
	ptr("John");

	return 0;
}
