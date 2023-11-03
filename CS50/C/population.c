#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        printf("Start size: ");
        scanf("%d", &start);
    }
    while (start < 9);
    // TODO: Prompt for end size
    int end;
    do
    {
        printf("End size: ");
        scanf("%d", &end);
    }
    while (end < start);
    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    while (start < end)
    {
        start = start + (int) (start / 3) - (int) (start / 4);
        year++;
    }
    // TODO: Print number of years
    printf("Years: %d", year);
    return 0;
}
