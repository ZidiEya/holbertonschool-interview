#!/usr/bin/python3
"""Solves the N Queens problem using backtracking"""

import sys


def is_safe(board, row, col, N):
    """
    Check if a queen can be placed at board[row][col].
    It checks the column, and both diagonals.
    """
    # Check column
    for i in range(row):
        if board[i] == col:
            return False

    # Check diagonal (upper-left)
    for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
        if board[i] == j:
            return False

    # Check diagonal (upper-right)
    for i, j in zip(range(row - 1, -1, -1), range(col + 1, N)):
        if board[i] == j:
            return False

    return True


def solve_nqueens(N, row, board):
    """
    Recursive backtracking function to place queens row by row.
    """
    if row == N:
        # Convert solution to required format: [[row, col], ...]
        solution = [[i, board[i]] for i in range(N)]
        print(solution)
        return

    for col in range(N):
        if is_safe(board, row, col, N):
            board[row] = col
            solve_nqueens(N, row + 1, board)


def main():
    """
    Main function: checks arguments, calls solver.
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [-1] * N
    solve_nqueens(N, 0, board)


if __name__ == "__main__":
    main()
