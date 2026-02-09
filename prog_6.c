#include <stdio.h>
#define MAX 100

// Max Heapify
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

// Min Heapify
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

// Build Max Heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Build Min Heap
void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Print Heap
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

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
