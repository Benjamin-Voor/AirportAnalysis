#ifndef QUEUE_H
#define QUEUE_H

#include <string>

template<typename T>
class Queue {
public:
    Queue(unsigned capacity = 10);
    
    unsigned size() const;
    bool empty() const;
    bool full() const;

    int front() const;
    
    const T& getData() const;
    
    void push(const T& val);
    void pop();

    void print() const;

private:
    T* data;
    unsigned queueSize; //the actual number of elements in the queue
    unsigned capacity; //the max number of elements in the queue
    int frnt; //the index storing the front of the queue
    int bck;  //the index storing the back of the queue
};

#endif