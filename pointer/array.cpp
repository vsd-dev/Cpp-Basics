#include <iostream>

int main(){
    int a[] = {1, 4, 7, 12, 45};
    std::cout << "address of a[0]: " << a << std::endl;
    std::cout << "address of a[0]: " << &a[0] << std::endl;

    std::cout << "value of a[0]: " << *a << std::endl;
    std::cout << "value of a[0]: " << a[0] << std::endl;
    return 0;
}