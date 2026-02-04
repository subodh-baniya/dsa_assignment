# Reverse Traversal of a Singly Linked List
This is the third question of the assignment where we have to reverse the elments of the linked list.

## Data Structure
The program uses  **structure** for implementation of the singly linked list.

```c 
struct Node{
    int info;
    struct Node *next;
};
```
- info stores data.
- next pointer stores the address of sucessor node.

## Functions Implemented

1. struct Node *insert(struct Node *head, int value)
```c
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
```

Adds a new node at the end of the linked list.

2. void reversePrint(struct Node *head)
```c
void reversePrint(struct Node *head){
    if (head == NULL){
        return;
    }
    reversePrint(head->next);
    printf("%d ", head->info);
}
```
Prints the linked list in reverse order using recursion.

## Main Function Overview

```c
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
```
### Workflow of main function
- User enters number of elements.
- Elements are read and inserted into the linked list.
- reversePrint() is called.
- Elements are displayed in reverse order.

## Sample Output
<img width="531" height="170" alt="Image" src="https://github.com/user-attachments/assets/361bf392-1a69-4474-bd82-f8fa547528d6" />

