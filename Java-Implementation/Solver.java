package com.company;

public class Solver {



    /**
     *
     * @param board 2D array, the game board
     * @param row, move down the rows
     * @param col move across the collumns
     * @param num the individual number to be placed
     * @return bool if can be placed
     */
    public static boolean isSafe(int[][] board, int row, int col, int num)
    {
        for (int d = 0; d < board.length; d++)
        {
            if (board[row][d] == num)
            {
                return false;
            }
        }

        for (int r = 0; r < board.length; r++)
        {
            if (board[r][col] == num)
            {
                return false;
            }
       }
        return true;
    }

    /**
     *
     * @param board the Sudoku board state being passed in
     * @param n the size of the parameter (9x9 for traditional Sudoku)
     * @return true if solved, if unsolvable return false
     */

    public static boolean solveSudoku(int[][]  board, int n) {
        int row = -1;
        int col = -1;

        boolean isEmpty = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) {
                    row = i;
                    col = j;

                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) {
                break;
            }
        }
        if (isEmpty) {
            return true;
        }
        for (int num = 1; num <= n; num++)
        {
            if ((isSafe(board, row, col, num)))
            {
                board[row][col] = num;
                if (solveSudoku(board, n))
                {
                    return true;
                }
                else
                {
                    board[row][col] = 0;
                }
            }
        }
        return false;
    }

    //Iterate along the puzzle if it has been solved
    public static void printResult(int[][] board, int N)
    {
        for (int r = 0; r < N; r++)
        {
            for (int d = 0; d < N; d++)
            {
                System.out.print(board[r][d]);
                System.out.print(" ");

            }
            System.out.print("\n");

            if ((r + 1) % (int) Math.sqrt(N) == 0)
            {
                System.out.print("");
            }
        }
    }

}
