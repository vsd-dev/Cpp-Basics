#include <iostream>


void increment(int *p){
    /*function to showcase change value by reference*/
    std::cout << "p: " << p << std::endl;
    *p = (*p) +1;

};

int main(){
    int a = 10;
    std::cout << "address of a: " << &a << std::endl;
    for (int i=0;i < 5; i++)
    {   
        
        std::cout << "value of a: " << a << std::endl;
        increment(&a);

    }

    return 0;
}