// Project 6-2
// priority queue : max heap
// PriorityQue.hpp

#pragma once
#include "6-1_HeapType.hpp"

template<class ItemType>
class PQType{
private:
	HeapType<ItemType> 	heap;
	int&		length = heap.num_items;
	int			max_items;

public:
	PQType(int max = 100);
	~PQType();
	PQType(const PQType<ItemType>&);
	const PQType<ItemType>&		operator=(const PQType<ItemType>&);

	void setMaxPQ(bool);

	void		enqueue(ItemType item);
	ItemType	dequeue();

	void		clear();
	bool		isFull() const;
	bool		isEmpty() const;
};

template<class ItemType>
PQType<ItemType>::PQType(int max) {
	max_items = max;
	heap.items = new ItemType[max];
	length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType() {
	clear();
}


template<class ItemType>
void PQType<ItemType>::clear() {
	if(length > 0) delete[] heap.items;
	length = 0;
}


template<class ItemType>
void PQType<ItemType>::setMaxPQ(bool b) {
	heap.setMaxHeap(b);
}


template<class ItemType>
void PQType<ItemType>::enqueue(ItemType item) {
	if (isFull()) {
		return;
	}
	heap.items[length] = item;
	heap.reheapUp(0, length);
	length++;
}

template<class ItemType>
ItemType PQType<ItemType>::dequeue() {
	if (isEmpty()) {
		return { '_', 0};
	}
	ItemType item = heap.items[0];
	heap.items[0] = heap.items[length - 1];
	heap.reheapDown(0, length - 2);
	length--;

	return item;
}

template<class ItemType>
bool		PQType<ItemType>::isFull() const {
	return length == max_items;
}

template<class ItemType>
bool		PQType<ItemType>::isEmpty() const {
	return length == 0;
}

template<class ItemType>
PQType<ItemType>::PQType(const PQType<ItemType>& ref) {
	if (ref == *this) return;

	heap.items = new ItemType[ref.length];
	for (int i = 0; i < ref.heap.num_items; i++)
		heap.items[i] = ref.heap.items[i];

}

template<class ItemType>
const PQType<ItemType>& PQType<ItemType>::operator=(const PQType<ItemType>& ref){
	if (&ref == this) return ref;

	clear();

	heap.items = new ItemType[ref.heap.num_items];
	for (int i = 0; i < ref.heap.num_items; i++)
		heap.items[i] = ref.heap.items[i];

	max_items = ref.max_items;
	length = ref.length;

	return ref;
}


/* ============= Test Code ===============
int main() {
	PQType<int> pq;
	PQType<int> pq2;
	PQType<int> pq3;

	pq.enqueue(1);
	pq.enqueue(3);
	pq.enqueue(5);
	pq.enqueue(2);
	pq.enqueue(4);
	pq.enqueue(6);

	pq2 = pq;
	pq3 = pq;



	while (!pq.isEmpty()) {
		int temp;
		pq.dequeue(temp);
		std::cout << temp << ' ';
	} std::cout << '\n';
	// 6 5 4 3 2 1


	std::cout << pq2.isEmpty() << ' ' << pq2.isFull() << '\n';
	// 0 0
	pq2.clear();
	std::cout << pq2.isEmpty() << ' ' << pq2.isFull() << '\n';
	// 1 0


	std::cout << "pq3(MaxPQ) -> pq(MinPQ)\n";
	pq.setMaxPQ(false);
	while (!pq3.isEmpty()) {
		int temp;
		pq3.dequeue(temp);
		pq.enqueue(temp);
	}
	while (!pq.isEmpty()) {
		int temp;
		pq.dequeue(temp);
		std::cout << temp << ' ';
	} std::cout << '\n';
	// 1 2 3 4 5 6

}
*/