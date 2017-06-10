#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        // return 1 and error msg
        printf("Error: must enter a command line cipher key!\n");
        return 1;
    }
        
    //declaring variables
    int cipher_key = atoi(argv[1]);
    string plaintxt;
    int ciphered_char;
    int plaintxt_char;
    
    if (cipher_key < 1)
    {
        // return 1 and error msg
        printf("Error: Your cipher key must be a non-negative interger!\n");
        return 1;
    }
    
    // promt for txt to encrypt
    printf("plaintext: ");
    plaintxt = get_string();
    printf("ciphertext: ");
        
    // loop for cycling though characters of string 'plaintxt'
    for (int i = 0, n = strlen(plaintxt); i < n; i++)
    {

        plaintxt_char = plaintxt[i];
         
        //if its a plaintxt_char
        if (isalpha(plaintxt_char))
        {
            //if its lower case encrypt 'plaintxt_char' using cipher_key, use %26 to roll over numbers is 26 range, and then apply to lower case ascii range
            if (islower(plaintxt_char))
            {
            ciphered_char = (((plaintxt_char - 97 + cipher_key) % 26) + 97);
            printf("%c", ciphered_char);
            }
            //if its upper case encrypt 'plaintxt_char' using cipher_key, use %26 to roll over numbers is 26 range, and then apply to upper case ascii range
            else if (isupper(plaintxt_char))
            {
            ciphered_char = (((plaintxt_char - 65 + cipher_key) % 26) + 65);
            printf("%c", ciphered_char);
            }
        }
        //if not alhpa print the plaintxt_char unencrypted
        else
        {
            printf("%c", plaintxt_char);
            }
    }
    printf("\n");
    return 0;
}

