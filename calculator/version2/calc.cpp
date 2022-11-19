#include <iostream>
#include "Calculator/calculator.h"
#include "Helpers/helpers.h"
using namespace std;



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