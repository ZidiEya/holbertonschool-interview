#!/usr/bin/python3
"""
Calculates the fewest number of operations to reach n 'H' characters
using Copy All and Paste operations.
"""


def minOperations(n):
    """
    Determine the minimum number of operations to get n 'H's.

    Parameters:
        n (int): Target number of H characters.

    Returns:
        int: Minimum operations to reach n H's, or 0 if impossible.
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
