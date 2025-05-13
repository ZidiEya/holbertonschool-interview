#!/usr/bin/python3
"""
Solves the N queens problem.

The N queens problem is the challenge of placing N non-attacking queens on an N×N chessboard.
"""
import sys


def is_safe(board, row, col):
    """
    Checks if a queen can be placed at board[row][col].

    Args:
        board (list of lists): The current state of the chessboard.
        row (int): The row to check.
        col (int): The column to check.

    Returns:
        bool: True if the position is safe, False otherwise.
    """
    n = len(board)
    # Check the row on the left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
        if i < 0 or j < 0:
            break
        if board[i][j] == 1:
            return False

    # Check lower diagonal on left side
    for i, j in zip(range(row + 1, n, 1), range(col - 1, -1, -1)):
        if i >= n or j < 0:
            break
        if board[i][j] == 1:
            return False

    return True


def solve_n_queens_util(board, col, solutions):
    """
    A recursive utility function to solve the N queens problem.

    Args:
        board (list of lists): The current state of the chessboard.
        col (int): The current column being considered.
        solutions (list): A list to store the solutions.

    Returns:
        bool: True if a solution is found, False otherwise.
    """
    n = len(board)
    # Base case: If all queens are placed, return True
    if col >= n:
        solution = []
        for r in range(n):
            for c in range(n):
                if board[r][c] == 1:
                    solution.append([r, c])
        solutions.append(solution)
        return True

    # Consider this column: try placing this queen in all rows one by one
    for i in range(n):
        if is_safe(board, i, col):
            # Place this queen in board[i][col]
            board[i][col] = 1

            # Make result true if any placement is done
            solve_n_queens_util(board, col + 1, solutions)

            # Backtrack: Remove the queen from board[i][col]
            board[i][col] = 0
    return False



def solve_n_queens(n):
    """
    Solves the N queens problem for a given N.

    Args:
        n (int): The size of the chessboard.

    Returns:
        list: A list of all possible solutions.
    """
    board = [[0 for _ in range(n)] for _ in range(n)]
    solutions = []
    solve_n_queens_util(board, 0, solutions)
    return solutions



if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = solve_n_queens(n)
    for solution in solutions:
        print(solution)
