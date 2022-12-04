#include <iostream>
#include <string.h>

int main(){

    char C[] = "JOHN";
     
    printf("%s \n", C); //Null termination (Not needed for cpp)
    printf("Size in bytes = %lu \n", sizeof(C)); // %lu for unsigned long datatype
    int len = strlen(C);
    printf("Length of string = %d \n", len); // null termminated char not included
    return 0;
}