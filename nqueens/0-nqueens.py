#!/usr/bin/python3
"""N Queens puzzle solver."""
import sys


def is_safe(board, row, col, N):
    """Check if a queen can be placed at board[row][col]."""
    for r, c in board:
        if c == col or r - c == row - col or r + c == row + col:
            return False
    return True


def solve_nqueens(N, row=0, board=[]):
    """Use backtracking to find all solutions."""
    if row == N:
        print(board)
        return
    for col in range(N):
        if is_safe(board, row, col, N):
            solve_nqueens(N, row + 1, board + [[row, col]])


if __name__ == "__main__":
    # Check number of arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Validate N is an integer
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # Validate N >= 4
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Solve
    solve_nqueens(N)
