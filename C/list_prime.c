#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool is_prime(int number) {
    if (number <= 1) {
        return false; // 0 and 1 are not prime
    }

    int sqrt_num = sqrt(number);

    for (int i = 2; i <= sqrt_num; i++) {
        if (number % i == 0) {
            return false; // Number is divisible, not prime
        }
    }

    return true; // If no divisors found, the number is prime
}

int main() {
    int minimum;
    int maximum;
    do
    {
        minimum = get_int("Minimum: ");
        maximum = get_int("Maximum: ");
    }
    while (minimum > maximum);

    for (int i = minimum; i <= maximum; i++)
    {
        if (is_prime(i))
        {
            printf("%d\n", i);
        }
    }
}
