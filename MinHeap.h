#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>

template <typename T>
class MinHeap {
public:
    MinHeap() {}
    // MinHeap(std::vector<T> v); // irrelevant
    void insert_distance(const T& val);
    void insert_cost(const T& val);
    void print() const;
    T delete_min_cost();
    T delete_min_distance();
    bool isEmpty() const;
    void decrease_key(int i, const T& val);
    void decrease_key_cost(int i, const T& val);
    void decrease_key_distance(int i, const T& val);

private:
    std::vector<T> data;
    void swap(T& v1, T& v2) {
        T tmp = v1;
        v1 = v2;
        v2 = tmp;
    }

    void percolate_down_cost(int i);
    void percolate_down_distance(int i);
    int min_index_cost(int i1, int i2) const;
    int min_index_distance(int i1, int i2) const;
};


#endif

