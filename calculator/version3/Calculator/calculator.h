#include<vector>

// keep only decorations in the class. Definiotions move to calculator.cpp
class Calculator
{
public:
    Calculator();
    void run();
private:
    float firstNumber, secondNumber;
    std::vector<float> pastResults;
    void get_entries();
    void see_past_results();
    
    enum CHOICE
    {
        INVALID=0, 
        ADD, 
        SUBTRACT, 
        MULTIPLY, 
        DIVIDE,
        PAST_RES
    };
    CHOICE _choice;

};