//
// Created by fang on 2023/7/20.
//

#include "Bubble.h"
#include <stdio.h>



void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int bubble_func() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, len);
    int i;
    printf("冒泡： ");
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}