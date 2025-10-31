#include<stdio.h>
#include<stdlib.h>
struct node
{
 	int data;
	struct node*link;
};
struct node*header;
/*void createnode()
{
	struct node*newnode;
  	newnode=(struct node*)malloc(sizeof(struct node));
  	newnode->data=item;
  	newnode->link=NULL;
  	header=newnode;
}*/
void insertAtfront(int item)
{
// 	struct *node newnode;
 //	newnode=createNode
  	struct node*newnode;
  	newnode=(struct node*)malloc(sizeof(struct node));
  	newnode->data=item;
  	newnode->link=NULL;
  	if(header==NULL)
   	{
     	header=newnode;
    }
 	else
  	{
     	newnode->link=header;
    	header=newnode;
   	}
}
void traverselist()
{
  	struct node*ptr;
  	ptr=header;
		while(ptr!=NULL)
 	 {
   		 printf("%d\n",ptr->data);
   		 ptr=ptr->link;
 	 }
}
void insertAtend(int item)
{
		struct node*newnode;
  	newnode=(struct node*)malloc(sizeof(struct node));
  	newnode->data=item;
  	newnode->link=NULL;
  	if(header==NULL)
   	{
    	 header=newnode;
   	}
  	else
  	{
   		struct node*ptr;
    	ptr=header;
   	
			while(ptr->link!=NULL)
  		{
    		ptr=ptr->link;
    	}
    	ptr->link=newnode;
    	newnode->link=NULL;
    	newnode->data=item;
   }
}
void insertAtany(int item,int key)
{
 	struct node *ptr,*ptr1;
 	while(ptr!=NULL&&ptr->data!=key)
 	{
 			ptr1=ptr;
 			ptr=ptr->link;
 	}
	if (ptr==NULL)   	
  {
     	printf("Key not found,Insertion not possible");
  }
  else
  {	
  	struct node *newnode;
  	newnode=(struct node*)malloc(sizeof(struct node));
  	newnode->data=item;
  	newnode->link=ptr;
  	ptr1->link=newnode;
 	}
}

void deleteAtfirst()
{
 struct	node*ptr;
 if(ptr==NULL)
 {
 	printf("Deletion not possible");
 }
 else
 {
 	ptr=header;
 	header=header->link;
 	free(ptr);
 }
}
int main()
{
 //header=NULL;
// createnode();
// printf("Data:%d\n",*header);
insertAtfront(10);
insertAtfront(20);
insertAtfront(30);
insertAtfront(40);
insertAtend(22);
insertAtend(33);
insertAtend(44);
insertAtend(55);
insertAtany(96,44);
traverselist();
deleteAtfirst();
return(0); 
}
