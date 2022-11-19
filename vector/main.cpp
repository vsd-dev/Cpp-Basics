#include <iostream>
#include <vector>

int main(){


    std::vector<float> data;
    std::cout << sizeof(data);
    for (unsigned int i=0; i < 40; i++)
    {
        data.push_back(i);
        std::cout << "i: " << i << " data: " << data[i] << std::endl;
    }
    return 0;
}