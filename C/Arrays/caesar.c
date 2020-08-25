/**
 * caesar.c
 *
 * Written by Fatma Orsun
 *
 * Encrypts text using a Caesar cipher key.
 */
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int shift = 0;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // ensure key is non-negative
    shift = atoi(argv[1]);

    if (shift < 0)
    {
        printf("Key must be a non-negative integer.\n");
        return 1;
    }
   
    // prompt user for text to encrypt
    
    string text = get_string("plaintext:\n");

    // encrypt text by using shifting key
   
    printf("ciphertext: ");

    for (int i = 0;  i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", ((text[i] - 'A') + shift) % 26 + 'A');
        }
        else if (islower(text[i]))
        {
            printf("%c", ((text[i] - 'a') + shift) % 26 + 'a');

        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");

    return 0;
}
