// Project 1-1
// stack : dynamic array
// StackType.hpp

#ifndef STACKTYPE_H
#define STACKTYPE_H
#include <iostream>

template <class ItemType>
class StackType{
private:
    int maxCount;
    int top;
    ItemType* data;

public:
    StackType(int);
    ~StackType();

    void push(ItemType item);
    ItemType pop();

    int size() const;
    bool isFull() const;
    bool isEmpty() const;
    
    void printStack();

};

// Stack Constructor
template <class ItemType>
StackType<ItemType>::StackType(int maxCount) : maxCount(maxCount), top(-1), data(new ItemType[maxCount]) {};

template <class ItemType>
StackType<ItemType>::~StackType() {
    delete[] data;
}

template <class ItemType>
void StackType<ItemType>::push(ItemType newItem){
    if (isFull()) return;

    top++;
    data[top] = newItem;
}

template <class ItemType>
ItemType StackType<ItemType>::pop(){
    if (isEmpty()) return NULL;

    top--;
    return data[top + 1];
}


template <class ItemType>
int StackType<ItemType>::size() const{
    return (top + 1);
}


template <class ItemType>
bool StackType<ItemType>::isEmpty() const{
    return (top == -1);
}

template <class ItemType>
bool StackType<ItemType>::isFull() const{
    return (top == maxCount - 1); // index ↔ num
}

template <class ItemType>
void StackType<ItemType>::printStack(){
    std::cout << "[ ";
    for(int i = 0; i <= top; i++){
        std::cout << data[i] << "\t";
    }
    std::cout << " (top)" << std::endl;
}


#endif /* STACKTYPE_H */
