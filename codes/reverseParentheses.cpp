//============================================================================
// Name        : reverseParantheses.cpp
// Author      : Xuandong Xu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
For string s = "a(bc)de", the output should be
reverseParentheses(s) = "acbde".
 */

#include <iostream>
#include <string>
#include <stack>

struct bracket{
	char type;
	int pos;
};

std::string reverse(std::string s) {
	std::string newS;
	for(int i=s.size()-1; i>-1; i--)
		newS.push_back(s[i]);
	return newS;
}

std::string reverseParentheses(std::string s) {
	std::stack<bracket> store;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '(') {
			// if opening bracket found, push it upon stack
			bracket myBracket;
			myBracket.pos = i;
			myBracket.type = s[i];
			store.push(myBracket);
		}
		else if(s[i] == ')' && !store.empty()) {
			// if closing bracket found, remove last opening from stack
			bracket lastOpen = store.top();
			store.pop();
			int startIndex = lastOpen.pos;
			int endIndex = i;
			std::string revSub = reverse(s.substr(startIndex,endIndex-startIndex+1));
			std::cout << "reverseSub: " << revSub << std::endl;
			s.replace(startIndex, endIndex-startIndex+1,revSub);
		}
	}

	std::string output;
	for(int i=0;i<s.size();i++){
		if(s[i] == '(' || s[i] == ')')
			continue;
		output += s[i];
	}
	return output;
}

/*
 SOlution:
 scan from left to right, if openig symbol add to the list,
 if closing symbol, remove last closing symbol
Input:
s: "abc(cba)ab(bac)c"
Output:
"abcbaccbaabc"
Expected Output:
"abcabcabcabc"
 */
int main() {
	std::string input[] = {"a(bcdefghijkl(mno)p)q","abc(cba)ab(bac)c"};
	std::string expected[] {"apmnolkjihgfedcbq", "abcabcabcabc"};
	std::cout << input[0] << std::endl;
	std::string output = reverseParentheses(input[0]);
	std::cout << "output: " << output << std::endl;
	return 0;
}

