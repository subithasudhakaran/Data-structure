
#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
};

struct node *header = NULL; // Global head pointer

// Function to insert a node at the front
void insertAtfront(int item) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = header;
    header = newnode;
}

// Function to traverse and print the linked list
void traverselist() {
    struct node *ptr = header;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements:\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

// Function to insert a node at the end
void insertAtend(int item) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;

    if (header == NULL) {
        header = newnode;
        return;
    }

    struct node *ptr = header;
    while (ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = newnode;
}

// Function to insert a node before a given key
void insertAtany(int item, int key) {
    struct node *ptr = header, *ptr1 = NULL;

    while (ptr != NULL && ptr->data != key) {
        ptr1 = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key %d not found. Insertion not possible.\n", key);
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = ptr;

    if (ptr1 == NULL)
        header = newnode; 
    else
        ptr1->link = newnode;
}


void deleteAtfirst() {
    if (header == NULL) {
        printf("Deletion not possible. List is empty.\n");
        return;
    }

    struct node *ptr = header;
    header = header->link;
    free(ptr);
}

void deleteAtend() {
    if (header == NULL) {
        printf("Deletion not possible. List is empty.\n");
        return;
    }

    struct node *ptr = header, *ptr1 = NULL;

    while (ptr->link != NULL) {
        ptr1 = ptr;
        ptr = ptr->link;
    }

    if (ptr1 == NULL)
        header = NULL;
    else
        ptr1->link = NULL;

    free(ptr);
}

void deleteAtany(int key) {
    if (header == NULL) {
        printf("Deletion not possible. List is empty.\n");
        return;
    }

    struct node *ptr = header, *ptr1 = NULL;

    while (ptr != NULL && ptr->data != key) {
        ptr1 = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key %d not found. Deletion not possible.\n", key);
        return;
    }

    if (ptr1 == NULL)
        header = ptr->link; 
    else
        ptr1->link = ptr->link;

    free(ptr);
}
int main() 
{
do
	{
		int	item,choice,key;
		printf("\n1.InsertAtfront\n2.InsertAtend\n3.InsertAtany\n4.DeleteAtfirst\n5.DeleteAtend\n6.DeleteAtany\n7.Display\n8.exit\n");
		printf("Enter	your	choice:	");
		scanf("%d",&choice);
		switch(choice)
		{
			case	1:printf("Enter	the	element:");
							scanf("%d",&item);
							insertAtfront(item);
							break;
			case	2:printf("Enter	the	element:");
							scanf("%d",&item);
							insertAtend(item);
							break;
			case	3:printf("Enter	the	Element:");
							scanf("%d",&item);
							printf("Enter	the	key:");
							scanf("%d",&key);
							insertAtany(item,key);
							break;
			case	4:deleteAtfirst();
							break;
			case	5:deleteAtend();
							break;
			case	6:printf("Enter	the	Element	to	delete:");
							scanf("%d",&key);
							deleteAtany(key);
							break;
			case	7:traverselist();
							break;
			case	8:return(0);
			default:printf("Enter	the	correct	choice.");
							break;														
		}
}while(1);
return 0;
}

