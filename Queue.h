#pragma once

template <class S>
struct QueueNode {
    QueueNode * next;
    S * data = nullptr;
    QueueNode<S> (S* item) {
        next = NULL;
        data = item;
    }
};

template <class T>
class Queue {
    private:
        QueueNode<T> * front;
        QueueNode<T> * rear;
        int size {0};
        int capacity;
    public:
        Queue<T>(int capacity);
        void dequeue();
        void enqueue(T* data);
        T const peek();
        bool isfull();
        bool isempty();
};
