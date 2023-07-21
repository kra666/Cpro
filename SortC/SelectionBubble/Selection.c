//
// Created by fang on 2023/7/20.
//


#include "Selection.h"
#include <stdio.h>

void swap(int *a,int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int selection_sort(int arr[],int len)
{
    int i,j;
	int n=0;

    for (i = 0 ; i < len - 1 ; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)     //走訪未排序的元素
            if (arr[j] < arr[min])    //找到目前最小值
                min = j;    //紀錄最小值
        swap(&arr[min], &arr[i]);    //做交換
    }

}


void Selection_test() {

    int arr[5] = {1, 3, 35, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr,n);

    printf("\n选择： ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}




//其他方法：

/*
void selectSort(ElemType arr[], int len) //选择排序
{
    int temp;
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
*/

