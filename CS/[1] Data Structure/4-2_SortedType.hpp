// Project 4-2
// sorted list using head & tail : singly linked list
// SortedType.hpp
// Using Head & Tail removes all the edge_case overhead of insertItem(), removeItem(), 
// using tail instead of nullptr

#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H
#include <iostream> 
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
    NodeType<ItemType>* head; // head & tail here
    NodeType<ItemType>* tail;
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
    tail = new NodeType<ItemType>{ INT_MAX, nullptr };
    head = new NodeType<ItemType>{ INT_MIN, tail };
    listData = head; // alias

    length = 0;
}

template <class ItemType>
SortedType<ItemType>::~SortedType(){ 
    clear();
    delete[] listData;
    delete head;
    delete tail;
}

template <class ItemType>
void SortedType<ItemType>::clear(){
    NodeType<ItemType>* tempNode = listData->next;
    NodeType<ItemType>* prevNode = listData; // head
    while (tempNode != tail) {
        prevNode->next = tempNode->next;
        delete tempNode;
        tempNode = prevNode->next;
    }

    length = 0;
}


template <class ItemType>
void SortedType<ItemType>::insertItem(ItemType item) {
    NodeType<ItemType>* newNode = new NodeType<ItemType>{ item, nullptr };
    NodeType<ItemType>* tempNode = listData->next;
    NodeType<ItemType>* prevNode = listData; // head

    // remove all overheads of edge cases.
    while (tempNode != nullptr) { // // insert는 특별히 tail까지 확인해봐야 함.
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

}


template <class ItemType>
void SortedType<ItemType>::removeItem(ItemType item){
    NodeType<ItemType>* tempNode = listData->next;
    NodeType<ItemType>* prevNode = listData; // head


    while (tempNode != tail) {
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
bool SortedType<ItemType>::findItem(ItemType& item) {
    NodeType<ItemType>* tempNode = listData->next;

    while (tempNode != tail) {
        if ((tempNode->value) == item) {
            return true;
        }
        else {
            tempNode = tempNode->next;
        }
    }
    return false;
}


template <class ItemType>
ItemType SortedType<ItemType>::getItem(int pos) {
    // edge case 1: invalid pos
    if (pos < 0 || pos >= length) return NULL;

    NodeType<ItemType>* tempNode = listData->next;
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
    return (length == 0);
}


template <class ItemType>
int SortedType<ItemType>::size(){
    return length;
}



template <class ItemType>
void SortedType<ItemType>::printList(){
    NodeType<ItemType>* tempPtr = listData->next;
    
    std::cout << "[\t";
    while (tempPtr != tail)
    {
        std::cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    
    std::cout << "]" << std::endl;
    
}

#endif
