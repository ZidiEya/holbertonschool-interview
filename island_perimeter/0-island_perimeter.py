#!/usr/bin/python3
"""
Module that defines the island_perimeter function
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    Each land cell contributes 4 to perimeter, minus 1 for each shared edge.
    """
    if not grid or not grid[0]:
        return 0

    height = len(grid)
    width = len(grid[0])
    perimeter = 0

    for row in range(height):
        for col in range(width):
            if grid[row][col] == 1:
                perimeter += 4

                # Check upper cell
                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 2
                # Check left cell
                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 2

    return perimeter
