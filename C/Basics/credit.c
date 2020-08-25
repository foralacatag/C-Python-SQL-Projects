#include <stdio.h>

#include <cs50.h>
#include <string.h>
#include <math.h>

int main()
{

    long long cnumber ;

    do
    {
        cnumber = get_long_long("Number: ");
    }
    while (cnumber <= 0);

    long long digits = cnumber;

    int snumber = 0;

    do
    {
        digits = digits / 10;
        snumber++;
    }

    while (digits > 0);

    if ((snumber != 13) && (snumber != 15) && (snumber != 16))    
    {
        printf("INVALID\n");
        return 0;

    }

    int list[snumber];
     for (int i = 0; i < snumber; i++)
    {
        list[i] = 0;
    }

    for (int i = 0; i < snumber; i++)
    {
        list[snumber - i - 1 ] = cnumber % 10;
        cnumber = cnumber / 10;
       //   printf("%d ", list[i]);
    }

    // initialize variables for checksum
    int total = 0;
    int x = 1;
    int in = 0;
    int multiple[8]={0,0,0,0,0,0,0,0};


    do
    {
        total = total + list[snumber-x];
        multiple[in] = list[(snumber - 1 - x)] * 2;
        in++;
        x = x + 2;
    }
    while ( x <= snumber );
    



    for (int i = 0; i < in; i++)
    {
        int mul_total = (multiple[i] % 10) + (multiple[i] / 10);
        total = total + mul_total;
    }


    if ((total % 10) == 0)
    {
        if (snumber == 16)
        {
            if (list[0] == 4)
            {
                printf("VISA\n");
            }
            else if (list[0]==5)
            {
                if ( (list[1] == 1 )|| (list[1] == 2) || (list[1] == 3 )|| (list[1] == 4 )|| (list[1] == 5))
                {
                    printf("MASTERCARD\n");
                    
                }
                else
                { 
                    printf("INVALID\n");
                }  
            }
            
        }
        else if (snumber == 15 && list[0] == 3) 

        {  
            if  (list[1] == 4 || list[1] == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {   
            printf("INVALID\n");
            
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}