// Project 3-2
// sorted list : singly linked list
// SortedType.hpp

#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H
#include<iostream>
using namespace std;

template<class ItemType>
struct NodeType{
    ItemType value;
    NodeType* next;
};

template <class ItemType>
class SortedType{
private:
    NodeType<ItemType>* listData;
    int length;

public:
    SortedType();
    ~SortedType();
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
SortedType<ItemType>::SortedType(){
    length = 0;
    listData = nullptr;
}

template <class ItemType>
SortedType<ItemType>::~SortedType(){ 
    NodeType<ItemType>* tempNode;
    while(listData != nullptr) {
        tempNode = listData;
        listData = listData->next;
        delete tempNode;
    }

    length = 0;
}

template <class ItemType>
void SortedType<ItemType>::clear(){
    this -> ~SortedType();
}


template <class ItemType>
void SortedType<ItemType>::insertItem(ItemType item) {
    NodeType<ItemType>* newNode = new NodeType<ItemType>{ item, nullptr }; // temporally set nullptr
    NodeType<ItemType>* tempNode = listData;
    NodeType<ItemType>* prevNode = nullptr;

    // edge case 1 : 완전히 빈 경우
    if (length == 0) {
        listData = newNode;
        length++;
        return;
    }

    // edge case 2 : 맨 앞에 넣어야 하는 경우
    if (item < listData->value) {
        newNode->next = listData;
        listData = newNode;
        length++;
        return;
    }

    // normal case
    while (tempNode != nullptr) {
        if (item < tempNode->value) {
            newNode->next = tempNode;
            prevNode->next = newNode;
            length++;
            return;
        }
        else {
            prevNode = tempNode;
            tempNode = tempNode->next;
        }

    }

    // edge case 3 : 마지막에 추가
    if (prevNode != nullptr) {
        prevNode->next = newNode;
        length++;
    }

}


template <class ItemType>
void SortedType<ItemType>::removeItem(ItemType item){
    NodeType<ItemType>* tempNode = listData;
    NodeType<ItemType>* prevNode = nullptr;

    // edge case 1: 완전히 빈 경우
    if (length == 0) return;

    // edge case 2: 맨 앞에서 제거
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
            break;
        }
        else {
            prevNode = tempNode;
            tempNode = tempNode->next;
        }
    }

}


template <class ItemType>
bool SortedType<ItemType>::findItem(ItemType& item) {
    NodeType<ItemType>* tempPtr;
    tempPtr = listData;

    while (tempPtr != nullptr) {
        if ((tempPtr->value) == item) {
            return true;
        }
        else {
            tempPtr = tempPtr->next;
        }
    }
    return false;
}


template <class ItemType>
ItemType SortedType<ItemType>::getItem(int pos) {
    // edge case 1: invalid pos
    if (pos < 0 || pos >= length) return NULL;

    // normal case
    NodeType<ItemType>* tempNode = listData;
    for (int i = 0; i < pos; i++) {
        tempNode = tempNode->next;
    }

    return tempNode->value;
}


template<class ItemType>
bool SortedType<ItemType>::isFull(){
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
bool SortedType<ItemType>::isEmpty(){
    return (listData == nullptr);
}


template <class ItemType>
int SortedType<ItemType>::size(){
    return length;
}



template <class ItemType>
void SortedType<ItemType>::printList(){
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
