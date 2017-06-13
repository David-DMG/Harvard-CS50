#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET 26

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        // error msg and return 1
        printf("Error! Must enter a command line cipher key\n");
        return 1;
    }
        
    //declaring variables
    int cipher_key = atoi(argv[1]);
    string plaintxt;
    int encrypted_char;
    int plaintxt_char;
    
    if (cipher_key < 1)
    {
        // error msg and return 1
        printf("Error! Your cipher key must be a non-negative interger\n");
        return 1;
    }
    
    // promt for txt to encrypt
    printf("plaintext: ");
    plaintxt = get_string();
    printf("ciphertext: ");
        
    // loop through characters txt to encrypt
    for (int i = 0, n = strlen(plaintxt); i < n; i++)
    {
        plaintxt_char = plaintxt[i];
        
        //keep case, change ascii to alpha base(i.e a=0, b=1 ...), apply caesat cipher, % 26 to rotate through alphabet, return to ascii, print
        if (isalpha(plaintxt_char))
        {
            if (islower(plaintxt_char))
            {                 
                encrypted_char = ((((plaintxt_char - 'a') + cipher_key) % ALPHABET) + 'a');
                printf("%c", encrypted_char);
            }
            else if (isupper(plaintxt_char))
            {
                encrypted_char = ((((plaintxt_char - 'A') + cipher_key) % ALPHABET) + 'A');
                printf("%c", encrypted_char);
            }
        }
        //if plaintxt_char is not alhpa print char unencrypted
        else
        {
            printf("%c", plaintxt_char);
        }
    }
    //end with a new lines
    printf("\n");
    return 0;
}