#ifndef EXTERNAL_H
#define EXTERNAL_H
#include <iostream>
#include <string>


class Player
{   
    private:
        
    public:
        std::string name;
        Player()
            {
                name = "Player 1";
                print();
                // std::cout << "Created" << std::endl;
            }
        ~Player()
            {
                std::cout << "Destroyed" << std::endl;
            }
        void print()
            {
                std::cout << "Created: " << name << std::endl;
            }
};





#endif