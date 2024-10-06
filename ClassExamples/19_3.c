// 3. Write an algorithm that inputs 3 integers and output them in non decreasing order.

#include <stdio.h>

int main() {
    int num1, num2, num3;

    // Input three integers
    printf("Enter three integers:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Sort the numbers using a simple comparison
    int temp;

    // Compare num1 and num2
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // Compare num2 and num3
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }

    // Compare num1 and num2 again
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // Output the numbers in non-decreasing order
    printf("The numbers in non-decreasing order are: %d, %d, %d\n", num1, num2, num3);

    return 0;
}
