#include <stdio.h>
#include <math.h>

int isArmstrong(int num);

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}

int isArmstrong(int num) {
    int originalNum, remainder, n = 0, result = 0;

    originalNum = num;

    // Find the number of digits in the given number
    while (num != 0) {
        num /= 10;
        ++n;
    }

    // Calculate the result by summing the nth power of each digit
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    // Check if the result is equal to the original number
    if (result == originalNum) {
        return 1; // It's an Armstrong number
    } else {
        return 0; // It's not an Armstrong number
    }
}
