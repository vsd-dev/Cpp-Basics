#include <iostream>
#include<memory>
int main(){
	
	std:: cout << "Pointer Example \n";
	{
		int*integerDataPtr;
		std::cout << "Size: " << sizeof(integerDataPtr) << std::endl;
		delete integerDataPtr; //Before becomes out of scope, need to de					//lete the pointer
	}

	
	{
		std::unique_ptr<int>integerDataPtr;
		std::cout << "Size: " << sizeof(integerDataPtr) << std::endl;
		//This will automatically delete ptr from memory when it becomes 		//out of scope
	}

	return 0;

	}
