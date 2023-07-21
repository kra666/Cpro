#include <stdio.h>
#include "./BubbleSort/Bubble.h"
#include "./SelectionBubble/Selection.h"
#include "./CountingSort/Counting.h"
#include "./InsertionSort/Insertion.h"
#include "./ShellSort/Shell.h"
#include "./QuickSort/Quick.h"
#include "./MergeSort/Merge.h"
#include "./RadixSort/Radix.h"
#include "./HeapSort/Heap.h"
#include "./BucketSort/Bucket.h"




int main(){

//冒泡排序
    bubble_func();

//选择排序
    Selection_test();

//计数排序
    Counting_test();

//单趟插入排序
    Insertion_test();

//二分法插入排序
    BInsertion_test();

//希尔排序
    ShellSort_test();

//快速排序
    Quick_test();

//归并排序
    Merge_test();

//归并排序（递归）


//基数排序
    Radix_test();

//堆排序
    Heap_test();

//桶排序
    Bucket_test();



   return 0;
};



