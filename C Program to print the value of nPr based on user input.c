#include <stdio.h>

/* This function calculates the factorial
 * of the passed number n and returns it
 */
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    // Loop to calculate the factorial of n
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to calculate nPr
unsigned long long nPr(int n, int r) {
    // If r is greater than n, nPr is 0
    if (r > n) return 0;

    // Calculate nPr using the formula: nPr = n! / (n-r)!
    return factorial(n) / factorial(n - r);
}

int main() {
    int n, r;
    
    // Prompt user to enter the value of n and r
    printf("Enter value of n: ");
    scanf("%d", &n); //store entered value in n
    printf("Enter value of r: ");
    scanf("%d", &r); //store entered value in r
    
    // Calculate nPr
    unsigned long long result = nPr(n, r);
    
    // Print the value of nPr
    printf("%dP%d = %llu\n", n, r, result);
    
    return 0;
}
