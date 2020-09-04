//
// Created by lenny on 04/09/2020.
//

#ifndef SORTING_VIS_INSERTIONSORT_H
#define SORTING_VIS_INSERTIONSORT_H

#include "ArrayCB.h"

class InsertionSort {
public:
    static void sort(ArrayCB &A, int n) {
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0 && A[j] < A[j - 1]; j--) {
                A.swap(j, j - 1);
            }
        }
    }
};

#endif //SORTING_VIS_INSERTIONSORT_H
