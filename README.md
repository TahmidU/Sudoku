# Soduku

Sudoku solver console application made using C++. Simply enter the numbers in each line or hard code the numbers into the 2D matrix array.

## Installation
C++ Compiler required. Specifically, the Microsoft C++ Compiler (MSVC).

## Usage

Hardcode the matrix like so:

```matrix-hardcode
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
```
Alternatively, comment everything in main (besides the return 0 statement) and uncomment:

```console-input
	std::cout << "Enter the numbers in order with spaces in between (e.g. 1 5 0 3 0 0 0 0 0). Leave a 0 for empty spaces..." << std::endl;

	std::array<std::array<int, 9>, 9> matrix;

	std::string args;

	do
	{
		input_args(args, matrix);

		std::cout << "Is this how the board looks [y/n]? " << std::endl;
		display_matrix(matrix);
		std::getline(std::cin, args);
	} while (args != "y");

	if (sudoku_solve(matrix))
		display_matrix(matrix);
	else
		std::cout << "No solution found. Probably mal input." << std::endl;

```
Then run the code from either the terminal (use one of command prompt provided by visual studio to load the vcvarsall.bat then type: cl sudoku.cpp and run the exe) or from the the visual studio IDE.

## License
[MIT](https://choosealicense.com/licenses/mit/)
