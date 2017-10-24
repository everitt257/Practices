//============================================================================
// Name        : commonCharacterCount.cpp
// Author      : Xuandong Xu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>

bool foundInMap(char c, std::map<char,int> mymap) {
	if(mymap.find(c) != mymap.end())
		return true;
	else
		return false;
}

std::map<char,int> stringCountMap(std::string s) {
	std::map<char,int> mymap;
	for(int i=0; i<s.size(); i++){
		// if character found in map
		if(foundInMap(s[i],mymap)) {
			mymap[s[i]] += 1;
		}
		// create new key value pair in map
		else {
			mymap[s[i]] = 1;
		}
	}
	return mymap;
}

int getCommonCount(std::map<char,int> & map1, std::map<char,int> & map2) {
	// define two iterator
	std::map<char,int>::iterator it;
	std::map<char,int>::iterator end;
	std::map<char,int> secondMap;

	// decide begining and ending
	if(map1.size() < map2.size()) {
		it = map1.begin();
		end = map1.end();
		secondMap = map2;
	}
	else {
		it = map2.begin();
		end = map2.end();
		secondMap = map1;
	}

	// define return sum
	int sum = 0;
	for(; it != end; ++it){
		char firstMapChar = it->first;
		int firstMapCharCount = it->second;
		if(foundInMap(firstMapChar, secondMap)) {
			// compare them, add the smallest one to sum
			sum += (firstMapCharCount < secondMap[firstMapChar]) ? firstMapCharCount:secondMap[firstMapChar];

		}
	}
	return sum;
}

void printMap(std::map<char, int> mymap) {
	std::map<char, int>::iterator it = mymap.begin();
	for(;it != mymap.end(); ++it){
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

int commonCharacterCount(std::string s1, std::string s2) {
	std::map<char,int> map1 = stringCountMap(s1);
	std::map<char,int> map2 = stringCountMap(s2);
	return getCommonCount(map1, map2);
}

int main() {
	std::string s1 = "abcccdda";
	std::string s2 = "abc";
	std::map<char,int> map1 = stringCountMap(s1);
	printMap(map1);
	std::cout << "------------" << std::endl;
	std::map<char,int> map2 = stringCountMap(s2);
	printMap(map2);
	std::cout << "------------" << std::endl;
	int sumcount = commonCharacterCount(s1,s2);
	std::cout << "sum count: " << sumcount << std::endl;
	return 0;
}

