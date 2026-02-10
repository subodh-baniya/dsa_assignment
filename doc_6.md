# Building Min Heap and Max Heap from an Array
This is the sixth question of the assignment where we construct a Min Heap and a Max Heap from an unsorted array using the heapify method.
## Data Structure
The program uses a **simple array** to represent the heap.

```c 
#define MAX 100
int arr[MAX];

```
- arr[] stores all the elements of the heap in a linear form

## Functions Implemented

1. void maxHeapify(int arr[], int n, int i) 
```c
void maxHeapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}
```

Ensures the subtree rooted at i satisfies Max Heap property.

2. void minHeapify(int arr[], int n, int i)
```c
void minHeapify(int arr[], int n, int i) {
    int smallest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2; 

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeapify(arr, n, smallest);
    }
}

```
Ensures the subtree rooted at i satisfies Min Heap property.


3. void buildMaxHeap(int arr[], int n)
```c
void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
```
Builds the Max Heap from an unsorted array.

4. void buildMinHeap(int arr[], int n)
```c
void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

```
Builds the Min Heap from an unsorted array.

5. void printHeap(int arr[], int n) 
```c
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
```
Prints the heap elements.

## Main Function Overview

```c

int main() {
    int n;
    int arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    printHeap(arr, n);

    buildMinHeap(arr, n);
    printf("Min Heap: ");
    printHeap(arr, n);

    return 0;
}


```
### Workflow of main function
- User enters the number of elements.
- User enters the unsorted array.
- Max Heap is constructed and printed.
- Min Heap is constructed and printed.


## Sample Output
<img width="357" height="264" alt="Image" src="https://github.com/user-attachments/assets/e678744a-7828-4949-b170-5eef709effd6" />

