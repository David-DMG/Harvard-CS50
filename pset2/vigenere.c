#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    string cipher = argv[1];
    int check_cipher;
    string plaintxt;
    int plaintxt_char;
    int cipher_key;
    int ciphered;
        
    if (argc != 2)
    {
        printf("Error, need single word cypher\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            check_cipher = cipher[i];
            if (isalpha(check_cipher) == 0)
            {
                printf("Error! only letter can be used in cypher\n");
                return 1;
            }
        }
        
        printf("plaintext: ");
        plaintxt = get_string();
        printf("ciphertext: ");
        
        for (int i = 0, j = 0, n = strlen(plaintxt), m = strlen(argv[1]); i < n; j++, i++)
        {   
            cipher_key = cipher[((j) % m)];
            plaintxt_char = plaintxt[i];
            
            if (isupper(cipher_key))
            {
                cipher_key = cipher_key - 65;
            }
            else if (islower(cipher_key))
            {
                cipher_key = cipher_key - 97;
            }
            
            if (isalpha(plaintxt_char))
            {
                if (islower(plaintxt_char))
                {
                    ciphered = (((plaintxt_char - 97) + (cipher_key)) % 26 + 97);
                    printf("%c", ciphered);
                }
                    
                else if (isupper(plaintxt_char))
                {
                    ciphered = (((plaintxt_char - 65) + (cipher_key)) % 26 + 65);
                    printf("%c", ciphered);
                }
            }
            
            else
            {
            j = j - 1;
            printf("%c", plaintxt_char);
            }
        }
    printf("\n");
    }
}