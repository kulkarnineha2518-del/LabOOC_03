#include <iostream>
using namespace std;

int main() {
    int number;
    int factorial = 1;

    cout << "Enter a positive number: ";
    cin >> number;

    while (number > 1) {
        factorial = factorial * number;
        number = number - 1;
    }

    cout << "Factorial is: " << factorial << endl;

    return 0;
}

