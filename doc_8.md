# Random Number Sorting Program
This is the seventh question of the assignment where we  generate a list of **N random integers** in the range `[1, 1000]` and sorts them using a user-selected sorting algorithm. The program also counts the number of **comparisons** and **swaps/assignments** performed during sorting.

# Data Structure
The program uses a **2D array (adjacency matrix)** to represent the weighted graph.The program uses a simple array to store the numbers.
```c 
int arr[N];
int sorted[N];


```
- arr[] stores the randomly generated numbers.
- sorted[] stores the sorted numbers separately so the original array remains unchanged.

## Functions Implemented

1. void swap(int *a, int *b) 
```c

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
    swaps++;
}
```

Swaps two numbers and increments the global swaps counter.

2. void bubbleSort(int arr[], int n)
```c
void bubbleSort(int arr[], int n) {
    comparisons = swaps = 0;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            comparisons++;
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

```
Sorts the array using Bubble Sort and counts comparisons and swaps.

3. void selectionSort(int arr[], int n)
```c
void selectionSort(int arr[], int n) {
    comparisons = swaps = 0;
    for(int i=0;i<n-1;i++) {
        int min = i;
        for(int j=i+1;j<n;j++) {
            comparisons++;
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min != i) swap(&arr[i], &arr[min]);
    }
}

```
Sorts the array using Selection Sort and counts comparisons and swaps.

4. void insertionSort(int arr[], int n)
```c
void insertionSort(int arr[], int n) {
    comparisons = swaps = 0;
    for(int i=1;i<n;i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key) {
            comparisons++;
            arr[j+1] = arr[j];
            swaps++;
            j--;
        }
        if(j>=0) comparisons++; 
        arr[j+1] = key;
    }
}
```
Sorts the array using Insertion Sort and counts comparisons and swaps.

5. void merge(int arr[], int l, int m, int r) 
```c
void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i] = arr[l+i];
    for(int i=0;i<n2;i++) R[i] = arr[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        comparisons++;
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        swaps++;
    }
    while(i<n1) arr[k++] = L[i++], swaps++;
    while(j<n2) arr[k++] = R[j++], swaps++;
}
```
Forms the core merging step of Merge Sort.

6. void mergeSort(int arr[], int l, int r)
```c
void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
```
Sorts the array using Merge Sort. Assignments during merging are counted as swaps.

7. void printArray(int arr[], int n) 
```c
void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```
Prints all elements of the array.

## Main Function Overview

```c


int main() {
    int N;
    printf("Enter number of integers: ");
    scanf("%d",&N);

    if(N<=0 || N>MAX) {
        printf("Invalid input! N should be 1-%d\n",MAX);
        return 1;
    }

    int arr[N];
    srand(time(0));

    // Generate random numbers
    for(int i=0;i<N;i++) arr[i] = rand()%1000 + 1;

    printf("\nRandom numbers:\n");
    printArray(arr,N);

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    int choice;
    scanf("%d",&choice);

    // Copy array to sort
    int sorted[N];
    for(int i=0;i<N;i++) sorted[i] = arr[i];

    // Sort based on choice
    switch(choice) {
        case 1: bubbleSort(sorted,N); printf("\nBubble Sort applied.\n"); break;
        case 2: selectionSort(sorted,N); printf("\nSelection Sort applied.\n"); break;
        case 3: insertionSort(sorted,N); printf("\nInsertion Sort applied.\n"); break;
        case 4: comparisons=swaps=0; mergeSort(sorted,0,N-1); printf("\nMerge Sort applied.\n"); break;
        default: printf("Invalid choice!\n"); return 1;
    }

    printf("\nSorted numbers:\n");
    printArray(sorted,N);

    printf("\nTotal comparisons: %lld\n",comparisons);
    printf("Total swaps/assignments: %lld\n",swaps);

    return 0;
}
```
### Workflow of main function
- User inputs the number of integers N.
- User inputs the number of integers N.
- Sorting algorithm is chosen by the user.
- The chosen algorithm is applied to a copy of the array (sorted[]).
- Numbers before and after sorting are displayed.
- Total comparisons and swaps/assignments are displayed.


## Sample Output
<img width="601" height="421" alt="Image" src="https://github.com/user-attachments/assets/33c7327d-fa07-46a6-bea4-312f3c27943b" />

