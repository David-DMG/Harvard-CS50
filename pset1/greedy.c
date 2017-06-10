#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    float change;
    int changed;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int coins = 0;
    
    printf("O hai! ");
    
    do
    {
    printf("How much change is owed?\n");
    change = get_float();
    }
    while (change < 0);

    changed = roundf(change * 100);

    while (changed >= quarter)
    {
        changed = changed - quarter;
        coins++;
    }
    while (changed >= dime)
    {
        changed = changed - dime;
        coins++;
    }
    while (changed >= nickel)
    {
        changed = changed - nickel;
        coins++;
    }
    while (changed >= penny)
    {
        changed = changed - penny;
        coins++;
    }
    printf("%i\n", coins);
    return 0;
}