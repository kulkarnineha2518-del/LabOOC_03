#include <stdio.h>

int main() {
    int numbers[4];
    int sum = 0;

    printf("Enter 4 integers:\n");

    for (int i = 0; i < 4; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &number[i]);
    }

    for (int i = 0; i < 4; i++) {
        sum += number[i];
    }

    printf("The sum of all elements is: %d\n", sum);

    return 0;
}
