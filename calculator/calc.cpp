#include <iostream>
using namespace std;

void get_entries(float& first, float& second);
void get_entries(double& first, double& second); //function overloads example
int main() {
    enum CHOICE {INVALID=0, ADD, SUBTRACT, MULTIPLY, DIVIDE};
    CHOICE _choice;
    bool isRunning = true;
    
    while (isRunning)
    {
        float firstNumber = 0; float secondNumber = 0;
        _choice = INVALID;

        while(_choice==INVALID){
            int choice = 0;
            cout << "Press 1 for add, 2 for subtract, 3 for multiply, 4 for divide \n";
            cin >> choice;
            if (choice > 0 && choice < 4)
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
            case 1:
            cout << "Addition " << endl;
            get_entries(firstNumber, secondNumber);
            cout << "Result: " << firstNumber << " + " << secondNumber << " = " <<firstNumber + secondNumber <<endl;
            break;

            case 2:
            cout << "Subtraction " << endl;
            get_entries(firstNumber, secondNumber);
            cout << "Result: " << firstNumber << " - " << secondNumber << " = " <<firstNumber - secondNumber <<endl;
            break;

            case 3:
            cout << "Multiplication " << endl;
            get_entries(firstNumber, secondNumber);
            cout << "Result: " << firstNumber << " X " << secondNumber << " = " <<firstNumber * secondNumber <<endl;
            break;

            case 4:
            cout << "Division " << endl;
            default:
            cout << "Invalid Choice!";
            break;
            do
            {
            get_entries(firstNumber, secondNumber);
            if (secondNumber == 0)
                {
                    cout << "Can not divide by 0, please try again! \n";
                }
            }
            while (secondNumber == 0);
            cout << "Result: " << firstNumber << " / " << secondNumber << " = " <<firstNumber / secondNumber <<endl;
            break;
            
        }
        char answer = 0;
        cout << "Do you want another calculation? ('y' to proceed) \n";
        cin >> answer;
        if (answer == 'y')
        {
            continue;
        }
        cout << "Exiting application \n";
        isRunning = false; // break from loop
    }


    return 0;
}

void get_entries(float& first, float& second){
    cout << "Enter 1st Number \n";
    cin >> first;
    cout << "Enter 2nd Number \n";
    cin >> second;
}

void get_entries(double& first, double& second){
    cout << "Enter 1st Number \n";
    cin >> first;
    cout << "Enter 2nd Number \n";
    cin >> second;
}