// Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

bool checker() 
{
	return false;
}

bool sodoku() 
{

	return false;
}

std::vector<int> tokenise(std::string &str) 
{
	std::vector<int> tokens;
	std::string word = "";
	
	for (auto x : str) 
	{
		if (tokens.size > 9) 
			break;

		if (x == ' ') 
		{
			std::cout << word << std::endl;
			word = "";
		}
		else 
		{
			word = word + x;
		}

		tokens.push_back(std::stoi(word));
	}

	return tokens;
}

int main()
{
    std::cout << "Enter the numbers in order with spaces in between (e.g. 1 5 * 3). Leave a * for empty spaces..." << std::endl;
	int matrix[9][9];

	std::string args;
	//std::getline(std::cin,args);
	
	for (int i = 0; i < 9; ++i)
	{
		std::cout << "What are the numbers for the " + std::to_string(i+1) + "th line? :" << std::endl;
		std::getline(std::cin, args);

		

		//size_t pos = 0;
		//int matrix_position = 0;
		//std::string delimiter = " ";
		//
		//while ((pos = args.find(delimiter)) != std::string::npos) 
		//{
		//	matrix[i][matrix_position] = std::stoi(args.substr(0, pos));
		//	std::cout << matrix[i][matrix_position] << std::endl;
		//	args.erase(0, pos + delimiter.length());
		//	matrix_position++;

		//	if (matrix_position > 9)
		//		break;
		//}
	}


	for (int i = 0; i < 9; ++i) 
	{
		for (int j = 0; j < 9; ++j)
		{
			std::cout << matrix[i][j];
			if (j == 8)
				std::cout << std::endl;
		}
	}
	return 0;
}
