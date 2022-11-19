// keep only decorations in the class. Definiotions move to calculator.cpp
class Calculator
{
public:
    Calculator();
    void run();
private:
    float firstNumber, secondNumber;
    void get_entries();
    
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