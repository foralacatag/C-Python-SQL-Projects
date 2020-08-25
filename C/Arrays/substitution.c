/**
 * vigenere.c aim is to shift letters differently based on the entered cipher key.
 * Ceaser cipher is one bit key and vigenere is n bit key.
 *If you enter MOVSBF this is 6 bit key and your text will be divided into 6 bits chunks
 * ignoring other characters.Each element of chunk will be shifted with amount of corresponding cipherkey.
 *
 * Written by Fatma Orsun
 *
 * Encrypts text using a Vigenere n bit cipher key.
 */
#include <cs50.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Global variable definition - shift:amount of shift for corresponding letter
*key : keeps the index of cipher key element
*total : keeps the number of bits encrypted .
*chunk : keeps the length of vigenere cipher key. */

int key,shift, total,chunk;
char vigenere(string argv, char h); // Function to calulate
bool uniqueCharacters(string str) ;
string org="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{

    /* Reset all variables to 0*/
    key = 0;   
    shift = 0;      
    total = 0; 
    chunk = 0;
 
  


    /*Check for error-If no argument or more than one key enetered */
    if (argc < 2 || argc >3)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }


    /* Check/iterate for vigenere key for alphabetical characters */
    chunk  =  strlen(argv[1]);
    
    if (chunk<26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (!uniqueCharacters(argv[1]))
    {
          printf("characters.\n");
        return 1;
    }
        
    for (int j = 0; j < chunk; j++ )
    {
        if (!isalpha(argv[1][j]))
        {
          printf("Usage: ./vigenere key\n");
         return 1;
        }
    }


    // prompt user for text to encrypt
    // printf("plaintext: ");
    string text  =  get_string("plaintext: ");
    

    // encrypt text by using shifting key
    printf("ciphertext: ");
    
    for (int i = 0; i < strlen(text); i++)
    {
        /* Check only for alphabetical letter*/
       if (isalpha(text[i]))
        {
            //key =  total  %  chunk;
            if (islower(text[i]))
            {
            
                printf("%c", tolower(vigenere(argv[1], text[i])));
            }
            else if (isupper(text[i]))
            {
                printf("%c", toupper(vigenere(argv[1], text[i])));
            /* Check only for all other characters*/
            }
        }
        else
        {
            printf("%c", text[i]);
        }
        
        
    }
    printf("\n");

    return 0;
}
/* Calculate Vigenere shift amount */
char vigenere(string argv, char h)

{
    int index =0;
    
     if ( islower(h) )
    {
       index = strchr(org,toupper(h))-org;
        //printf("%d", index);
         //return argv[index];
         }
         else{
   
     index = strchr(org,h)-org;
        //   printf("%d", index);
         }
          return argv[index];
       
   //  return argv[index];
   
}
  
bool uniqueCharacters(string str) 
{ 
  
    // If at any time we encounter 2 
    // same characters, return false 
    for (int i = 0; i < strlen(str) - 1; i++) 
    { 
        for (int j = i + 1; j < strlen(str); j++) 
        { 
            if (str[i] == str[j]) 
            { 
                return false; 
            } 
        } 
    } 
  
    // If no duplicate characters encountered, 
    // return true 
    return true; 
} 
