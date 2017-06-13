#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET 26

int main(int argc, string argv[])
{
    //declare variables
    string cipher = argv[1];
    int check_cipher;
    string plaintxt;
    int plaintxt_char;
    int cipher_key;
    int encrypted_char;
    
    //error if no cypher is provided or if cypher is multiple strings
    if (argc != 2)
    {
        printf("Error, need single word cypher\n");
        return 1;
    }
    else
    {
        //error is a character of string is not a valid letter
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            check_cipher = cipher[i];
            if (isalpha(check_cipher) == 0)
            {
                printf("Error! only letter can be used in cypher\n");
                return 1;
            }
        }
        //asking for txt to encrypt
        printf("plaintext: ");
        plaintxt = get_string();
        printf("ciphertext: ");
        
        for (int i = 0, j = 0, n = strlen(plaintxt), m = strlen(argv[1]); i < n; j++, i++)
        {   
            //to rotate the cipher
            cipher_key = cipher[((j) % m)];
            plaintxt_char = plaintxt[i];
            
            //keep case, change cipher key from ascii value to alpha base
            if (isupper(cipher_key))
            {
                cipher_key = cipher_key - 'A';
            }
            else if (islower(cipher_key))
            {
                cipher_key = cipher_key - 'a';
            }
            
            //keep case, change plaintxt char from ascii value to alpha base, apply cipher, % 26 to rotate through alphabet, return to ascii, print char
            if (isalpha(plaintxt_char))
            {
                if (isupper(plaintxt_char))
                {
                    encrypted_char = (((plaintxt_char - 'A') + (cipher_key)) % ALPHABET + 'A');
                    printf("%c", encrypted_char);
                }
                    
                else if (islower(plaintxt_char))
                {
                    encrypted_char = (((plaintxt_char - 'a') + (cipher_key)) % ALPHABET + 'a');
                    printf("%c", encrypted_char);
                }
            }

            //reuse cipher key char is not alpha, print unencrypted char
            else
            {
            j = j - 1;
            printf("%c", plaintxt_char);
            }
        }
    printf("\n");
    }
}