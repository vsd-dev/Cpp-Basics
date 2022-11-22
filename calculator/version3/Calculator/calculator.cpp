#include "calculator.h"
#include <iostream>
using namespace std;

Calculator::Calculator()
{
    firstNumber = 0;
    secondNumber = 0;
    _choice = INVALID;
}

void Calculator::run()
{
    _choice = CHOICE::INVALID;

    while (_choice == CHOICE::INVALID)
    {
        int choice = 0;
        cout << "Press 1 for add, 2 for subtract, 3 for multiply, 4 for divide, 5 to see past results\n";
        cin >> choice;
        if (choice > 0 && choice < 6)
        {
            _choice = static_cast<CHOICE>(choice);
        }
        else
        {
            cout << "Invalid entry of \'" << choice << "\' - try again" << endl;
        }
    }

    switch (_choice)
    {
    case ADD:
    {
        cout << "Addition " << endl;
        get_entries();
        float result = firstNumber + secondNumber;
        cout << "Result: " << firstNumber << " + " << secondNumber << " = " << result << endl;
        pastResults.push_back(result);
    }
    break;

    case SUBTRACT:
    {
        cout << "Subtraction " << endl;
        get_entries();
        float result = firstNumber - secondNumber;
        cout << "Result: " << firstNumber << " - " << secondNumber << " = " << result << endl;
        pastResults.push_back(result);
    }
    break;

    case MULTIPLY:
    {
        cout << "Multiplication " << endl;
        get_entries();
        float result = firstNumber * secondNumber;
        cout << "Result: " << firstNumber << " X " << secondNumber << " = " << result << endl;
        pastResults.push_back(result);
    }
    break;

    case DIVIDE:
    {
        cout << "Division " << endl;
        do
        {
            get_entries();
            if (secondNumber == 0)
            {
                cout << "Can not divide by 0, please try again! \n";
            }
        } while (secondNumber == 0);
        float result = firstNumber / secondNumber;
        cout << "Result: " << firstNumber << " / " << secondNumber << " = " << result << endl;
        pastResults.push_back(result);
    }
    break;
    case PAST_RES:
        see_past_results();
        break;
    default:
        cout << "Invalid Choice!";
        break;
    }
}

void Calculator::get_entries()
{
    cout << "Enter 1st Number \n";
    cin >> firstNumber;
    cout << "Enter 2nd Number \n";
    cin >> secondNumber;
}
void Calculator::see_past_results()
{
    if (!pastResults.size())
    {
        std::cout << "No past results to show \n";
        return;
    }
    std::cout << "Past Results \n"
              << "_________________\n";
    for (auto r : pastResults)
    {
        std::cout << r << ",\n";
    }
    std::cout << "_________________\n";
}