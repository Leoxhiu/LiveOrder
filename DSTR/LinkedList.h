#pragma once

using namespace std;

template <class T> class Node {
    public:
        T data;
        Node<T>* next;
};

template <class T> class LinkedList
{
private:
    Node<T>* head;
    int length;

public:
    LinkedList();
    ~LinkedList();
    void append(T newData);
    void appendAfter(int index, T newData);
    int getLength();
    T* getData(int index);
    Node<T>* getNode(int index);
    Node <T>* getHead();
};

template<class T>
inline void LinkedList<T>::append(T newData)
{
    Node<T>* newNode = new Node<T>();
    Node<T>* last = this->head;
    newNode->data = newData;
    newNode->next = nullptr;
    if (this->head == nullptr)
    {
        this->head = newNode;
        this->length++;
        return;
    }
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = newNode;
    this->length++;
    return;
}

template<class T>
inline void LinkedList<T>::appendAfter(int index, T newData)
{
    if (index >= this->length)return;
    if (!this->head) return;
    Node<T>* newNode = new Node<T>();
    Node<T>* last = this->head;
    Node<T>* lastNext = nullptr;
    newNode->data = newData;
    newNode->next = nullptr;
    int currIndex = 0;
    if (index == 0) {
        lastNext = last->next;
        this->head->next = newNode;
        newNode->next = lastNext;
    }
    else {
        while (index != currIndex && last->next) {
            last = last->next;
            if (last) {
                lastNext = last->next;
            }
            currIndex++;
        }
        last->next = newNode;
        newNode = lastNext;
    }
    this->length++;

}

template<class T>
inline int LinkedList<T>::getLength()
{
    return this->length;
}

template<class T>
inline T* LinkedList<T>::getData(int index)
{
    if (index >= this->length)
    {
        return nullptr;
    }
    Node<T>* last = this->head;
    int currIndex = 0;
    if (index == 0) {
        return &this->head->data;
    }
    else {
        while (index != currIndex && last->next) {
            last = last->next;
            currIndex++;
        }
        return &(last->data);
    }
}

template<class T>
inline Node<T>* LinkedList<T>::getHead() {
    return this->head;
}

template<class T>
inline Node<T>* LinkedList<T>::getNode(int index) {
    if (index >= this->length)
    {
        return nullptr;
    }
    Node<T>* last = this->head;
    int currIndex = 0;
    if (index == 0) {
        return &this->head;
    }
    else {
        while (index != currIndex && last->next) {
            last = last->next;
            currIndex++;
        }
        return &last;
    }
}

template<class T>
inline LinkedList<T>::LinkedList()
{
    this->length = 0;
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
}