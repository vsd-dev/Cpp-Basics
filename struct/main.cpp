#include<iostream>

int main()
{
struct {
	std::string brand;
	std::string model;
	int year;	
} car1, car2;

car1.brand = "Tesla";
car1.model = "Model 1";
car1.year = 2020;

car2.brand = "Tesla";
car2.model = "Model 3";
car2.year = 2022;

std::cout << "Car " << car1.brand << car1.model << " " << car1.year << std::endl;
std::cout << "Car " << car2.brand << car2.model << " " << car2.year << std::endl;
return 0;

}
