#include<stdio.h>
int main()
{
	int i=0,avg,n;
	int sum;
	printf("enter the number");
	scanf("%d",&n);
	do
	{
		sum=i+sum;
		avg=sum/n;
		i+=1;
	}	while(i<=n);
printf("average	is%d",avg);
return	0;
}	
	
