//
// Created by fang on 2023/7/21.
//


#include "Heap.h"
#include <stdio.h>

/*
void H(int pInt[7], int size);

void Heapify(int *arr, int m, int size)
{
    int i, tmp;
    tmp = arr[m];
    for (i = 2 * m; i <= size; i *= 2) {
        if (i + 1 <= size && arr[i] < arr[i+1]) {
            i++;
        }
        if (arr[i] < tmp) {
            break;
        }
        arr[m] = arr[i];
        m = i;
    }
    arr[m] = tmp;
}

void BuildHeap(int *arr, int size)
{
    int i;
    int n;
    for (i = n / 2; i > 0; i--) {
        Heapify(arr, i, size);
    }
}

void swapNum(int *arr, int i, int j)
{
    int tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void HeapSort(int *arr, int size)
{
    int i;
    BuildHeap(arr, size);
    for (i = size; i > 1; i--) {
        swapNum(arr, 1, i);
        Heapify(arr, 1, i - 1);
    }
}

int Heap_test(){

    int arr[7] = {2, 32, 12, 72, 92, 62, 22};
    int size = sizeof(arr) / sizeof(arr[0]);

    HeapSort(arr, size);

    printf("\n堆排序: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;

}
//测试结果少了32，多了90这个元素
 */


/*------------------------------------------------------优化代码----------------------------------------------------------------*/

#include <stdio.h>


void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest!= i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Driver code
int Heap_test() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("\n堆排: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
