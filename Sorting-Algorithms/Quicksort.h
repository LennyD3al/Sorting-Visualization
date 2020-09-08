//
// Created by lenny on 08/09/2020.
//

#ifndef SORTING_VIS_QUICKSORT_H
#define SORTING_VIS_QUICKSORT_H

#include "../util/ArrayCB.h"

class QuickSort {
private:
    friend class Sort;

    static void sort(ArrayCB arr, int n) {
        quickSort(arr, 0, n - 1);
    }

    static int partition (ArrayCB arr, int low, int high)
    {
        int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j <= high- 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++;    // increment index of smaller element
                arr.swap(i, j);
            }
        }
        arr.swap(i + 1, high);
        return (i + 1);
    }

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
    static void quickSort(ArrayCB arr, int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(arr, low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};


#endif //SORTING_VIS_QUICKSORT_H
