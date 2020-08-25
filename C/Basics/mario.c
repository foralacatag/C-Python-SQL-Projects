#include <stdio.h>
#include <cs50.h>
 // set variables for height and string to display
int height, space, pyramid;
int main(void)
{

/*Set a condition to make sure user enters correct
format of information*/
do
{
  height=get_int("Enter height b/w 0-23 : ");
}
while (height<1 || height >23);
  

//Below is the loop for displaying the blocks
if (height>=1 ){
   if (height==1)
      {
        space=0;
      }
    else
      {
          space=height-1;
      }
    pyramid=1;
 for (int i=0; i<height; i++)
 {
     for (int s=0; s<space; s++)
     printf(" ");
     for ( int p=0; p<pyramid; p++)
     printf("#");

     //space between walls
     printf("  ");
     for (int p=0; p<pyramid; p++)
     printf("#");


     printf("\n");

     space--;
     pyramid++;
  }
      
}
else
{ 
  printf(""); 
      
}


}
