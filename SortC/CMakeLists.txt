cmake_minimum_required(VERSION 3.25)
project(SortC C)

set(CMAKE_C_STANDARD 23)

#add_executable(BubbleSort SelectionBubble main.c BubbleSort/Bubble.c BubbleSort/Bubble.h SelectionBubble/Selection.cpp SelectionBubble/Selection.h)

add_executable(BubbleSort BubbleSort/Bubble.c BubbleSort/Bubble.h

        SelectionBubble SelectionBubble/Selection.c SelectionBubble/Selection.h
        CountingSort CountingSort/Counting.c CountingSort/Counting.h
        InsertionSort InsertionSort/Insertion.c InsertionSort/InsertionBinary.c InsertionSort/Insertion.h
        ShellSort ShellSort/Shell.c ShellSort/Shell.h
		QuickSort QuickSort/Quick.c QuickSort/Quick.h
        MergeSort MergeSort/Merge.c MergeSort/MergeRecursion.c MergeSort/Merge.h
		RadixSort RadixSort/Radix.c RadixSort/Radix.h
		BucketSort BucketSort/Bucket.c BucketSort/Bucket.h
		HeapSort


		main.c

		HeapSort/Heap.c HeapSort/Heap.h)



