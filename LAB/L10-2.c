#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[smallest])
        smallest = left;
    if (right < n && arr[right] > arr[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void insert(int arr[], int *n, int value)
{
    if (*n == 100)
    {
        printf("Heap is full\n");
        return;
    }
    *n += 1;
    int i = *n - 1;
    arr[i] = value;
    while (i != 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void deleteElement(int arr[], int *n, int value)
{
    if (*n <= 0)
    {
        printf("Heap is empty\n");
        return;
    }
    int i;
    for (i = 0; i < *n; i++)
    {
        if (arr[i] == value)
            break;
    }
    if (i == *n)
    {
        printf("Element %d not in the heap.\n", value);
        return;
    }
    arr[i] = arr[*n - 1];
    *n -= 1;
    heapify(arr, *n, i);
}
void printHeap(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int heap[100];
    int hSize = 0;
    int n=0,temp,del;
    printf("Enter heap size: ");
    scanf("%d",&n);
    printf("Enter heap elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        insert(heap,&hSize,temp);
    }
    printf("After inserting:\n");
    printHeap(heap, hSize);
    printf("Enter element to delete: ");
    scanf("%d",&del);
    deleteElement(heap,&hSize,del);
    printf("After deleting %d: ",del);
    printHeap(heap,hSize);
    return 0;
}
