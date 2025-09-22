#include "MinHeap.h"
#include <iostream>

template<typename T>
void MinHeap<T>::insert_cost(const T& val) {
    data.push_back(val);
    int n = data.size() - 1; //index of the last node
    //percolate UP
    while (data[n] < data[(n - 1) / 2]) {
        swap(data[n], data[(n - 1) / 2]);
        n = (n - 1) / 2; //make cur index equal to the parent index
    }
}

template<typename T>
void MinHeap<T>::insert_distance(const T& val) {
    data.push_back(val);
    int n = data.size() - 1; //index of the last node
    //percolate UP
      while (data[(n - 1) / 2] > data[n]) {
        swap(data[n], data[(n - 1) / 2]);
        n = (n - 1) / 2; //make cur index equal to the parent index
    }
}


template<typename T>
void MinHeap<T>::print() const {
    int cur_level = 0;
    int new_level = 1;

    for(const T& i : data) {
        std::cout << i << ' ';
        cur_level++;
        if (cur_level == new_level) {
            std::cout << "\n";
            new_level *= 2;
            cur_level = 0;
        }
    }
    std::cout << "\n----------------------------\n";
}


template<typename T>
T MinHeap<T>::delete_min_cost() {
    if (data.empty()) {
        throw std::string("delete_min: Empty Heap\n");
    }    
    T res = data[0];
    data[0] = data[data.size() - 1]; //set the root with the value of the last node
    data.pop_back(); //deletes the last node

    //percolate DOWN ***for cost***
    percolate_down_cost(0);

    return res;
}


template<typename T>
T MinHeap<T>::delete_min_distance() {
    if (data.empty()) {
        throw std::string("delete_min: Empty Heap\n");
    }    
    T res = data[0];
    data[0] = data[data.size() - 1]; //set the root with the value of the last node
    data.pop_back(); //deletes the last node

    //percolate DOWN
    percolate_down_distance(0);

    return res;
}


template<typename T>
void MinHeap<T>::percolate_down_cost(int i) { // ***for cost***
    if (data.empty() || data.size() <= i || i < 0) {
        return;
    }
    int parent_index = i;
    int kids_min_index = i;

    do {
        //no kids
        if (data.size() <=  parent_index * 2 + 1) {
            break;
        }
        else if (parent_index * 2 + 2 < data.size()){ //has 2 kids
            kids_min_index = min_index_cost(parent_index * 2 + 1, parent_index * 2 + 2);

        }
        else if (parent_index * 2 + 1 < data.size()) { //has left kid
            kids_min_index = parent_index * 2 + 1;
        }
        //check is the smallest kid smaller than the parent
        if (data[kids_min_index] < data[parent_index]) {
            swap(data[parent_index], data[kids_min_index]);
            parent_index = kids_min_index;
        }
        else {
            break;
        }

    } while(1);
}

template<typename T>
void MinHeap<T>::percolate_down_distance(int i) {
    if (data.empty() || i >= data.size() ||  0 > i) {
        return;
    }

    int parent_index = i;
    int kids_min_index = i;

    do {
        //no kids
        if (parent_index * 2 + 1 >= data.size()) {
            break;
        }
        else if (data.size() > parent_index * 2 + 2){ //has 2 kids
            kids_min_index = min_index_distance(parent_index * 2 + 1, parent_index * 2 + 2);

        }
        else if (data.size() > parent_index * 2 + 1) { //has left kid
            kids_min_index = parent_index * 2 + 1;
        }
        //check is the smallest kid smaller than the parent
        if (data[parent_index] > data[kids_min_index]) {
            swap(data[parent_index], data[kids_min_index]);
            parent_index = kids_min_index;
        }
        else {
            break;
        }

    } while(1);

}


template<typename T>
int MinHeap<T>::min_index_cost(int i1, int i2) const {
    if ( data.size() <= i1  ||  data.size() <= i2  || i1 < 0 || i2 < 0) {
        throw std::string ("min_index: incorrect index");
    }

    return (data[i1] < data[i2] ? i1 : i2);
}


template<typename T>
int MinHeap<T>::min_index_distance(int i1, int i2) const {
    if (i1 >= data.size() || i2 >= data.size() || 0 > i1 || 0 > i2) {
        throw std::string ("min_index: incorrect index");
    }
    return (data[i2] > data[i1] ? i1 : i2);
}


template<typename T>
bool MinHeap<T>::isEmpty() const {
    return data.empty();
}

template<typename T>
void MinHeap<T>::decrease_key_cost(int i, const T &val){
    if (data[i] < val){
        throw std::string("decrease_key: new value is bigger than the old one");
    }
    data[i] = val;
    percolate_down_cost(i);
}

template<typename T>
void MinHeap<T>::decrease_key_distance(int i, const T &val){
    if (val > data[i]){
        throw std::string("decrease_key: new value is bigger than the old one");
    }
    data[i] = val;
    percolate_down_distance(i);
}

// MinHeap(std::vector<T> v); {
//     //insert the elements in the given order
//     //heapify
// }