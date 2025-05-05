#!/usr/bin/python3
"""
Solves the N Queens puzzle using backtracking
"""

import sys


def is_safe(row, col, queens):
    """Check if a queen can be placed at (row, col)"""
    for r, c in enumerate(queens):
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve(row, n, queens):
    """Recursively solve N Queens"""
    if row == n:
        print([[r, c] for r, c in enumerate(queens)])
        return

    for col in range(n):
        if is_safe(row, col, queens):
            queens.append(col)
            solve(row + 1, n, queens)
            queens.pop()


def main():
    """Parse command line and start solving"""
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

    solve(0, n, [])


if __name__ == "__main__":
    main()
