#include <cs50.h>
#include <stdio.h>

int main(void)
{
// get size
int n;
do
{
    n = get_int("Size: ");
}
while(n < 1);
//build steps
for(int i = 0; i < n; i++)
{
    for(int j = 0; j < (n - i - 1); j++)
    {
        printf(".");
    }
    for(int x = 0; x < (i + 1) ; x++)
    {
        printf("#");
    }
    printf(".");
    for(int x = 0; x < (i + 1) ; x++)
    {
        printf("#");
    }
    for(int j = 0; j < (n - i - 1); j++)
    {
        printf(".");
    }
    printf("\n");
}
}
