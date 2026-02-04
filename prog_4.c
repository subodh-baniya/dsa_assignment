#include<stdio.h>
#include<stdlib.h>
//structure of each node
struct Node{
    int info;
    struct Node* prev;
    struct Node* next;
};

//create a new node
struct Node* create(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->info=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

//insert node at the end
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

//search the node
struct Node* searchNode(struct Node* head, int key) {
    while (head != NULL) {
        if (head->info == key)
            return head;
        head = head->next;
    }
    return NULL;
}

//insert after a given node
void insertAfter(struct Node* givenNode, int value) {
    if (givenNode == NULL) return;

    struct Node* newNode = create(value);

    newNode->next = givenNode->next;
    newNode->prev = givenNode;

    if (givenNode->next != NULL)
        givenNode->next->prev = newNode;

    givenNode->next = newNode;
}

//delete a selected node
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

//display the list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->info);
        head = head->next;
    }
}

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