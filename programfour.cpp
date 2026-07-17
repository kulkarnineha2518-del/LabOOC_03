#include <iostream>
using namespace std;

int main() {
    int choice;
    float num1, num2; 

    // This loop keeps running for all rounds
    while (true) {
        // 1. Show the options
        cout << "\n--- CALCULATOR MENU ---" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Modulo (Remainder)" << endl;
        cout << "6. Exit Program" << endl; 
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // 2. Check if the user wants to exit
        if (choice == 6) {
            cout << "Exiting calculator. Goodbye!" << endl;
            break; 
        }

        // 3. Check for invalid choices
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice! Please try again." << endl;
            continue; 
        }

        // 4. Get the numbers from the user
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        // 5. Calculate and show the result
        if (choice == 1) {
            cout << "Result: " << num1 + num2 << endl;
        }
        else if (choice == 2) {
            cout << "Result: " << num1 - num2 << endl;
        }
        else if (choice == 3) {
            cout << "Result: " << num1 * num2 << endl;
        }
        else if (choice == 4) {
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error! Division by zero is not allowed." << endl;
            }
        }
        else if (choice == 5) {
            if (num2 != 0) {
                // (int) converts the float to a whole number so modulo works
                int intNum1 = (int)num1;
                int intNum2 = (int)num2;
                cout << "Result (Remainder): " << intNum1 % intNum2 << endl;
            } else {
                cout << "Error! Modulo by zero is not allowed." << endl;
            }
        }
    }

    return 0;
}
