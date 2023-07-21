//
// Created by fang on 2023/7/20.
//

#include "Radix.h"
#include <stdio.h>


void radixSort(int arr[], int len) //基数排序（基数排序是桶排序的一种特殊情况。桶排序是一种非比较排序算法）
{
    int temp[10][20];
    int index;
    for (int n = 1; n <= 100; n *= 10)//数据中最大数是几位，就要进行几次循环
    {
        for (int x = 0; x < 10; ++x)  //初始化     为了方便查找到存放的数据
        {
            for (int y = 0; y < 20; ++y)
            {
                temp[x][y] = -1;
            }
        }
        for (int i = 0; i < len; ++i)  //存放数据
        {
            index = (arr[i] / n) % 10;
            temp[index][i] = arr[i];
        }
        int count = 0;
        for (int i = 0; i < 10; ++i)          //将该次排序后的结果放回原数组
        {
            for (int j = 0; j < 20; ++j)
            {
                if (temp[i][j] != -1)
                    arr[count++] = temp[i][j];
            }
        }

    }
}


int Radix_test(){
    int arr[] = {17, 45, 75, 90, 82, 24, 2, 66};
    int len = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, len);

    printf("\n基数：");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }


    return 0;

}