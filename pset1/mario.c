#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    
    for (int rows = 0; rows < height; rows = rows + 1)
    {
        for (int space = height - rows; space > 1; space = space - 1)
        {
            printf(" ");
        }
        for (int hash = height - rows; hash < height + 2; hash = hash + 1)
        {
            printf("#");
        }
        printf("\n");
    }
}