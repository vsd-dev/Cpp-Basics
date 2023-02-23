#include <iostream>
class Player
{
public:
    int x, y;
    int speed;
    void Move(int xa, int ya)
    {
        x += xa*speed;
        y += ya*speed;
    }
};


int main(){


    std::cout << "HELLO" << std::endl;
    Player player1;
    player1.x = 5;
    player1.y = 10;
    player1.speed = 20;
    player1.Move(2, 2);
    return 0;
}