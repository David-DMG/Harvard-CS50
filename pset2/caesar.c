#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
        {
        // return 1 and error msg for no key
        printf("You forgot to enter the encryption key!\n");
        return 1;
        }
        
    //declaring variables
    int key = atoi(argv[1]);
    string plaintxt;
    int cyphered;
    int letter;
    
    if (key < 1)
    {
        // return 1 and error msg for -ve key
        printf("Your encryption key must be a non-negative interger!\n");
        return 1;
    }
    
    else if (argc == 2)
    {
        // promt for txt to encrypt
        printf("plaintext: ");
        plaintxt = get_string();
        printf("ciphertext: ");
        
        // loop for cycling though characters of string 'plaintxt'
        for (int i = 0, n = strlen(plaintxt); i < n; i++)
        {
            //assigning 'i'th character variable
            letter = plaintxt[i];
            
            //if its a letter
            if (isalpha(letter))
            {
                //if its lower case encrypt 'letter' using key, use %26 to roll over numbers is 26 range, and then apply to lower case ascii range
                if (islower(letter))
                {
                cyphered = (((letter - 97 + key) % 26) + 97);
                printf("%c", cyphered);
                }
                //if its upper case encrypt 'letter' using key, use %26 to roll over numbers is 26 range, and then apply to upper case ascii range
                else if (isupper(letter))
                {
                cyphered = (((letter - 65 + key) % 26) + 65);
                printf("%c", cyphered);
                }
            }
            //if not alhpa print the letter unencrypted
            else
            {
                printf("%c", letter);
            }
        }
        printf("\n");
        return 0;
    }
}