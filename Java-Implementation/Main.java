package com.company;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// Get User Input
    Solver solver = new Solver();
        //console in. Let's keep some C++ conventions for Ryan's Sanity
        Scanner cin = new Scanner(System.in);

        //Initialize the Sudoku Board
        int[][] board = new int[9][9];
        int N = board.length;

        //read in the Sudoku board
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                board[i][j] = cin.nextInt();
            }
        }

        //call the recursive solve function
        if (solver.solveSudoku(board, N))
        {
            solver.printResult(board, N);
        }
        else{
            System.out.println("No possible solution");
        }
    }
}
