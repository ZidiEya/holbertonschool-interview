#!/usr/bin/python3
"""Solves the N Queens problem."""
import sys


def is_safe(row, col, solution):
    """Check if placing a queen at (row, col) is safe from attack."""
    for r in range(row):
        c = solution[r]
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve_nqueens(n, row=0, solution=[]):
    """Recursively solve the N Queens problem."""
    if row == n:
        print([[r, solution[r]] for r in range(n)])
        return
    for col in range(n):
        if is_safe(row, col, solution):
            solution.append(col)
            solve_nqueens(n, row + 1, solution)
            solution.pop()


def main():
    """Main entry point for the program."""
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
