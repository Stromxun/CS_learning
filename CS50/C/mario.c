#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n > 8 || n < 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("#");
        for (int j = 1; j <= 2; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("#");
        printf("\n");
    }
    return 0;
}
