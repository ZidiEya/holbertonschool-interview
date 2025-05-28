#!/usr/bin/python3
"""Solves the N Queens puzzle"""


import sys


def is_safe(queens, row, col):
    """Check if it's safe to place a queen at (row, col)"""
    for r in range(row):
        c = queens[r]
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve(queens, row, n):
    """Backtracking solution"""
    if row == n:
        print([[r, queens[r]] for r in range(n)])
        return

    for col in range(n):
        if is_safe(queens, row, col):
            queens[row] = col
            solve(queens, row + 1, n)


def nqueens(n):
    """Initialize and start solving"""
    queens = [-1] * n
    solve(queens, 0, n)


if __name__ == "__main__":
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

    nqueens(N)
