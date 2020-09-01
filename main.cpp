#include <iostream>
#include <cstdio>

#include "MainWindow.h"

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
int main(int argc, char **argv) {
/*
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);


    ArrayCB array(arr, n);
    auto lambda = [](void) {
        printf("Test\n");
    };
    array.add_array_accessed_cb(lambda);
    array[0] = 10;
    */
    QApplication app(argc, argv);

    MainWindow widget;
    widget.show();

    return app.exec();


}