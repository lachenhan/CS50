#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int s;
    do
    {
        s = get_int("Start size(positive integer: ");
    }
    while (s < 9);
    
    // TODO: Prompt for end size
    int e;
    do 
    {
        e = get_int("End size (positive integer: ");
    }
    while (e < s);


    // TODO: Calculate number of years until we reach threshold

    int n = 0;
    while(s < e)
    {
        s = s + (s/3) - (s/4);
        n += 1;
    }

    // TODO: Print number of years
    printf("The number is %i\n", n);
}
