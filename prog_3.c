#include <stdio.h>
#include <stdlib.h>
//structure of the each node
struct Node{
    int info;
    struct Node *next;
};

//inserting the node
struct Node *insert(struct Node *head, int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

//reverse print of list
void reversePrint(struct Node *head){
    if (head == NULL){
        return;
    }
    reversePrint(head->next);
    printf("%d ", head->info);
}

int main(){
    struct Node *head = NULL;
    int n;
    printf("Enter the number of data you want to see in reverse: \n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements for the list\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        head = insert(head, a[i]);
    }

    printf("\nReverse Traversal: ");
    reversePrint(head);

    return 0;
}