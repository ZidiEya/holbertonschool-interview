#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 grid
 * @grid: The grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_unstable - Checks if the grid is unstable
 * @grid: The 3x3 grid to check
 * Return: 1 if any cell > 3, else 0
 */
static int is_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	return (0);
}

/**
 * topple - Topples unstable cells in the grid
 * @grid: The 3x3 grid to topple
 */
static void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3] = {{0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j]++;
				if (i < 2)
					temp[i + 1][j]++;
				if (j > 0)
					temp[i][j - 1]++;
				if (j < 2)
					temp[i][j + 1]++;
			}
		}
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] += temp[i][j];
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First grid and result
 * @grid2: Second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (is_unstable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
