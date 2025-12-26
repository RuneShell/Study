// Project 4-3
// unsorted list using head & tail : doubly linked list
// UnSortedType.hpp

#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include <iostream> 
using namespace std;

template<class ItemType>
struct NodeType{
    NodeType* prev;
    ItemType value;
    NodeType* next;
};

template <class ItemType>
class UnsortedType{
private:
    NodeType<ItemType>* head;
    NodeType<ItemType>* tail;
    int length;

    NodeType<ItemType>* getPointerWithIndex(int pos);
    NodeType<ItemType>* getPointerWithItem(ItemType item);

public:
    UnsortedType();
    ~UnsortedType();
    void clear();

    void insertItem(ItemType item);
    void removeItem(ItemType item);

    bool findItem(ItemType& item);
    ItemType getItem(int pos);

    bool isFull();
    bool isEmpty();
    int  size();

    void printList();
};

template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::getPointerWithIndex(int pos) {
    // edge case : invalid pos
    if (pos < 0 || pos >= length) return nullptr;

    NodeType<ItemType>* tempNode = head->next;
    for (int i = 0; i < pos; i++) {
        tempNode = tempNode->next;
    }

    return tempNode;
}

template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::getPointerWithItem(ItemType item) {
    NodeType<ItemType>* tempNode = head->next;
    while (tempNode != tail) {
        if (tempNode->value == item) return tempNode;
        else tempNode = tempNode->next;
    }

    return nullptr; // must be equal to tail->next.
}


template <class ItemType>
UnsortedType<ItemType>::UnsortedType(){
    head = new NodeType<ItemType>{ nullptr, INT_MIN, nullptr};
    tail = new NodeType<ItemType>{ head, INT_MAX, nullptr }; // unsorted이기에 굳이 INT_MAX나 INT_MIN일 필요는 없다.
    head->next = tail;

    length = 0;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType(){
    clear();
    delete head;
    delete tail;
}

template <class ItemType>
void UnsortedType<ItemType>::clear(){
    NodeType<ItemType>* tempNode = head->next;
    NodeType<ItemType>* prevNode = head;
    while (tempNode != tail) {
        prevNode->next = tempNode->next;
        delete tempNode;
        tempNode = prevNode->next;
    }

    length = 0;
}


template <class ItemType>
void UnsortedType<ItemType>::insertItem(ItemType item) {
    // append list stack
    NodeType<ItemType>* newNode = new NodeType<ItemType>{ head, item, head->next };

    head->next->prev = newNode;
    head->next = newNode;
    length++;
}


template <class ItemType>
void UnsortedType<ItemType>::removeItem(ItemType item){
    NodeType<ItemType>* tempNode = getPointerWithItem(item);

    if (tempNode != nullptr) {
        tempNode->prev->next = tempNode->next;
        tempNode->next->prev = tempNode->prev;
        delete tempNode;
    }
    length--;
}


template <class ItemType>
bool UnsortedType<ItemType>::findItem(ItemType& item) {
    NodeType<ItemType>* tempNode = getPointerWithItem(item);

    if (tempNode != nullptr) {
        return true;
    }
    return false;
}


template <class ItemType>
ItemType UnsortedType<ItemType>::getItem(int pos) {
    NodeType<ItemType>* tempNode = getPointerWithIndex(pos);

    if (tempNode != nullptr) return tempNode->value;
    else return -1;
} 


template<class ItemType>
bool UnsortedType<ItemType>::isFull(){
    NodeType<ItemType>* tempPtr;
    try {
        tempPtr = new NodeType<ItemType>;
        delete tempPtr;
        return false;
    } catch(std::bad_alloc exception){
        return true;
    }
}

template<class ItemType>
bool UnsortedType<ItemType>::isEmpty(){
    return (length == 0);
}


template <class ItemType>
int UnsortedType<ItemType>::size(){
    return length;
}



template <class ItemType>
void UnsortedType<ItemType>::printList(){
    NodeType<ItemType>* tempPtr = head->next;
    
    std::cout << "[\t";
    while (tempPtr != tail)
    {
        std::cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    
    std::cout << "]" << std::endl;
    
}

#endif
