//
// Created by lenny on 9/1/2020.
//

#ifndef SCHULE_ARRAY_CB_H
#define SCHULE_ARRAY_CB_H

#include <vector>

class array_cb {

    using f_void_t = void (*)(int*, int);

public:

    explicit array_cb(int* p = nullptr, int s = 0);

    int& operator[] (int);

    void add_array_accessed_cb(f_void_t cb);
    void add_array_swapped_cb(f_void_t cb);

    void remove_array_accessed_cb(f_void_t cb);
    void remove_array_swapped_cb(f_void_t cb);

    void swap(const int& index1, const int& index2);

    int get_access_count() { return access_count; }
    int get_swap_count() { return swap_count; }

    void print() const;

private:
    int* ptr;
    int size;

    std::vector<f_void_t> array_accessed_cb;
    std::vector<f_void_t> array_swapped_cb;

    int access_count;
    int swap_count;

};


#endif //SCHULE_ARRAY_CB_H
