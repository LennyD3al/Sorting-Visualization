#include <iostream>
#include <cstdio>

#include "BubbleSort.h"
#include "array_cb.h"

void test(int* arr, int size) {

    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void printArr(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {


    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    array_cb array(arr, n);
    array.add_array_accessed_cb(test);

    BubbleSort::sort(array, n);

    printf("%d\n", array.get_access_count());
    printf("%d\n", array.get_swap_count());

    return 0;
}