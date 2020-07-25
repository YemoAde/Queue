#include "Queue.h"
#include <iostream>
#include <assert.h>
#include <exception>


//Linked List implementation of Queues
template <class T>
Queue<T>::Queue (int capacity) {
    this->capacity = capacity;
    rear = NULL;
    front = NULL;
}

template <class T>
void Queue<T>::dequeue () {
    if(size == 0) {
        throw std::underflow_error("Underflow");
    }

    auto item = front;
    front = front->next;
    delete item;
    size--;
}

template <class T>
void Queue<T>::enqueue (T* data) {
    if(isfull()) {
        throw std::overflow_error("Overflow");
        return;
    }

    auto tolist = new QueueNode<T>(data);
    if (size == 0) {
        front = tolist;
        rear = tolist;
    } else {
        rear->next = tolist;
        rear = tolist;
    }
    size++;
}

template <class T>
T const Queue<T>::peek () {
    if(size == 0) {
        throw std::underflow_error("Underflow");
    }
    return *(front->data);
}

template <class T>
bool Queue<T>::isfull () {
    return size == capacity;
}

template <class T>
bool Queue<T>::isempty() {
    return size == 0;
}


int main () {
    Queue<int> testQueue = Queue<int>(5);
    int first = 1;
    int two = 2;
    int three = 2;
    int four = 2;

    //Tests
    //Check if Queue is empty
    assert(testQueue.isempty() == true);

    //Check dequeue when empty - underflow
    bool dequeueEmptyError = false;
    try {
        testQueue.dequeue();
    } catch(std::exception& e) {
        dequeueEmptyError = true; 
    }
    assert(dequeueEmptyError == true);

    //Check enqueue
    testQueue.enqueue(& first);
    assert(testQueue.isfull() == false);
    assert(testQueue.peek() == 1);

    testQueue.dequeue();
    testQueue.enqueue(& two);
    testQueue.enqueue(& three);
    testQueue.enqueue(& four);
    testQueue.enqueue(& first);
    testQueue.enqueue(& three);

    //Check of isfull
    assert(testQueue.isfull() == true);
    assert(testQueue.peek() == 2);

    bool overFlowError = false;
    try {
        testQueue.enqueue(&first);
    } catch(std::exception& e) {
        overFlowError = true; 
    }
    assert(overFlowError == true);
    
}