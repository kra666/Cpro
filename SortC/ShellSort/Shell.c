//
// Created by fang on 2023/7/20.
//

#include <stdio.h>
#include "Shell.h"
#include "time.h"

void ShellSort(int* arr, int size)
{
    int gap = size;
    while (gap > 1)
    {
        gap = gap / 3 + 1;	//调整希尔增量
        int i = 0;
        for (i = 0; i < size - gap; i++)	//从0遍历到size-gap-1
        {
            int end = i;
            int temp = arr[end + gap];
            while (end >= 0)
            {
                if (arr[end] > temp)
                {
                    arr[end + gap] = arr[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            arr[end + gap] = temp;	//以 end+gap 作为插入位置
        }
    }
}



int ShellSort_test()
{
    int arr[] = {5, 11, 8, 45, 1, 66, 4, 6, 15};
    int size = sizeof(arr) / sizeof(arr[0]);


    clock_t start = clock(); // 记录算法开始时间

    ShellSort(arr, size);

    clock_t end = clock(); // 记录算法结束时间
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // 计算算法耗时


    printf("希尔：");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\t 算法耗时: %f seconds\n", time_taken);
    return 0;
}