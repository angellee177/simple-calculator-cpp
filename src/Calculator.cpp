#include "../include/Calculator.h"

#include <cmath>
#include <iostream> // for error message
#include <math.h>
using namespace std;

double Calculator::calculate(double num1, char op, double num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                cerr << "Error: Division by Zero" << endl;
                return 0.0;
            }
        case '^':
            return pow(num1, num2);
        default:
            cerr << "Error: Invalid Operator" << endl;
            return 0.0;
    }
}