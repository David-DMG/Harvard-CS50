#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Minutes: ");
    int minutes = get_int();
    
    if (minutes > 0)
    {
        int bottles = (128 * (1.5 * minutes) / 16);
        printf("Bottes: %d\n", bottles);
    }
    else
    {
        printf("Number must be positive!\n");
    }
}