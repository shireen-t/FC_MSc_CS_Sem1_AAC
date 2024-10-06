// Write a menu driven program for simple functions
// used for factorial, Fibonacci, palindrome, perfect
// number.

#include <stdio.h>

// Function to calculate factorial
long long factorial(int n) {
    if (n < 0) return -1; // Return -1 for negative numbers
    if (n == 0) return 1; // 0! is 1
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to generate Fibonacci series
void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    int original = num, reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    int choice, num;

    do {
        printf("\nMenu:\n");
        printf("1. Factorial\n");
        printf("2. Fibonacci Series\n");
        printf("3. Palindrome Check\n");
        printf("4. Perfect Number Check\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number for factorial: ");
                scanf("%d", &num);
                printf("Factorial of %d is %lld\n", num, factorial(num));
                break;
            case 2:
                printf("Enter the number of terms for Fibonacci series: ");
                scanf("%d", &num);
                fibonacci(num);
                break;
            case 3:
                printf("Enter a number to check for palindrome: ");
                scanf("%d", &num);
                if (isPalindrome(num)) {
                    printf("%d is a palindrome.\n", num);
                } else {
                    printf("%d is not a palindrome.\n", num);
                }
                break;
            case 4:
                printf("Enter a number to check for perfect number: ");
                scanf("%d", &num);
                if (isPerfect(num)) {
                    printf("%d is a perfect number.\n", num);
                } else {
                    printf("%d is not a perfect number.\n", num);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
