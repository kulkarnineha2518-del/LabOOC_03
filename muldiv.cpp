#include <iostream>
using namespace std;


void mult(int num1, int num2) {
    cout << "--- MULTIPLICATION ---" << endl;
    cout << "The product is: " << (num1 * num2) << "\n\n";
}


void division(double num1, double num2) {
    cout << "--- DIVISION  ---" << endl;
    if (num2 == 0) {
        cout << "Error: Division by zero!\n\n";
    } else {
        cout << "The result is: " << (num1 / num2) << "\n\n";
    }
}
