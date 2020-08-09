#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


int main(int argc,char **argv)
{
  srand(time(NULL));
 
  int x,num;
  printf("How many passwords?\n");
  scanf("%d",&num);
  for(int j=0;j<num;j++)
  {
  for(int i=0;i<8;i++)
  {
    x=rand()% (122-48) + 48;
   while((x>57 && x<65) || (x>90 && x<97))
    {
      x=rand()% (122-48) + 48;
    }
    putchar(x);
   

  }
 printf("\n");
  }





return EXIT_SUCCESS;
}
