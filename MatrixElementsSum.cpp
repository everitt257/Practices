//============================================================================
// Name        : Matrix.cpp
// Author      : Xuandong Xu 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>

struct position{
	int i;
	int j;
};

void printMatrix(std::vector<std::vector<int>> matrix) {
	for(int i=0;i<matrix.size();i++) {
		for(int j=0;j<matrix[i].size();j++)
			std::cout<<matrix[i][j] << ", ";
		std::cout << std::endl;
	}
}

void printPosition(std::vector<position> locations) {
	for(int i=0;i<locations.size();i++)
		std::cout << locations[i].i << ", " << locations[i].j << std::endl;
}


std::string helloWorld(std::string name) {
    std::cout << "This prints to the console when you Run Tests" << std::endl;
    return "Hello, " + name;
}


std::vector<position> findZeros(std::vector<std::vector<int>> & matrix) {
	// find positions of zeros?
	std::vector<position> positions;
	for(int i=0;i<matrix.size();i++) {
		for(int j=0;j<matrix[i].size();j++) {
			if(matrix[i][j] == 0) {
				position location;
				location.i = i;
				location.j = j;
				positions.push_back(location);
			}
		}
	}
	return positions;
}

void ChangeZero(std::vector<std::vector<int>> & matrix, std::vector<position> & locations) {
	for(int i=0;i<locations.size();i++){
		int column = locations[i].j;
		int row = locations[i].i;
		for(int k=row+1;k<matrix.size();k++){
			matrix[k][column] = 0;
		}
	}
	printMatrix(matrix);

}

int sumMatrix(std::vector<std::vector<int>> & matrix) {
	int result = 0;
	for(int i=0;i<matrix.size();i++) {
		for(int j=0;j<matrix[i].size();j++)
			result += matrix[i][j];
	}
	return result;
}

int matrixElementsSum(std::vector<std::vector<int>> matrix) {
	std::vector<position> locations = findZeros(matrix);
	ChangeZero(matrix, locations);
	return sumMatrix(matrix);
}

int main() {
	std::vector<std::vector<int>> matrix = {{0,1,1,2},{0,5,0,0},{2,0,3,3}};
	printMatrix(matrix);
	std::vector<position> locations = findZeros(matrix);
	std::cout << "=============================" << std::endl;
	printPosition(locations);
	std::cout << "=============================" << std::endl;
	ChangeZero(matrix, locations);
	std::cout << "=============================" << std::endl;
	std::cout << "Sum of Matrix: " << sumMatrix(matrix) << std::endl;
	return 0;
}
