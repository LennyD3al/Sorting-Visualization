//
// Created by lenny on 9/1/2020.
//

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "array_cb.h"

int &array_cb::operator[](int index) {
    // TODO: Implement callback when array is accessed

    if (index >= size) {
        std::cout << "Array index out of bound, exiting";
        throw;
    }

    access_count++;
    for (auto &cb: array_accessed_cb) {
        cb(ptr, size);
    }

    return ptr[index];
}

array_cb::array_cb(int * p, int s) {
    size = s;
    ptr = nullptr;
    if (s != 0) {
        ptr = new int[s];
        for(int i = 0; i < s; i++)
            ptr[i] = p[i];
    }
}

void array_cb::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << ptr[i] << " ";
    }

    std::cout << std::endl;
}

void array_cb::add_array_accessed_cb(array_cb::f_void_t cb) {
    array_accessed_cb.push_back(cb);
}

void array_cb::add_array_swapped_cb(array_cb::f_void_t cb) {
    array_swapped_cb.push_back(cb);
}

void array_cb::remove_array_accessed_cb(array_cb::f_void_t cb) {
    array_accessed_cb.erase(std::remove(array_accessed_cb.begin(), array_accessed_cb.end(), cb), array_accessed_cb.end());
}

void array_cb::remove_array_swapped_cb(array_cb::f_void_t cb) {
    array_swapped_cb.erase(std::remove(array_swapped_cb.begin(), array_swapped_cb.end(), cb), array_swapped_cb.end());

}

void array_cb::swap(const int &index1, const int &index2) {

    int temp = ptr[index1];
    ptr[index1] = ptr[index2];
    ptr[index2] = temp;

    swap_count++;
    for (auto& cb: array_swapped_cb) {
        cb(ptr, size);
    }

}

