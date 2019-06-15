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

bool find_next(const std::array<std::array<int, 9>, 9> &matrix, point& curr_point)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (matrix[i][j] == 0)
			{

				curr_point = point(j, i);

				return true;
			}
		}
	}

	return false;
}

bool validate(const int &num, const std::array<std::array<int, 9>, 9> & matrix, const point& curr_point)
{
	for (int i = 0; i < 9; i++) 
	{
		if (matrix[i][curr_point.get_x()] == num && curr_point.get_y() != i)
		{
			//std::cout << "x:" << curr_point.get_x() << ", y:" << curr_point.get_y() << std::endl;
			return false;
		}
	}

	for (int j = 0; j < 9; j++)
	{
		if (matrix[curr_point.get_y()][j] == num && curr_point.get_x() != j)
		{
			//std::cout << "x:" << curr_point.get_x() << ", y:" << curr_point.get_y() << std::endl;
			return false;
		}
	}

	int box_x = curr_point.get_x() / 3;
	int box_y = curr_point.get_y() / 3;

	for (int i = box_x*3; i < 3; i++)
	{
		for (int j = box_y*3; j < 3; j++)
		{
			//std::cout << "i:" << i << ", j:" << j << std::endl;
			if (matrix[i][j] == num)
			{
				//std::cout << "x:" << curr_point.get_x() << ", y:" << curr_point.get_y() << std::endl;
				return false;
			}
		}
	}

	if (matrix[curr_point.get_y()][curr_point.get_x()] != 0)
		return false;

	return true;
}

bool sudoku_sort(std::array<std::array<int, 9>, 9> &matrix)
{
	point curr_point(0,0);

	if (!find_next(matrix, curr_point))
		return true;

	for (int i = 1; i <= 9; i++)
	{

		if (validate(i, matrix, curr_point))
		{
			matrix[curr_point.get_y()][curr_point.get_x()] = i;

			if (sudoku_sort(matrix))
				return true;

			matrix[curr_point.get_y()][curr_point.get_x()] = 0;
		}

	}
	return false;
}



int main()
{
    std::cout << "Enter the numbers in order with spaces in between (e.g. 1 5 0 3 0 0 0 0 0). Leave a 0 for empty spaces..." << std::endl;

	std::array<std::array<int, 9>, 9> matrix = 
	{
		{
			{3, 0, 6, 5, 0, 8, 4, 0, 0},
			{5, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 8, 7, 0, 0, 0, 0, 3, 1},
			{0, 0, 3, 0, 1, 0, 0, 8, 0},
			{9, 0, 0, 8, 6, 3, 0, 0, 5},
			{0, 5, 0, 0, 9, 0, 6, 0, 0},
			{1, 3, 0, 0, 0, 0, 2, 5, 0},
			{0, 0, 0, 0, 0, 0, 0, 7, 4},
			{0, 0, 5, 2, 0, 6, 3, 0, 0}
		}
	};

	//std::array<std::array<int, 9>, 9> matrix;

	//takes in user inputs
	std::string args;
	
	do
	{
		/*input_args(args, matrix);*/

		std::cout << "Is this how the board looks [y/n]? " << std::endl;
		display_matrix(matrix);
		std::getline(std::cin, args);
	} while (args != "y");

	/*if (sudoku_sort(matrix, curr_point))
		display_matrix(matrix);
	else
		std::cout << "No solution found." << std::endl;*/

	sudoku_sort(matrix);
	display_matrix(matrix);

	return 0;
}
