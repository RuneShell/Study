// Project 3-1
// unsorted list : singly linked list
// UnsortedType.hpp

#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include<iostream>
using namespace std;

template<class ItemType>
struct NodeType{
    ItemType value;
    NodeType* next;
};

template <class ItemType>
class UnsortedType{
private:
    NodeType<ItemType>* listData;
    int length;

public:
    UnsortedType();
    ~UnsortedType();
    void clear();

    void appendItem(ItemType item);
    void removeItem(ItemType item);

    bool findItem(ItemType& item);
    ItemType getItem(int pos);

    bool isFull();
    bool isEmpty();
    int  size();

    void printList();
};



template <class ItemType>
UnsortedType<ItemType>::UnsortedType(){
    length = 0;
    listData = nullptr;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType(){
    NodeType<ItemType>* tempNode;
    while (listData != nullptr) {
        tempNode = listData;
        listData = tempNode->next;
        delete tempNode;
    }
    
    length = 0;
}

template <class ItemType>
void UnsortedType<ItemType>::clear() {
    this -> ~UnSortedType();
}


template <class ItemType>
void UnsortedType<ItemType>::appendItem(ItemType item){
    NodeType<ItemType>* newNode = new NodeType<ItemType>{ item, listData };
    listData = newNode;

    length++;
}


template <class ItemType>
void UnsortedType<ItemType>::removeItem(ItemType item) {
    NodeType<ItemType>* prevNode = nullptr;
    NodeType<ItemType>* tempNode = listData; // it can be nullptr, but no matter

    // edge case 1 : 아무것도 없을 때
    if (length == 0) return;

    // edge case 2 : 맨 앞 삭제
    if (tempNode->value == item) {
        listData = tempNode->next;
        delete tempNode;
        length--;
        return;
    }

    // normal case
    while (tempNode != nullptr) {
        if (tempNode->value == item) {
            prevNode->next = tempNode->next;
            delete tempNode;
            length--;
            return;
        }
        else {
            prevNode = tempNode;
            tempNode = tempNode->next;
        }
    }
}


template <class ItemType>
bool UnsortedType<ItemType>::findItem(ItemType& item) {
    NodeType<ItemType>* tempPtr;
    tempPtr = listData;


    while (tempPtr != nullptr) {
        if ((tempPtr->value) == item) {
            item = tempPtr->value;
            return true;
        }
        else {
            tempPtr = tempPtr->next;
        }
    }
    return false;
}


template <class ItemType>
ItemType UnsortedType<ItemType>::getItem(int pos) {
    //edge case
    if (pos >= length) return NULL;

    int cursor = 0;
    NodeType<ItemType>* tempNode = listData;

    while (cursor < pos) {
        cursor++;
        tempNode = tempNode->next;
    }

    return tempNode->value;
}


template<class ItemType>
bool UnsortedType<ItemType>::isFull()
{
    NodeType<ItemType>* tempPtr;
    try {
        tempPtr = new NodeType<ItemType>;
        delete tempPtr;
        return false;
    }
    catch(std::bad_alloc exception){
        return true;
    }
}

template<class ItemType>
bool UnsortedType<ItemType>::isEmpty(){
    return (listData == nullptr);
}


template <class ItemType>
int UnsortedType<ItemType>::size(){
    return length;
}



template <class ItemType>
void UnsortedType<ItemType>::printList(){
    NodeType<ItemType>* tempPtr = listData;
    
    std::cout << "[\t";
    while (tempPtr != NULL)
    {
        std::cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    
    std::cout << "]" << std::endl;
    
}

#endif
