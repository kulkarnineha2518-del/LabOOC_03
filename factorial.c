#include <stdio.h>

int main() {
    int n = 5; // Change this to find other factorials
    int fact = 1;

    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    printf("Factorial of %d is %d", n, fact);
    return 0;
}

