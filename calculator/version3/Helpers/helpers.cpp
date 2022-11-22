#include "helpers.h"
#include <iostream>
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