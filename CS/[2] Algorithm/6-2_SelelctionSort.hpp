// Project 6-2
// selection sort with tag
// SelectionSort.hpp
#include <iostream>
using namespace std;

namespace StudentNS{
	struct Student{
		int ID;
		char name[10];
		float GPA;
	};

	enum KEY { ID, NAME, GPA };
	const int MAX_ITEM = 10;
}

using namespace StudentNS;

// values: array of address of Student (INDEX)
void tagSortPointer(Student* values[], int numValues, KEY keyType){
	//sorting by comparing according to the received keyType.
	//Implement it recursively by referring to the sequential search implemented with recursion in the lecture materials.

	int minIdx = 0;

	switch (keyType)
	{
	case ID:
		////////////
		for (int i = 1; i < numValues; i++) {
			if (values[i]->ID < values[minIdx]->ID) {
				minIdx = i;
			}
		}
		std::swap(values[0], values[minIdx]);

		break;
	case NAME:
		////////////
		for (int i = 1; i < numValues; i++) {
			if (strcmp(values[minIdx]->name, values[i]->name) == 1) {
				minIdx = i;
			}
		}
		std::swap(values[0], values[minIdx]);

		break;
	case GPA:
		////////////
		for (int i = 0; i < numValues; i++) {
			if (values[i]->GPA < values[minIdx]->GPA) {
				minIdx = i;
			}
		}
		std::swap(values[0], values[minIdx]);
		break;
	}

	if (numValues > 2) tagSortPointer(values + 1, numValues - 1, keyType);
}

void PrintPtrArray(Student* values[])
{
	for (int i = 0; i < MAX_ITEM; i++)
		cout << values[i]->ID << " " << values[i]->name << " " << values[i]->GPA << endl;
	cout << endl;
}
