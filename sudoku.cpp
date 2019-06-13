// sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>
#include <array>

bool checker() 
{
	return false;
}

void tokenise(const std::string &args, const int &row, std::array<std::array<int,9>,9> &matrix) 
{
	std::string word = "";
	int arr_position = 0; //Track array position.
	
	for (auto x : args) 
	{
		//If positions run out then drop the others.
		if (arr_position > 8) 
			break;

		if (x == ' ') 
		{
			word.clear();
		}
		else 
		{
			//if char thats not a space is detected, add it to the word.
			word = word + x;
			matrix[row][arr_position] = std::stoi(word);
			arr_position++;
		}
	}
}

void display_matrix(const std::array<std::array<int,9>,9> &matrix) 
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			std::cout << matrix[i][j];
			if (j == 8)
				std::cout << std::endl;
			else
				std::cout << ", ";
		}
	}
}

int main()
{
    std::cout << "Enter the numbers in order with spaces in between (e.g. 1 5 0 3). Leave a 0 for empty spaces..." << std::endl;

	//std::array<std::array<int, 9>, 9> matrix = 
	//{
	//	{
	//		{1,1,1,1,1,1,1,1,1},
	//		{2,2,2,2,2,2,2,2,2},
	//		{2,2,2,2,2,2,2,2,2},
	//		{2,2,2,2,2,2,2,2,2},
	//		{2,2,2,2,2,2,2,2,2},
	//		{2,2,2,2,2,2,2,2,2},
	//		{2,2,2,2,2,2,2,2,2},
	//		{2,2,2,2,2,2,2,2,2},
	//		{3,3,3,3,3,3,3,3,3}
	//	}
	//};

	std::array<std::array<int, 9>, 9> matrix;

	//Takes in user inputs
	std::string args;
	
	for (int i = 0; i < 9; ++i)
	{
		std::cout << "What are the numbers for the " + std::to_string(i+1) + "th line? :" << std::endl;
		args.clear();
		std::getline(std::cin, args);

		//User inputs into matrix
		tokenise(args, i, matrix);
	}

	display_matrix(matrix);

	return 0;
}
