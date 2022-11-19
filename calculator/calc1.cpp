#include <iostream>
#include "calculator.h"
using namespace std;

bool checkIfUserWantsRToContinue()
{
    char answer = 0;
    cout << "Do you want another calculation? ('y' to proceed) \n";
    cin >> answer;
    if (answer == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

///////////////////////////////////////

int main() {
    Calculator calc;
    bool IsRunning = true;
    while (IsRunning)
    {
        calc.run();
        IsRunning = checkIfUserWantsRToContinue();
    }
    return 0;
}