#ifndef CALCULATOR_H // check if the header already define
#define CALCULATOR_H // define the Calculator header
#include <string>

using namespace std;

class Calculator {
public:
    // Takes a string expression, evaluates it,
    // and returns the result as a string.
    string evaluateExpression(const string& expression);

    // Clear the current expression and the last result
    void clear();

    // Clears only the last character of the current expression
    void backspace();

    // Return the current state of the expression as a string.
    string getExpression();

    // return the previous result as a string for history display.
    std::string getHistoryResult();
};

#endif
