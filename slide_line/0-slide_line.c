#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers to slide and merge
 * @size: size of the array
 * @direction: direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 if success, 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, fill;
	int last = 0;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		fill = 0;
		last = 0;
		for (i = 0; i < size; i++)
		{
			if (line[i] == 0)
				continue;
			if (last == 0)
				last = line[i];
			else if (last == line[i])
			{
				line[fill++] = last * 2;
				last = 0;
			}
			else
			{
				line[fill++] = last;
				last = line[i];
			}
		}
		if (last != 0)
			line[fill++] = last;
		while (fill < size)
			line[fill++] = 0;
	}
	else /* SLIDE_RIGHT */
	{
		fill = size - 1;
		last = 0;
		for (i = size; i-- > 0;)
		{
			if (line[i] == 0)
				continue;
			if (last == 0)
				last = line[i];
			else if (last == line[i])
			{
				line[fill--] = last * 2;
				last = 0;
			}
			else
			{
				line[fill--] = last;
				last = line[i];
			}
		}
		if (last != 0)
			line[fill--] = last;
		while ((int)fill >= 0)
			line[fill--] = 0;
	}
	return (1);
}
