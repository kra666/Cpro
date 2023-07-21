//
// Created by fang on 2023/7/20.
//

#include "Insertion.h"
#include <stdio.h>
#include "time.h"


/*//单趟插入排序
void InsertSort(int* arr, int size)
{
    int i = 0;
    for (i = 1; i < size; i++)
    {
        int end = i;
        int temp = arr[end];	//记录待排数值
        while (end > 0)
        {
            if (arr[end-1] > temp)	//若前一个数大于待排数值，则后移一位
            {
                arr[end] = arr[end-1];
                end--;
            }
            else
            {
                break;
            }
        }
        // arr[end-1] = temp;是之前的错误，现已修正
        arr[end] = temp;	//将数据放入插入位置
    }
}*/

void InsertSort(int* arr, int size)
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        int key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int Insertion_test()
{
    int arr[] = {5, 2, 8, 3, 1, 9, 4, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    clock_t start = clock(); // 记录算法开始时间

    InsertSort(arr, size);

    clock_t end = clock(); // 记录算法结束时间
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // 计算算法耗时



    printf("\n");
    printf("单趟插入：");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\t 算法耗时: %f seconds\n", time_taken);
    return 0;
}


