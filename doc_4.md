# Reverse Traversal of a Singly Linked List
This is the fourth question of the assignment where we have to implement a doubly linked list with basic operations: insertion at the end, insertion after a given node, deletion of a node, and display of the list.

## Data Structure
The program uses  **structure** for implementation of the doubly linked list.

```c 
struct Node{
    int info;
    struct Node* prev;
    struct Node* next;
};
```
- info stores data.
- next pointer stores the address of sucessor node.
- prev points to the previous node.

## Functions Implemented

1. struct Node* create(int value)
```c
struct Node* create(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->info=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
```

Creates a new node with the given value.

2. struct Node* insertEnd(struct Node* head, int value)
```c
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = create(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}
```
Inserts a new node at the end of the doubly linked list.

3. void insertAfter(struct Node* givenNode, int value)
```c
void insertAfter(struct Node* givenNode, int value) {
    if (givenNode == NULL) return;

    struct Node* newNode = create(value);

    newNode->next = givenNode->next;
    newNode->prev = givenNode;

    if (givenNode->next != NULL)
        givenNode->next->prev = newNode;

    givenNode->next = newNode;
}
```
Inserts a new node with the given value immediately after the specified node.

4. struct Node* searchNode(struct Node* head, int key)
```c
struct Node* searchNode(struct Node* head, int key) {
    while (head != NULL) {
        if (head->info == key)
            return head;
        head = head->next;
    }
    return NULL;
}
```
Searches for a node containing the given key and returns its address. Returns NULL if not found.

5. void deleteNode(struct Node** head, struct Node* delNode)
```c 
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) return;

    if (*head == delNode)
        *head = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    free(delNode);
}
```
Deletes the specified node from the list and updates links of neighboring nodes.

6. void display(struct Node* head)
```c
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->info);
        head = head->next;
    }
}
```
Traverses and prints the linked list from head to end.

## Main Function Overview

```c

int main() {
    struct Node* head = NULL;
    int n, value, key, newValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Initial List: ");
    display(head);

    printf("\nEnter the node value after which to insert: ");
    scanf("%d", &key);
    struct Node* pos = searchNode(head, key);
    if (pos == NULL) {
        printf("Node %d not found.\n", key);
    } else {
        printf("Enter new value to insert after %d: ", key);
        scanf("%d", &newValue);
        insertAfter(pos, newValue);
        printf("List after insertion: ");
        display(head);
    }

    printf("\nEnter the node value to delete: ");
    scanf("%d", &key);

    struct Node* delNode = searchNode(head, key);
    if (delNode == NULL) {
        printf("Node %d not found.\n", key);
    } else {
        deleteNode(&head, delNode);
        printf("List after deletion: ");
        display(head);
    }
    return 0;
}
```
### Workflow of main function
- User enters the number of nodes.
- Nodes are inserted at the end of the list.
- Initial list is displayed.
- User specifies a node value after which a new node should be inserted.
- The list is updated and displayed.
- User specifies a node to delete.
- The node is deleted and the updated list is displayed.

## Sample Output
<img width="503" height="203" alt="Image" src="https://github.com/user-attachments/assets/71bc1c14-88bd-4c3a-9602-15a677623f77" />

