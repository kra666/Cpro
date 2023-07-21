//
// Created by fang on 2023/7/20.
//

#include "Counting.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




//计数排序(优化后)
void CountSort(int* arr, int n)
{
    //找到序列中的最大值和最小值
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    int range = max - min + 1;//开辟空间的数量
    int* countArr = (int*)malloc(sizeof(int)*range);//开辟空间
    //初始化数组全部为0
    memset(countArr, 0, sizeof(int)*range);
    //开始计数
    for (int i = 0; i < n; i++)
    {
        countArr[arr[i]-min]++;
    }

    //开始排序
    int j = 0;
    for (int i = 0; i < range; i++)
    {
        while (countArr[i]--)
        {
            arr[j] = i + min;
            j++;
        }
    }

    free(countArr);
}

void Print(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Counting_test()
{
    int arr[] = { -5,8,5,4,6,8,9,7,2,3,4,5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    CountSort(arr, n);
    printf("计数： ");
    Print(arr, n);

}








/*

void print_arr(int *arr, int n) {
    int i;
    printf("%d", arr[0]);
    for (i = 1; i < n; i++)
        printf(" %d", arr[i]);
    printf("\n");
}

void counting_sort(int *ini_arr, int *sorted_arr, int n) {
    int *count_arr = (int *) malloc(sizeof(int) * 100);
    int i, j, k;
    for (k = 0; k < 100; k++)
        count_arr[k] = 0;
    for (i = 0; i < n; i++)
        count_arr[ini_arr[i]]++;
    for (k = 1; k < 100; k++)
        count_arr[k] += count_arr[k - 1];
    for (j = n; j > 0; j--)
        sorted_arr[--count_arr[ini_arr[j - 1]]] = ini_arr[j - 1];
    free(count_arr);
}

int Counting_func(int argc, char **argv) {
    int n = 10;
    int i;
    int *arr = (int *) malloc(sizeof(int) * n);
    int *sorted_arr = (int *) malloc(sizeof(int) * n);
    srand(time(0));
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;
    printf("ini_array: ");
    print_arr(arr, n);
    counting_sort(arr, sorted_arr, n);
    printf("sorted_array: ");
    print_arr(sorted_arr, n);
    free(arr);
    free(sorted_arr);
    return 0;
}*/
