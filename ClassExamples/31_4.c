// Algorithm for TOH

#include <stdio.h>

// Function to perform Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case: only one disk to move
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary, using destination as auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Move the nth disk from source to destination
    printf("Move disk %d from peg %c to peg %c\n", n, source, destination);
    
    // Move n-1 disks from auxiliary to destination, using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    // Input the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Solve Tower of Hanoi
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
