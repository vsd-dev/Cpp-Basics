#include <fstream>
#include <iostream>
#include <vector>


int main(){
    std::fstream in;
    bool opened;
    in.open("data.txt");
    opened = in.is_open();
    if(opened)
    {
        std::cout << "File is Opened!" << std::endl;
        std::vector<float>fileData;
        while(!in.eof())
        {
            float tmp = 0;
            in >> tmp;
            fileData.push_back(tmp);

        }
        std::cout << "Data read :";
        for (int i=0;i<fileData.size();i++)
        {
            std::cout << fileData[i] << ", ";
        }
    }
    else
    {
        std::cout << "File unable to open!\n";

    }

    
    return 0;
}