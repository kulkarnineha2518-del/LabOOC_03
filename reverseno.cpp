#include <iostream>
using namespace std;

int main() {
    int n, r;
    int rev = 0;

    cout << "Enter a number: ";
    cin >> n;

    while (n > 0) {
        r = n % 10;       // Get the last digit
        rev = rev * 10 + r; // Add it to the reversed number
        n = n / 10;       // Remove the last digit
    }

    cout << "Reversed: " << rev;

    return 0;
}

