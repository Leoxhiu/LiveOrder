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

public:
    void append(T newData);
    void appendAfter(int i, T newData);
    //bool* search(T data);
    int getLength();
    T* get(int i);

public:
    int length;

public:
    LinkedList();
    ~LinkedList();
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
inline void LinkedList<T>::appendAfter(int i, T newData)
{
    if (i >= this->length)return;
    if (!this->head) return;
    Node<T>* newNode = new Node<T>();
    Node<T>* last = this->head;
    Node<T>* lastNext = nullptr;
    newNode->data = newData;
    newNode->next = nullptr;
    int currIndex = 0;
    if (i == 0) {
        lastNext = last->next;
        this->head->next = newNode;
        newNode->next = lastNext;
    }
    else {
        while (i != currIndex && last->next) {
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

//template<class T>
//inline bool* LinkedList<T>::search(T data)
//{
//    Node<T>* last = this->head;
//    while (last != NULL)
//    {
//        if (last->data == data)
//        {
//            return true;
//        }
//        last = last->next;
//    }
//    return false;
//}

template<class T>
inline int LinkedList<T>::getLength()
{
    return this->length;
}

template<class T>
inline T* LinkedList<T>::get(int i)
{
    if (i >= this->length)
    {
        return nullptr;
    }
    Node<T>* last = this->head;
    int currIndex = 0;
    if (i == 0) {
        return &this->head->data;
    }
    else {
        while (i != currIndex && last->next) {
            last = last->next;
            currIndex++;
        }
        return &(last->data);
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
