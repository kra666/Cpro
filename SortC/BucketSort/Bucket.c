//
// Created by fang on 2023/7/21.
//


#include <string.h>
#include <stdio.h>

#include "Bucket.h"

void bucketSort(int *arr, int size, int max)
{
    int i,j;
    int buckets[max];
    memset(buckets, 0, max * sizeof(int));
    for (i = 0; i < size; i++) {
        buckets[arr[i]]++;
    }
    for (i = 0, j = 0; i < max; i++) {
        while((buckets[i]--) >0)
            arr[j++] = i;
    }
}

int Bucket_test(){
    int arr[7] = {2,5,3,7,6,9,13};
    int size = sizeof (arr)/ sizeof(arr[0]);
    bucketSort(arr, size, 5);

    printf("桶排：");
    for (int i = 0; i <size ; ++i) {
        printf("%d ",arr[i]);
    }

	return 0;
}


//这段代码的测试结果有两个3是因为在桶排序中，相同的元素会被分配到同一个桶中，因此在对桶中的元素进行排序时，
// 可能会出现相同的元素，从而导致有多个相同的元素。在这个例子中，数组`arr`中有两个3，它们被分配到了同一个桶中，
// 因此在对桶中的元素进行排序时，可能会出现多个3。
//
//如果要避免这种情况，可以在分配元素到桶中时，先检查该元素是否已经存在于桶中，如果存在则不再分配。
// 这样可以避免相同的元素被分配到同一个桶中，从而导致排序结果中有多个相同的元素。
//
// 如果输入数组中存在大量重复元素，那么需要使用计数排序来优化桶排序的性能。


