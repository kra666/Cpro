//
// Created by fang on 2023/7/20.
//
#include <stdio.h>
#include "Quick.h"
#include <time.h>    //计算算法时间


void quickSort(int arr[], int left, int right)//快速排序
{
    int i = left, j = right;
    int temp;
    if (left >= right) return;
    while (i <= j)
    {
        while (i <= j&&arr[left] >= arr[i]) ++i;//找出左边比arr[left]大的元素
        while (i <= j&&arr[left] <= arr[j]) --j;//找出右边比arr[left]小的元素
        if (i < j)//交换找到的元素
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;//交换完之后移向下一个位置
            --j;
        }
    }
    //经过循环后在j位置就是标杆的位置，这个位置左边都不大于该值，该位置右边都不小于该值
    temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;       //交换
    quickSort(arr, left, j - 1);  //递归操作左边元素
    quickSort(arr, j+1, right);   //递归操作右边元素

}

int Quick_test()
{

        int arr[] = { 5, 2, 8, 3, 1, 6, 9, 4, 7 };
        int size = sizeof(arr) / sizeof(arr[0]);


        clock_t start = clock(); // 记录算法开始时间

        quickSort(arr, 0, size - 1);

        clock_t end = clock(); // 记录算法结束时间
        double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // 计算算法耗时

        printf("快排:");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }

    	printf("\t \t算法耗时: %f seconds\n", time_taken);

        return 0;

}

