#!/usr/bin/python3
"""
Solves the N Queens problem using backtracking.
"""

import sys


def is_safe(queens, row, col):
    """Check if placing a queen at (row, col) is safe."""
    for r, c in queens:
        if c == col or abs(row - r) == abs(col - c):
            return False
    return True


def solve_nqueens(n, row=0, queens=[]):
    """Recursively solve the N Queens problem."""
    if row == n:
        print(queens)
        return

    for col in range(n):
        if is_safe(queens, row, col):
            solve_nqueens(n, row + 1, queens + [[row, col]])


def main():
    """Main entry point for the script."""
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

    solve_nqueens(n)


if __name__ == "__main__":
    main()
