//
// Created by lenny on 25.10.2019.
//

#ifndef SCHULE_BUBBLESORT_H
#define SCHULE_BUBBLESORT_H

#include<vector>
#include "ArrayCB.h"

class BubbleSort {
public:
    static void sort(ArrayCB arr, int n) {
        int i, j;
        for (i = 0; i < n -1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j+1])
                    arr.swap(j, j+1);
            }
        }
    }
private:
    static void swap(int* a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};


#endif //SCHULE_BUBBLESORT_H
