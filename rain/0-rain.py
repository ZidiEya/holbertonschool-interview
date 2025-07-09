#!/usr/bin/python3
"""
Rain - calculates how much water will be retained after raining
"""


def rain(walls):
    """
    Calculates total amount of rainwater retained.

    Args:
        walls (list): List of non-negative integers representing wall heights.

    Returns:
        int: Total units of water retained.
    """
    if not walls or len(walls) < 3:
        return 0

    left = 0
    right = len(walls) - 1
    left_max = walls[left]
    right_max = walls[right]
    water = 0

    while left < right:
        if walls[left] < walls[right]:
            left += 1
            left_max = max(left_max, walls[left])
            water += max(0, left_max - walls[left])
        else:
            right -= 1
            right_max = max(right_max, walls[right])
            water += max(0, right_max - walls[right])

    return water
