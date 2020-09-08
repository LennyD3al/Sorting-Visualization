//
// Created by lenny on 9/1/2020.
//

#ifndef SCHULE_ARRAY_CB_H
#define SCHULE_ARRAY_CB_H

#include <vector>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iostream>

class ArrayCB {

    using f_void_t = std::function<void()>;

public:

    explicit ArrayCB(int* p = nullptr, int s = 0);
    ArrayCB (ArrayCB &arr);

    int& operator[] (int);

    int size() const;

    void add_array_accessed_cb(const f_void_t& cb);
    void add_array_swapped_cb(const f_void_t& cb);
    void add_array_update_cb(const f_void_t& cb);

    void remove_array_accessed_cb(f_void_t cb);
    void remove_array_swapped_cb(f_void_t cb);
    void remove_array_update_cb(f_void_t cb);

    void swap(const int& index1, const int& index2);

    int get_access_count() { return access_count; }
    int get_swap_count() { return swap_count; }

    int largest_element();

    std::vector<bool> position_changed(ArrayCB arr);

    void print() const;

    void update();

private:
    int* ptr;
    int m_size;

    std::vector<f_void_t> array_accessed_cb;
    std::vector<f_void_t> array_swapped_cb;
    std::vector<f_void_t> array_update_cb;

    int access_count = 0;
    int swap_count = 0;

    int last_largest_element;
    bool m_array_changed;

};


#endif //SCHULE_ARRAY_CB_H
