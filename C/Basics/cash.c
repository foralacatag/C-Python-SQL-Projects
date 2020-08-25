#include <stdio.h>
#include <cs50.h>
#include <math.h>
 // set variables for coins and money
    int coins, cents, total, remainde;
    int change[4] = {25, 10, 5, 1};
    float money;
int main(void)
{
    total=0;
    cents=0;
/*Set a condition to make sure user enters correct
format of information. $ amount between 0 to 50*/
do
{
    money = get_float("Enter Amount 0 to 50 for your change : ");
}
while (money < 0.0 || money > 50.00 );

//Convert entered amount into cents
cents= (int)roundf(money * 100);

//Calculate required change amount. List of Change is stored in an array
while  (cents>0)
{
    for (int i=0; i<4; i++) // Check for all the coins 25,10,5,1 in order in Change[] array
    {
        coins = coins + floor( cents/change[i]);
        cents = cents % change[i];
    }
};


 printf(" %i\n", coins);

}