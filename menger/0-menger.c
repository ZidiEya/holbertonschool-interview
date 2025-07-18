#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_space - Checks whether to print a space at (row, col)
 * @row: The current row index
 * @col: The current column index
 *
 * Return: 1 if it's a space, 0 otherwise
 */
int is_space(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the Menger Sponge
 *
 * Description: If level is less than 0, the function does nothing.
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_space(row, col))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
