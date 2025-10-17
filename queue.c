#include<stdio.h>
#define max_size 5
int q[max_size-1],front=-1,rear=-1;

void	enqueue(int	item)
{
	if(rear>=max_size)
	{
		printf("Queue	is	full");
	}
	else if(front=0,rear=0)
	 {
	  front=1;
	 }
  else
  {	   
		rear=rear+1;
		q[rear]=item;
	 }
		printf("%d	is	inserted	successfully",item);
}
void	dequeue(int item)
{
	if(front<1)
	{
		printf("Queue is	empty");
	}
	else
	{
	  item=q[front];
		printf("The deleted elemet	is	%d\n",item);
	}
  if(front=rear)	
   {
     front=rear=0;
   }
   else
   {
     front=front+1;
   } 
}	
void	display()
{
	if(front==-1)
	{
		printf("Queue	is	empty");
		return;
	}
	for(int	i=0;i<=front;i++)
	{
		printf("%d ",q[i]);

	}
	printf("\n");
}	
int	main()
{
	do
	{
		int	item,choice;
		printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		printf("Enter	your	choice:	");
		scanf("%d",&choice);
		switch(choice)
		{
			case	1:printf("Enter	the	element:");
							scanf("%d",&item);
							enqueue(item);
							break;
			case	2:dequeue(item);
							break;
			case	3:display();
							break;
			case	4:return(0);
			default:printf("Enter	the	correct	choice.");
							break;														
		}
	}while(1);
return(0);
}
		
