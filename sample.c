#include<stdio.h>
#define max_size 5
int q[max_size],front=0,rear=0;

void	enqueue(int	item)
{
	if(rear>=max_size)
	{
		printf("Queue	is	full");
	}
	else
	 {
	     if(front=0,rear=0)
	       {
	         front=1;
	       }
	   
		rear=rear+1;
		q[rear]=item;
	 }
		printf("%d	is	pushed	successfully",item);
}
