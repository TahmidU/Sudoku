// sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "point.h"

#include <iostream>
#include <string>
#include <vector>
#include <array>

void tokenise(const std::string& args, const int& row, std::array<std::array<int, 9>, 9>& matrix)
{
	std::string word = "";
	int arr_position = 0; //track array position.

	for (auto x : args)
	{
		//if positions run out then drop the others.
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

void input_args(std::string& args, std::array<std::array<int, 9>, 9>& matrix)
{
	for (int i = 0; i < 9; ++i)
	{
		std::cout << "What are the numbers for the " + std::to_string(i + 1) + "th line? :" << std::endl;
		args.clear();
		std::getline(std::cin, args);

		//user inputs into matrix
		tokenise(args, i, matrix);
	}
}

void display_matrix(const std::array<std::array<int, 9>, 9>& matrix)
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

bool find_next(const std::array<std::array<int, 9>, 9>& matrix, point& curr_point)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (matrix[i][j] == 0)
			{
				//[i][j], where i is row and j is col therefore x=j and y=i.
				curr_point = point(j, i);
				return true;
			}
		}
	}

	return false;
}

bool validate(const int& num, const std::array<std::array<int, 9>, 9>& matrix, const point& curr_point)
{
	//check rows
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i][curr_point.get_x()] == num && curr_point.get_y() != i)
		{
			return false;
		}
	}


	//check columns
	for (int j = 0; j < 9; j++)
	{
		if (matrix[curr_point.get_y()][j] == num && curr_point.get_x() != j)
		{
			return false;
		}
	}


	//check in the single 3*3 boxes to check for any clashes.
	int box_x = curr_point.get_x() - (curr_point.get_x() % 3);
	int box_y = curr_point.get_y() - (curr_point.get_y() % 3);

	for (int i = box_y; i < box_y + 3; i++)
	{
		for (int j = box_x; j < box_x + 3; j++)
		{
			if (matrix[i][j] == num && i != curr_point.get_y() && j != curr_point.get_x())
			{
				return false;
			}
		}
	}

	//if it passes all validations then its good.
	return true;
}

bool sudoku_solve(std::array<std::array<int, 9>, 9>& matrix)
{
	point curr_point(0, 0);

	//find next 0.
	if (!find_next(matrix, curr_point))
		return true;

	for (int i = 1; i <= 9; i++)
	{

		if (validate(i, matrix, curr_point))
		{
			//if its valid, apply to current position.
			matrix[curr_point.get_y()][curr_point.get_x()] = i;

			//sort for next 0. if next is unsolvable then...
			if (sudoku_solve(matrix))
				return true;

			//reset this one and try another number.
			matrix[curr_point.get_y()][curr_point.get_x()] = 0;
		}

	}

	//backtrack!
	return false;
}



int main()
{
	//zero would be our unassigned symbol since it keeps things simplier.
	std::cout << "Enter the numbers in order with spaces in between (e.g. 1 5 0 3 0 0 0 0 0). Leave a 0 for empty spaces..." << std::endl;

	//Use the stuff bellow to skip inputting into the console.

	std::array<std::array<int, 9>, 9> matrix =
	{
		{
			{0, 1, 3, 4, 2, 0, 0, 8, 6},
			{2, 0, 4, 6, 0, 0, 0, 0, 0},
			{0, 8, 7, 0, 1, 0, 3, 0, 0},
			{0, 0, 0, 0, 3, 0, 6, 0, 0},
			{0, 6, 2, 5, 0, 0, 0, 0, 3},
			{5, 0, 0, 7, 6, 4, 0, 9, 1},
			{7, 0, 0, 0, 4, 0, 8, 1, 0},
			{0, 4, 0, 8, 0, 0, 0, 6, 0},
			{0, 0, 1, 2, 5, 6, 0, 3, 7}
		}
	};

	if (sudoku_solve(matrix))
		display_matrix(matrix);

	//Uncomment the code bellow and comment the code above to manually type into the console.

	//std::array<std::array<int, 9>, 9> matrix;

	////takes in user inputs
	//std::string args;

	//do
	//{
	//	input_args(args, matrix);

	//	std::cout << "Is this how the board looks [y/n]? " << std::endl;
	//	display_matrix(matrix);
	//	std::getline(std::cin, args);
	//} while (args != "y");

	//if (sudoku_solve(matrix))
	//	display_matrix(matrix);
	//else
	//	std::cout << "No solution found. Probably mal input." << std::endl;

	return 0;
}