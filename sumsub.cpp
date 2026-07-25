#include <iostream>
using namespace std;

// Added parameters so it can receive numbers from switch.cpp
void add(int num1, int num2) {
    cout << "--- ADDITION PROGRAM ---" << endl;
    cout << "The sum is: " << (num1 + num2) << "\n\n";
}

// Added parameters so it can receive numbers from switch.cpp
void sub(int num1, int num2) {
    cout << "--- SUBTRACTION PROGRAM ---" << endl;
    cout << "The subtraction is: " << (num1 - num2) << "\n\n";
}
