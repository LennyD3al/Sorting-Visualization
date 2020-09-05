//
// Created by lenny on 9/1/2020.
//


#include "ArrayCB.h"

int &ArrayCB::operator[](int index) {

    if (index >= m_size) {
        // std::cout << "Array index out of bound, exiting";
        throw;
    }

    access_count = access_count + 1;
    for (auto &cb: array_accessed_cb) {
        cb();
    }

    m_array_changed = false;
    return ptr[index];
}

ArrayCB::ArrayCB(int * p, int s) {
    m_size = s;
    ptr = nullptr;
    if (s != 0) {
        ptr = new int[s];
        for(int i = 0; i < s; i++)
            ptr[i] = p[i];
    }
}

ArrayCB::ArrayCB(ArrayCB &arr) {
    m_size = arr.size();
    ptr = new int[m_size];
    for (int i = 0; i < m_size; i++) {
        ptr[i] = arr[i];
    }
}


void ArrayCB::print() const {
    for (int i = 0; i < m_size; i++) {
        std::cout << ptr[i] << " ";
    }

    std::cout << std::endl;
}

void ArrayCB::add_array_accessed_cb(ArrayCB::f_void_t cb) {
    array_accessed_cb.push_back(cb);
}

void ArrayCB::add_array_swapped_cb(ArrayCB::f_void_t cb) {
    array_swapped_cb.push_back(cb);
}

void ArrayCB::remove_array_accessed_cb(ArrayCB::f_void_t cb) {
    // array_accessed_cb.erase(std::remove(array_accessed_cb.begin(), array_accessed_cb.end(), cb), array_accessed_cb.end());
}

void ArrayCB::remove_array_swapped_cb(ArrayCB::f_void_t cb) {
    // array_swapped_cb.erase(std::remove(array_swapped_cb.begin(), array_swapped_cb.end(), cb), array_swapped_cb.end());

}

void ArrayCB::swap(const int &index1, const int &index2) {

    int temp = ptr[index1];
    ptr[index1] = ptr[index2];
    ptr[index2] = temp;

    swap_count++;
    for (auto& cb: array_swapped_cb) {
        cb();
    }

}

int ArrayCB::size() const {
    return m_size;
}

int ArrayCB::largest_element() {

    if (m_array_changed) return last_largest_element;

    int largest_element = INT32_MIN;

    for (int i = 0; i < m_size; i++) {
        if (ptr[i] > largest_element)
            largest_element = ptr[i];
    }

    last_largest_element = largest_element;
    m_array_changed = true;
    return largest_element;
}

std::vector<bool> ArrayCB::position_changed(ArrayCB arr) {
    std::vector<bool> pos_changed;

    for (int i = 0; i < m_size; i++) {
        if (ptr[i] == arr[i])
            pos_changed.push_back(false);
        else
            pos_changed.push_back(true);
    }

    return pos_changed;
}


