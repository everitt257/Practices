//============================================================================
// Name        : AllLongestString.cpp
// Author      : Xuandong Xu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>



int findLongestLength(std::vector<std::string> inputArray){
	int maxLen = 1;
	for(int i=0; i<inputArray.size();i++){
		if(inputArray[i].size() > maxLen)
			maxLen = inputArray[i].size();
	}
	return maxLen;
}

std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
	std::vector<std::string> result;
	int maxLen = findLongestLength(inputArray);
	for(int i=0; i<inputArray.size(); i++){
		if(inputArray[i].size() == maxLen){
			result.push_back(inputArray[i]);
		}
	}
	return result;
}

int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	std::vector<std::string> teststring = {"aba", "aa", "ad", "vcd", "aba"};
	// should expect output to be ["aba", "vcd", "aba"]
	std::vector<std::string> result = allLongestStrings(teststring);
	for(int i=0;i<result.size();i++){
		std::cout << result[i] << ", ";
	}
	std::cout << std::endl;
	return 0;
}

