#include <cs50.h>
#include <stdio.h>
#include <string.h>

int collatz(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }

    // even number
    else if ( (n % 2) == 0)
    {
        return 1 + collatz(n / 2);
    }

    // odd number
    else
    {
        return 1 + collatz(3*n + 1);
    }
}



int main(void)
{
    int number;
    int steps;
    // Get input
    number = get_int("Enter positive number: ");

    if (number < 0)
    {
        printf("Input must be positive integer");
        return 1;
    }

    steps = collatz(number);
    printf("%i\n", steps);
    return 0;
}
