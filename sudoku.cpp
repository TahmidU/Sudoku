// sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>

bool checker() 
{
	return false;
}

std::vector<int> tokenise(const std::string &str, std::vector<int> &tokens) 
{
	std::string word = "";
	
	for (auto x : str) 
	{
		if (tokens.size() > 8) 
			break;

		if (x == ' ') 
		{
			word.clear();
		}
		else 
		{
			word = word + x;
			tokens.push_back(std::stoi(word));
		}

		//::cout << word << std::endl;
	}

	return tokens;
}

void display_matrix(const int matrix[9][9]) 
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			std::cout << matrix[i][j];
			if (j == 8)
				std::cout << std::endl;
		}
	}
}

int main()
{
    std::cout << "Enter the numbers in order with spaces in between (e.g. 1 5 0 3). Leave a 0 for empty spaces..." << std::endl;
	int matrix[9][9];

	std::string args;
	//std::getline(std::cin,args);
	
	for (int i = 0; i < 9; ++i)
	{
		std::cout << "What are the numbers for the " + std::to_string(i+1) + "th line? :" << std::endl;
		args.clear();
		std::getline(std::cin, args);

		std::vector<int> tokenised;
		tokenise(args, tokenised);
		for (int j = 0; j < 9; ++j) 
		{
			matrix[i][j] = tokenised.at(j);
		}
		tokenised.clear();
	}

	display_matrix(matrix);

	return 0;
}
