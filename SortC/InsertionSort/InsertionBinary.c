//
// Created by fang on 2023/7/20.
//

#include <stdio.h>
#include "Insertion.h"
#include "time.h"


void InsertionBinary(int* arr, int size)
{
    int i = 0;
    for (i = 1; i < size; i++)
    {
        int left = 0;
        int right = i - 1;

        //查找插入位置
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[i] < arr[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        //后移数据并插入
        int temp = arr[i];
        for (right = i; right > left; right--)
        {
            arr[right] = arr[right-1];
        }
        arr[left] = temp;
    }
}


int BInsertion_test()
{
    int arr[] = {5, 2, 8, 3, 1, 9, 4, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    clock_t start = clock(); // 记录算法开始时间
    InsertionBinary(arr, size);

    clock_t end = clock(); // 记录算法结束时间
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // 计算算法耗时

    printf("二分插入：");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\t算法耗时: %f seconds\n", time_taken);

    return 0;
}