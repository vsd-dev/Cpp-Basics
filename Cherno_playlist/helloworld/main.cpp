#include <iostream>
#include "Log.h"
// void Log(const char* message);
int Multiply(int a, int b)
{
    Log("Multiply");
    return a * b;
}


int main()
{   
    int a = 15;
    a++;
    Log("Hello World!!");
    initLog();
    std::cout << Multiply(3, 4) << std::endl;
    int var = 8;
    double* ptr = (double*)&var;
    *ptr = 10;
    std::cout << "ptr " << *ptr << std::endl;
    return 0;
}