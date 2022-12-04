#include <iostream>

void Double(int array[], int size){

for (int i=0;i<size;i++)

    array[i] = 2*array[i];
};


int main(){
    int array [] = {1, 2, 3, 4, 5};
    int size = sizeof(array)/sizeof(array[0]);
    
    Double(array, size);

    for (int i=0;i<size;i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}