// sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "point.h"

#include <iostream>
#include <string>
#include <vector>
#include <array>

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

void input_args(std::string &args, std::array<std::array<int, 9>, 9> & matrix)
{
	for (int i = 0; i < 9; ++i)
	{
		std::cout << "What are the numbers for the " + std::to_string(i + 1) + "th line? :" << std::endl;
		args.clear();
		std::getline(std::cin, args);

		//User inputs into matrix
		tokenise(args, i, matrix);
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

//bool find_next(const std::array<std::array<int, 9>, 9> &matrix, point &curr_point)
//{
//	for (int i = 0; i < 9; ++i)
//	{
//		for (int j = 0; j < 9; ++j)
//		{
//			if (matrix[i][j] == 0)
//			{
//				curr_point = point(i, j);
//				return true;
//			}
//		}
//	}
//
//	return false;
//}
//
//bool validate(const int &num, const std::array<std::array<int, 9>, 9> & matrix, const point& curr_point)
//{
//	for (int i = 0; i < 9; ++i) 
//	{
//		if (matrix[i][curr_point.get_x()] == num)
//		{
//			return false;
//		}
//	}
//
//	for (int j = 0; j < 9; ++j)
//	{
//		if (matrix[curr_point.get_y()][j] == num)
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
//
//bool sudoku_sort(std::array<std::array<int, 9>, 9> &matrix, point &curr_point)
//{
//
//	if (find_next(matrix, curr_point)) 
//	{
//		int curr_num = matrix[curr_point.get_x()][curr_point.get_y()];
//
//		for (int i = 1; i < 10; ++i) 
//		{
//			if (i != curr_num && validate(i, matrix, curr_point))
//			{
//				matrix[curr_point.get_x()][curr_point.get_y()] = i;
//				return sudoku_sort(matrix, curr_point);
//			}
//			else
//				return false;
//				
//		}
//	}
//	else
//		return true;
//}



int main()
{
    std::cout << "Enter the numbers in order with spaces in between (e.g. 1 5 0 3 0 0 0 0 0). Leave a 0 for empty spaces..." << std::endl;

	std::array<std::array<int, 9>, 9> matrix = 
	{
		{
			{6,0,1,0,2,3,5,7,0},
			{3,7,0,0,0,0,0,0,0},
			{8,9,5,4,0,0,0,0,0},
			{1,3,0,7,0,0,0,8,0},
			{0,0,0,2,1,5,0,0,0},
			{0,2,0,0,0,9,0,4,1},
			{0,0,0,0,0,4,8,5,9},
			{0,0,0,0,0,0,0,1,7},
			{0,5,7,8,9,0,6,0,2}
		}
	};

	//std::array<std::array<int, 9>, 9> matrix;

	//takes in user inputs
	std::string args;

	//start at 0,0
	point curr_point(0,0);
	
	do
	{
		/*input_args(args, matrix);*/

		std::cout << "Is this how the board looks [y/n]? " << std::endl;
		display_matrix(matrix);
		std::getline(std::cin, args);
	} while (args != "y");

	//sudoku_sort(matrix, curr_point);

	display_matrix(matrix);

	return 0;
}
