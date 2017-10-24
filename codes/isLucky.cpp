//============================================================================
// Name        : isLucky.cpp
// Author      : Xuandong Xu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

struct Sums{
	int left;
	int right;
};

int getRemainder(int n) {
	return n/10;
}

int getDigit(int n) {
	int result = n % 10;
	return result;
}

Sums getBothSum(std::vector<int> digits) {
	Sums result;
	int len = digits.size();
	int secondHalfStart = len/2;
	int leftSum = 0;
	int rightSum = 0;
	for(int i=0;i<secondHalfStart;i++)
		leftSum += digits[i];
	for(int i=secondHalfStart;i<len;i++)
		rightSum += digits[i];
	result.left = leftSum;
	result.right = rightSum;
	return result;
}

bool isLucky(int n) {
	std::vector<int> digits;
	while(n != 0) {
		int digit = getDigit(n);
		digits.push_back(digit);
		n = getRemainder(n);
		std::cout << digit << ",";
	}
	std::cout << std::endl;
	Sums result = getBothSum(digits);
	std::cout << "left: " << result.left << " right: " << result.right << std::endl;
	if(result.left == result.right)
		return true;
	return false;
}

int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int number = 1230;
	std::cout << "9 " << getRemainder(9) << std::endl;
	std::cout << "1 " << getDigit(1) << std::endl;
	bool result = isLucky(1230);
	std::cout << "isLucky(1230): " << result << std::endl;
	return 0;
}

