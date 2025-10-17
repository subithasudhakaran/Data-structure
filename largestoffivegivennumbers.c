#include<stdio.h>
int main()
{
 int i=1,num;
 int largest=0;
 while(i<=5)
  {
   printf("enter a number");
   scanf("%d",&num);
   if(num>largest)
   {
   	largest=num;
   }
   i+=1;	
   }
   printf("the	largest	number	is%d",largest);
return 0;
}

