using namespace std;
class Calculator
{
public:
    Calculator()
    {
        firstNumber = 0;
        secondNumber = 0;
        _choice = INVALID;

    }
    ~Calculator(){} //destructer

    void run()
    {
        _choice = CHOICE::INVALID;

        while(_choice==CHOICE::INVALID)
        {
            int choice = 0;
            cout << "Press 1 for add, 2 for subtract, 3 for multiply, 4 for divide \n";
            cin >> choice;
            if (choice > 0 && choice < 5)
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
            cout << "Addition " << endl;
            get_entries();
            cout << "Result: " << firstNumber << " + " << secondNumber << " = " <<firstNumber + secondNumber <<endl;
            break;

            case SUBTRACT:
            cout << "Subtraction " << endl;
            get_entries();
            cout << "Result: " << firstNumber << " - " << secondNumber << " = " <<firstNumber - secondNumber <<endl;
            break;

            case MULTIPLY:
            cout << "Multiplication " << endl;
            get_entries();
            cout << "Result: " << firstNumber << " X " << secondNumber << " = " <<firstNumber * secondNumber <<endl;
            break;

            case DIVIDE:
            cout << "Division " << endl;
            do
            {
                get_entries();
                if (secondNumber == 0)
                    {
                        cout << "Can not divide by 0, please try again! \n";
                    }
            }
            while (secondNumber == 0);
            cout << "Result: " << firstNumber << " / " << secondNumber << " = " <<firstNumber / secondNumber <<endl;
            break;
            default:
            cout << "Invalid Choice!";
            break;
        }
    }

private:
    float firstNumber, secondNumber;

    void get_entries()
    {
        cout << "Enter 1st Number \n";
        cin >> firstNumber;
        cout << "Enter 2nd Number \n";
        cin >> secondNumber;
    }
    enum CHOICE
    {
        INVALID=0, 
        ADD, 
        SUBTRACT, 
        MULTIPLY, 
        DIVIDE
    };
    CHOICE _choice;

};