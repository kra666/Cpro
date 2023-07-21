//
// Created by fang on 2023/7/20.
//

#include "Merge.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void MergeSort(int* arr, int left, int right, int* temp)
{
    //分解：
    //分割数组只有一个元素时停止递归
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;

    MergeSort(arr, left, mid, temp);		//分割并排序数组左半边
    MergeSort(arr, mid + 1, right, temp);	//分割并排序数组右半边

    //合并：
    int begin1 = left, end1 = mid;			//数组1的左右区间
    int begin2 = mid + 1, end2 = right;		//数组2的左右区间
    int i = begin1;

    //排序两个有序数组
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (arr[begin1] <= arr[begin2])
        {
            temp[i] = arr[begin1];
            begin1++;
        }
        else
        {
            temp[i] = arr[begin2];
            begin2++;
        }
        i++;
    }

    while (begin1 <= end1)
    {
        temp[i] = arr[begin1];
        begin1++;
        i++;
    }

    while (begin2 <= end2)
    {
        temp[i] = arr[begin2];
        begin2++;
        i++;
    }

    //拷贝临时数组的内容到原数组（可以调用memcpy函数）
    //memcpy(arr+left, temp+left, (right-left+1)*sizeof(int));
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}


int Merge_test(){
    int arr[] = { 5, 2, 8, 3, 1, 6, 9, 4, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int* temp = (int*)malloc(n * sizeof(int));

    MergeSort(arr, 0, n - 1, temp);

    printf("归并：");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(temp);
    return 0;

}



