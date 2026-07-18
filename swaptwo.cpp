#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Enter first positive integer (a): ";
    cin >> a;

    cout << "Enter second positive integer (b): ";
    cin >> b;

    a = a + b;   
    b = a - b;   
    a = a - b;   

    cout << "After swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

