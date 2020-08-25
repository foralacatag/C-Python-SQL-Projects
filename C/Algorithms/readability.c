/*
 * Written by Fatma Orsun
 *
 * computes the approximate grade level needed to comprehend some text, per the below..
 */

#include <cs50.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, string argv[])
{

  // prompt user for text to encrypt

    string str = get_string("Text: ");

    // encrypt text by using shifting key

    int i = 0;
    int state=0;
    float wc = 0;  // word count
    float lc = 0;  // letter count
    float sc=0;    //settence count

    // Scan all characters one by one
    while (i < strlen(str) )
    {
        // If next character is a separator, set the
        // state as
        if (str[i+1]== ' ' || str[i+1] == '\n' || str[i+1] == '\t')
        {
             lc--;
             state=0;
        }
        else if (str[i+1]== ',' )
        {
            lc--;
        }
        else if (str[i+1]== '.' || str[i+1] == '?' || str[i+1] == '!')
        {

             sc++;
             lc--;
           



        }

        // If next character is not a word separator and
        // state is OUT, then set the state as IN and
        // increment word count
        else if (state == 0)
        {
            state = 1;
            wc++;
        }

        // Move to next character
        lc++;
        i++;

    }
   // lc=lc-sc;
    

    int index = round(0.0588 * (lc/wc)*100 - 0.296 * (100*(sc/wc) )- 15.8);


     if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index  < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }





}

