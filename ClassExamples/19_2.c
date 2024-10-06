// 2. Write a program to print max of three numbers.

#include <stdio.h>

int main() {
    int num1, num2, num3;

    // Input three numbers
    printf("Enter three numbers:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Determine the maximum
    int max = num1; // Assume num1 is the max initially

    if (num2 > max) {
        max = num2; // Update max if num2 is greater
    }
    
    if (num3 > max) {
        max = num3; // Update max if num3 is greater
    }

    // Print the maximum
    printf("The maximum of the three numbers is: %d\n", max);

    return 0;
}
