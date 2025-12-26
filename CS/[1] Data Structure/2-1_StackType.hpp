// Project 2-1
// stack : singly linked list
// StackType.hpp

#ifndef STACKTYPE_H
#define STACKTYPE_H
#include <iostream>

// Define Node
template<typename ItemType>
struct NodeType {
	ItemType value;
	NodeType* next;
};


template<typename ItemType>
class StackType {
private:
	NodeType<ItemType>* pTop;

public:
	StackType();
	~StackType();

	void clear();
	void push(ItemType newItem);
	ItemType pop();

	bool isEmpty() const;
	bool isFull() const;
	int size() const;

	void Print();
};


template<typename ItemType>
StackType<ItemType>::StackType() {
	pTop = nullptr;
}

template<typename ItemType>
StackType<ItemType>::~StackType() {
	clear();
}

template<typename ItemType>
void StackType<ItemType>::clear() {
	NodeType<ItemType>* tempNode = pTop;

	while (tempNode != nullptr) {
		pTop = pTop->next;
		delete tempNode;
		tempNode = pTop;
	}
}

template<typename ItemType>
void StackType<ItemType>::push(ItemType newItem) {
	if (isFull()) return;

	NodeType<ItemType>* newNode = new NodeType<ItemType>{ newItem, pTop };
	pTop = newNode;
}

template<typename ItemType>
ItemType StackType<ItemType>::pop() {
	if (isEmpty()) return NULL;

	NodeType<ItemType>* tempNode = pTop;
	pTop = tempNode->next;
	ItemType result = tempNode->value;
	delete tempNode;

	return result;
}

template<typename ItemType>
bool StackType<ItemType>::isEmpty() const {
	return (pTop == nullptr);
}

template<typename ItemType>
bool StackType<ItemType>::isFull() const {
	try {
		NodeType<ItemType>* newNode = new NodeType<ItemType>;
		delete newNode;
	}
	catch (std::bad_alloc exception) {
		return true;
	}

	return false;
}

template<typename ItemType>
int StackType<ItemType>::size() const {
	int len = 0;
	NodeType<ItemType>* cursor = pTop;
	while (cursor != nullptr) {
		len++;
		cursor = cursor->next;
	}

	return len;
}


template<typename ItemType>
void StackType<ItemType>::Print() {
	if (isEmpty()) {
		std::cout << "[EMPTY STACK]" << std::endl;
		return;
	}

	std::cout << "(top)\t";
	NodeType<ItemType>* tempPtr = pTop;

	while (tempPtr != nullptr) {
		std::cout << tempPtr->value << "\t";
		tempPtr = tempPtr->next;
	}

	std::cout << " ] " << std::endl;
}


#endif