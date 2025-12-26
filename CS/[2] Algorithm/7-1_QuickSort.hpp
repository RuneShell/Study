// Project 7-1
// quick sort - Ascending Order
// QuickSort.hpp


#ifndef _QUICKSORT_H
#define _QUICKSORT_H
#include <algorithm> // for std::swap
//#include <functional>
//#define COUNT // size of arr

template<typename T>
// Ascending Order. change 3▲ to change Order.
void QuickSort(T arr[], int firstIndex, int lastIndex) {
	// For Debugging - 선 operation 후 출력할 것.
	//std::function<void(T[], int, int, int, int, int, int)> printArr = [](const T arr[], int size, int firstIndex, int lastIndex, int pivot, int left, int right) {
	//	for (int i = 0; i < COUNT; i++)
	//		std::cout << (i == firstIndex ? "[ " : "") << (i == pivot ? "P" : "") << (i == left ? "L" : "") << (i == right ? "R" : "") << arr[i] << (i == lastIndex ? " ]" : "") << ' '; std::cout << '\n';
	//	};

	//std::cout << "C\n";
	if (firstIndex < lastIndex) {
		int pivot = firstIndex; // first item is pivot.
		int left = firstIndex + 1;
		int right = lastIndex;


		// 1. Split and Swap
		while (left < right) {
			//std::cout << "W\n";
			// SKIP. No need to change. 
			while (arr[left] <= arr[pivot] && left < lastIndex) { // arr[start] <= arr[pivot] // ▲
				left++;
				//std::cout << "[L++] "; printArr(arr, COUNT, firstIndex, lastIndex, pivot, left, right);
			}
			while (arr[pivot] <= arr[right] && pivot < right) { // arr[pivot] <= arr[end] // ▲
				right--;
				//std::cout << "[R--] "; printArr(arr, COUNT, firstIndex, lastIndex, pivot, left, right);
			}

			// Swap
			if (arr[pivot] < arr[left] && arr[right] < arr[pivot] && left <= right) {
				std::swap(arr[left], arr[right]);
				left++; right--;
				//std::cout << "[ S ] "; printArr(arr, COUNT, firstIndex, lastIndex, pivot, left, right);
			}
		}
		// 
		if (arr[pivot] > arr[right]) std::swap(arr[pivot], arr[right]); // ▲
		//std::cout << "[ C ] "; printArr(arr, COUNT, firstIndex, lastIndex, pivot, left, right);
		int split = right;

		// 2. Split recursivly
		QuickSort(arr, firstIndex, split - 1);
		QuickSort(arr, split + 1, lastIndex);
	}
}



#endif



/*==== Test Code ====
#include <iostream>
#include "9_QuickSort.h"
#include "9_MergeSort.h"
#include <string>
#define COUNT 12

struct People {
	std::string name;
	int age;
	auto getAttr() {
		return this->name;
	}
	bool operator<=(People& b) { return this->getAttr() <= b.getAttr(); };
	bool operator>=(People& b) { return this->getAttr() >= b.getAttr(); };
	bool operator<(People& b) { return this->getAttr() < b.getAttr(); };
	bool operator>(People& b) { return this->getAttr() > b.getAttr(); };
};



void P(const int* a, int count) {
	std::cout << '\n';
	for (int i = 0; i < count; i++) std::cout << a[i] << ' ';
	std::cout << '\n';
}
void P(const People a[], int count) {
	std::cout << '\n';
	for (int i = 0; i < count; i++) std::cout << a[i].name << ' ' << a[i].age << '\n';
	std::cout << '\n';
}

int main() {
	// === Test 1 ===
	int a[COUNT] = { 3, 5, 4, 6, 2, 8, 9, 10, 11, 0, 1, 7 };
	int b[COUNT] = { 99, 99, 99, 3, 7, 8, 5, 2, 1, 9, 0, 4 };
	MergeSort(a, 0, COUNT - 1);
	MergeSort(b, 0, COUNT - 1);
	P(a, COUNT);
	P(b, COUNT);


	// === Test 2 ===
	People people[5] = {
		People{"john", 23},
		People{"amy", 14},
		People{"chris", 99},
		People{"bob", 4},
		People{"boolean", 17}
	};
	MergeSort(people, 0, 4);
	P(people, 5);
	

	// === Test 3 ===
	int aa[5] = { 5, 1, 4, 2, 3 };
	MergeSort(aa, 0, 4);
	for (int i = 0; i < 5; i++) std::cout << aa[i] << ' ';
	std::cout << '\n';


	std::cout << "\n프로그램 종료\n";
}


*/