#include <cs50.h>
#include <stdio.h>
#include <math.h>

int calculateDigits(long long number);
int firstTwoDigits(long long number);
int calculateChecksum(long long number);
int main(void)
{
    //prompt for input
    long long n;
    do
    {
        n = get_long("Please type your card number: ");
    }
    while (n < 1);

    //check credit card type and print out
    int nr_digits = calculateDigits(n);
    int fist2d= firstTwoDigits(n);


    //Amex has 15-digits and start with 34 or 37
    if (nr_digits == 15 && (fist2d ==34 || fist2d == 37))
    {
        printf("America Express Card\n");
    }
    //Master card 16-digits and start with 51, 52, 53, 54, or 55
    else if (nr_digits == 16 && (fist2d >= 51 && fist2d <= 55))
    {
        printf("Master Card\n");
    }
    //Visa card 13 or 16-digits and start with 4
    else if ((nr_digits == 13 || nr_digits == 16) && ((fist2d / 10)  == 4))
    {
        printf("Visa Card\n");
    }
    else
    {
        printf("Invalid\n");
    }


    //check card number checksum
    int checksum = calculateChecksum(n);
    printf("The checksum is: %d\n", checksum);
}

int calculateDigits(long long number)
{
    int digits = 0;
    long long n = number;

    // Count the number of digits
    while (n > 0) {
        n /= 10;
        digits++;
    }
    return digits;
}

int firstTwoDigits(long long number)
{
    int digits = calculateDigits(number);

    // Calculate the divisor
    double divisor = pow(10, (digits - 2));

    // Extract the first two digits
    return number / divisor;
}



int calculateChecksum(long long number) {
    int sum = 0;
    int isSecond = 0; // Flag to track every other digit

    while (number > 0) {
        int digit = number % 10; // Get the last digit
        number /= 10; // Remove the last digit

        if (isSecond) {
            digit *= 2; // Double the digit if it's every other digit
            if (digit > 9) {
                digit -= 9; // Subtract 9 if the doubled digit is more than 9
            }
        }

        sum += digit; // Add the digit (or modified digit) to the sum
        isSecond = !isSecond; // Flip the flag for every other digit
    }

    return sum;
}
