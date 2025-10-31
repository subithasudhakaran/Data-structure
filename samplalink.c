#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
};


struct node *header = NULL;

void insertAtfront(int item) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = header;
    header = newnode;
}


void traverselist() {
    struct node *ptr = header;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}


void insertAtend(int item) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;

    if (header == NULL) {
        header = newnode;
        return;
    }

    struct node *ptr = header;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newnode;
}


void insertAtany(int item, int key) {
    struct node *ptr = header;

    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key %d not found, insertion not possible.\n", key);
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = ptr->link;
    ptr->link = newnode;
}


void deleteAtfirst() {
    if (header == NULL) {
        printf("Deletion not possible, list is empty.\n");
        return;
    }

    struct node *ptr = header;
    header = header->link;
    free(ptr);
}
void 

int main() {
    insertAtfront(10);
    insertAtfront(20);
    insertAtfront(30);
    insertAtfront(40);

    insertAtend(22);
    insertAtend(33);
    insertAtend(44);
    insertAtend(55);

    insertAtany(96, 44); 

    printf("List after insertions:\n");
    traverselist();

    deleteAtfirst();

    printf("\nList after deleting first element:\n");
    traverselist();

    return 0;
}

