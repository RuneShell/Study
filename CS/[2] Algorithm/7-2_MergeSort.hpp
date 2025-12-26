// Project 7-2
// merge sort - Descending Order
// MergeSort.hpp

#ifndef _MERGESORT_H
#define _MERGESORT_H


template<typename T>
/* void Merge(array to sort, first index, mid index, last index) */
void Merge(T arr[], int first, int mid, int last) { 
    int leftCursor = first;
    int rightCursor = mid + 1;
    int tempArrCursor = 0;
    T* tempArr = new T[last - first + 1];


    // Left block과 Right block을 비교하며 [큰/작은] 순서대로 tempArr에 삽입.
    while (leftCursor <= mid && rightCursor <= last) {
        if (arr[leftCursor] <= arr[rightCursor]) { // Descending Order
            tempArr[tempArrCursor] = arr[rightCursor];
            tempArrCursor++; rightCursor++;
        } else {
            tempArr[tempArrCursor] = arr[leftCursor];
            tempArrCursor++; leftCursor++;
        }
    }
    
    // Left block 또는 Right block에서 나머지 tempArr에 삽입.
    while (leftCursor <= mid) {
        tempArr[tempArrCursor] = arr[leftCursor];
        tempArrCursor++; leftCursor++;
    }
    while (rightCursor <= last) {
        tempArr[tempArrCursor] = arr[rightCursor];
        tempArrCursor++; rightCursor++;
    }

    
    for (int i = 0; i <= last - first; i++) {
        arr[i + first] = tempArr[i];
    }
    delete[] tempArr;
}


template<typename T>
void MergeSort(T arr[], int startIndex, int endIndex) {
    if(startIndex < endIndex){
        int mid = (startIndex + endIndex) / 2;
        MergeSort(arr, startIndex, mid);
        MergeSort(arr, mid + 1, endIndex);
        Merge(arr, startIndex, mid, endIndex);
    }
}


#endif
