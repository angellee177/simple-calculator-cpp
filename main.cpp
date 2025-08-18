#include <iostream>

#include "include/Calculator.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Calculator calculator;
    double num1, num2, result;
    char op;

    cout << "Please enter first numbers" << endl;
    cin >> num1;

    cout << "Please enter Operator (+, -, /, *, ^)" << endl;
    cin >> op;

    cout << "Please enter second numbers" << endl;
    cin >> num2;

    result = calculator.calculate(num1, op, num2);
    cout << "The result is " << result << endl;
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}