//
// Created by lenny on 05/09/2020.
//

#ifndef SORTING_VIS_SORT_H
#define SORTING_VIS_SORT_H

#include "BubbleSort.h"
#include "InsertionSort.h"

enum SortingAlgorithm {
    BubbleSort,
    InsertionSort,
    QuickSort,
};

class Sort {
public:
    static void sort(ArrayCB &arr, const SortingAlgorithm &sortingAlgorithm) {
        switch(sortingAlgorithm) {
            case BubbleSort:
                BubbleSort::sort(arr, arr.size());
                break;
            case InsertionSort:
                InsertionSort::sort(arr, arr.size());
                break;
        }

    }
};

#endif //SORTING_VIS_SORT_H
