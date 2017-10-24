//============================================================================
// Name        : sortByHeight.cpp
// Author      : Xuandong Xu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

void printSeq(std::vector<int> sequence) {
	for(int i=0; i<sequence.size();i++){
		std::cout << sequence[i] << " ,";
	}
	std::cout << std::endl;
}

int pivotIndex(std::vector<int> & sequence, int start, int end) {
	int i = start + 1;
	int j = end;
	int base = sequence[start];
	while(i <= j) {
		while(sequence[i] < base) {
			++i;
		}
		while(sequence[j] > base) {
			--j;
		}
		if(i <= j) {
			std::swap(sequence[i++],sequence[j--]);
		}
	}

	std::swap(sequence[start],sequence[j]); //critical, swap pivot index with meet-in-middle index

	return j;
}

void quicksort(std::vector<int> & sequence, int start, int end){
	if(start < end) {
		int pivot = pivotIndex(sequence, start, end);
		quicksort(sequence, start, pivot-1);
		quicksort(sequence, pivot + 1, end);
	}
}

void mySort(std::vector<int> & sequence) {
	int start = 0;
	int end = sequence.size() - 1;
	quicksort(sequence, start, end);
}

void sortHeights(std::vector<int> & a) {
	std::vector<int> Heights;
	std::vector<int> Locations;
	for(int i=0; i< a.size(); i++) {
		if(a[i] != -1) {
			Heights.push_back(a[i]);
			Locations.push_back(i); //locations of values;
		}
	}
	mySort(Heights);
    printSeq(Heights);
	for(int i=0; i<Locations.size(); i++){
		a[Locations[i]] = Heights[i];
	}
}

std::vector<int> sortByHeight(std::vector<int> a) {
	sortHeights(a);
	return a;
}

int main() {
	std::vector<int> sequence = {2,3,1,2,5,6,8,5};

	mySort(sequence);
	printSeq(sequence);
//	std::cout << "ended" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::vector<int> sequence2 = {-1, 150, 190, 170, -1, -1, 160, 180};
	printSeq(sequence2);
	std::vector<int> output = sortByHeight(sequence2);
	printSeq(output);
	return 0;
}

