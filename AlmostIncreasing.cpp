//============================================================================
// Name        : AlmostIncreasing.cpp
// Author      : Xuandong Xu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

struct NegPair{
	int count;
	int lastIndex;
};

std::vector<int> differenceSeq(std::vector<int> sequence) {
	std::vector<int> secondSeq;
	int seqsize = sequence.size();
	if(seqsize > 1) {
		for(int i=1; i<seqsize;i++){
			int data = (sequence[i]-sequence[i-1]);
			secondSeq.push_back(data);
		}
	}
	else {
		secondSeq = sequence;
	}
	return secondSeq;
}

NegPair MoreOneNegative(std::vector<int> sequence) {
	// here should modify it to count both Negative and the zeros!
	int count = 0;
	int lastIndex = -1;
	for(int i=0;i<sequence.size();i++){
		if(sequence[i] <= 0) {
			count++;
			lastIndex = i;
		}
	}
	NegPair returnPair;
	returnPair.count = count;
	returnPair.lastIndex = lastIndex;
	return returnPair;
}

bool mergeDiffSeq(int loc, std::vector<int> sequence) {
	int locPrev = loc - 1;
	int locNext = loc + 1;
	int mergeLeft = sequence[loc] + sequence[locPrev];
	int mergeRight = sequence[loc] + sequence[locNext];
	if(mergeLeft <= 0 && mergeRight <= 0) {
		return false;
	}
	else
		return true;
}

bool isAlmostIncreasing(std::vector<int> sequence) {
	// First, check if there's more than one negatives
	NegPair MoreN = MoreOneNegative(sequence);
	if(MoreN.count > 1)
		return false;
	// Secondly, if there's one negative
	else if(MoreN.count == 1) {
		int position = MoreN.lastIndex;
		// if this position is at either end, it's okay since we can get rid of it
		if(position == 0 || position == sequence.size()-1){
			return true;
		}
		// if this position is in the middle, getting rid of it will cause the diff seq change
		else
			return mergeDiffSeq(position, sequence);
	}
	else
		return true;
}

bool almostIncreasingSequence(std::vector<int> sequence) {
	std::vector<int> outputSeq = differenceSeq(sequence);
	NegPair MoreN = MoreOneNegative(outputSeq);
	return isAlmostIncreasing(outputSeq);
}

void printSeq(std::vector<int> sequence) {
	for(int i=0; i<sequence.size();i++){
		std::cout << sequence[i] << " ,";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> testSeq = {1,2,1,2};
	std::vector<int> outputSeq = differenceSeq(testSeq);
	printSeq(outputSeq);
	NegPair MoreN = MoreOneNegative(outputSeq);
	std::cout << "Negative count: " << MoreN.count << std::endl;
	std::cout << "Last Negative Index: " << MoreN.lastIndex << std::endl;
	bool result = isAlmostIncreasing(outputSeq);
	std::cout << "is Almost Increasing: " << result << std::endl;
	std::cout << "last testing: " << almostIncreasingSequence(testSeq) << std::endl;
	return 0;
}
