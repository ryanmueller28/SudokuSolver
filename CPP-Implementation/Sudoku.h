#include <iostream>
#include <cstdlib>

using namespace std;

//unassigned if a cell is empty
#define UNASSIGNED 0

//size of grid
#define N 9

class Sudoku{
private:
    bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
    bool isSafe(int grid[N][N], int row, int col, int num);
    bool UsedInRow(int grid[N][N], int row, int num);
    bool UsedInCol(int grid[N][N], int col, int num);
    bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
    void printGrid(int grid[N][N]);
    bool SolveSudoku(int grid[N][N]);

public:
    Sudoku();
    ~Sudoku(){};
};


/* Takes an unsolved sudoku puzzle
and attempts to solve it if it's possible
Calls itself recursively if it is possible and safe to
place a number in a row, column, and block*/
bool Sudoku::SolveSudoku(int grid[N][N]) 
{ 
	int row, col; 

	// If there is no unassigned location, 
	// we are done 
	if (!FindUnassignedLocation(grid, row, col)) 
	return true; // success! 

	// consider digits 1 to 9 
	for (int num = 1; num <= 9; num++) 
	{ 
		// if looks promising 
		if (isSafe(grid, row, col, num)) 
		{ 
			// make tentative assignment 
			grid[row][col] = num; 

			// return, if success, yay! 
			if (SolveSudoku(grid)) 
				return true; 

			// failure, unmake & try again 
			grid[row][col] = UNASSIGNED; 
		} 
	} 
	return false; // this triggers backtracking 
} 

/* Searches the sudoku grid 9x9 for any value with the 
UNASSIGNED variable still*/
bool Sudoku::FindUnassignedLocation(int grid[N][N], 
							int &row, int &col) 
{ 
	for (row = 0; row < N; row++) 
		for (col = 0; col < N; col++) 
			if (grid[row][col] == UNASSIGNED) 
				return true; 
	return false; 
} 

/* Checks to see if a number is in a row*/
bool Sudoku::UsedInRow(int grid[N][N], int row, int num) 
{ 
	for (int col = 0; col < N; col++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Checks to see if a number is in a column */
bool Sudoku::UsedInCol(int grid[N][N], int col, int num) 
{ 
	for (int row = 0; row < N; row++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Searches within a 3x3 for a given number
if it's okay to put it there, YAY!*/
bool Sudoku::UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) 
{ 
	for (int row = 0; row < 3; row++) 
		for (int col = 0; col < 3; col++) 
			if (grid[row + boxStartRow] 
					[col + boxStartCol] == num) 
				return true; 
	return false; 
} 

/*Is the number we're about to place 
good to go here?*/
bool Sudoku::isSafe(int grid[N][N], int row, 
				int col, int num) 
{ 
	/* Check if 'num' is not already placed in 
	current row, current column and current 3x3 box */
	return !UsedInRow(grid, row, num) && 
		!UsedInCol(grid, col, num) && 
		!UsedInBox(grid, row - row % 3 , 
					col - col % 3, num) && 
			grid[row][col] == UNASSIGNED; 
} 

/* Um...The name of the function is obvious*/
void Sudoku::printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) 
	{ 
	for (int col = 0; col < N; col++)
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
}

/**
 * The constructor class that gets called in main. 
 * By copying a Sudoku puzzle with the documented format
 * the algorithm will solve it.
 * */

Sudoku::Sudoku()
{
    int grid[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> grid[i][j];
        }
    }

    if (SolveSudoku(grid) == true)
    {
        std::cout << "\n\n";
        printGrid(grid);
    }else
    {
        printf("No solution exists.");
    }
    
}
