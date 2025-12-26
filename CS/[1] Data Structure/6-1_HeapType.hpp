// Project 6-1
// heap (max heap)
// HeapType.hpp
#pragma once

template<class ItemType>
void swap(ItemType& x, ItemType& y){
	ItemType tmp = y;
	y = x;
	x = tmp;
}

template<class ItemType>
struct HeapType{
private:
	bool isMaxHeap = true; // Default is [max heap]

public:
	ItemType*	items;
	int			num_items; // length is alias of num_items in [PriorityQue.h]

	void		setMaxHeap(bool);

	void 		reheapUp(int root, int bottom_id);
	void		reheapDown(int root, int bottom_id);
};


template<class ItemType>
void HeapType<ItemType>::setMaxHeap(bool b) {
	isMaxHeap = b;
}


template<class ItemType>
void HeapType<ItemType>::reheapUp(int root, int bottom_id) { // insert
	if (bottom_id > root) {
		int parent = (bottom_id - 1) / 2;
		if (isMaxHeap && (items[parent] < items[bottom_id]) || 
			!isMaxHeap && (items[parent] > items[bottom_id])) {

			swap(items[parent], items[bottom_id]);
			reheapUp(root, parent);
		}
	}
}

template<class ItemType>
void HeapType<ItemType>::reheapDown(int root, int bottom_id) { // pop
	int maxChild;
	int leftChild = root * 2 + 1;
	int rightChild = root * 2 + 2;

	if (leftChild <= bottom_id) {
		if (rightChild <= bottom_id) {
			// select bigger one
			if ((isMaxHeap && items[leftChild] > items[rightChild]) ||
				(!isMaxHeap && items[leftChild] < items[rightChild])) {
				maxChild = leftChild;
			}
			else {
				maxChild = rightChild;
			}
		}
		else { // if rightChild not exist
			maxChild = leftChild;
		}

		// Swap
		if (isMaxHeap && (items[root] < items[maxChild]) ||
			!isMaxHeap && (items[root] > items[maxChild])) {
			swap(items[root], items[maxChild]);
			reheapDown(maxChild, bottom_id);
		}
	}
}