#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{   
    //get full name string
    string full_name = get_string();
    
    //print first letter of initals in upper case
    printf("%c", toupper(full_name[0]));
    
    //loop going through each character in full name string
    for (int i = 0, n = strlen(full_name); i < n; i++)
    {
        //check if loop finds a space
        if (i > 0 && full_name[i] == ' ')
        {
            //print char after space, in upper case
            printf("%c", toupper(full_name[i+1]));
        }
    }
    printf("\n");
}