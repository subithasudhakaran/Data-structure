#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE	5
int	counter=0;
struct stack 
{
    int data;
    struct stack *link;
};

struct stack *TOP = NULL;
void push(int item)
{
    struct stack *newnode;
    newnode = (struct stack *)malloc(sizeof(struct stack));
    newnode->data = item;
    newnode->link = NULL;
		if(TOP==NULL)
		{
			TOP=newnode;
			
		}
		else
		{
			if(counter<MAX_SIZE)
			{
				newnode->link=TOP;
				TOP=newnode;
				counter=counter+1;
			}
			else
			{
					printf("Stack	is	full.");
			}
		}
}
void pop() 
{
		struct	stack	*ptr;
    if (TOP == NULL) 
    {
        printf("Deletion not possible. Stack is empty.\n");
    }
		else
		{
			ptr=TOP;
			TOP=TOP->link;
			free(ptr);
			printf("Successfully deleted.");
			
		}
}
void display()
 {
    struct stack *ptr;
    ptr=TOP;
    if (ptr == NULL)
    {
        printf("Stack	is empty.\n");
    }
    printf("Stack	elements:\n");
   	while (ptr != NULL) 
    {	
      printf("%d\n", ptr->data);
      ptr = ptr->link;
    }
   	
}

int main()
{
do
	{
		int	item,choice;
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("Enter	your	choice:	");
		scanf("%d",&choice);
		switch(choice)
		{
			case	1:printf("Enter	the	element:");
							scanf("%d",&item);
							push(item);
							break;
			case	2:pop();
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
					

