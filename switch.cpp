#include <iostream>
using namespace std;


void add(int num1, int num2);
void sub(int num1, int num2);
void mult(int num1, int num2);
void division(double num1, double num2);

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    for (int i = 1; i <= 4; i++) 
    {
        switch (i) 
        {
            case 1:
                mult(num1, num2);
                break;
            case 2:
                division(num1, num2);
                break;
            case 3:
                add(num1, num2);
                break;
            case 4:
                sub(num1, num2);
                break;
        }
    }
    return 0;
}
