#!/usr/bin/python3
"""making change project"""


def makeChange(coins, total):
    """Change comes from within"""
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    y = 0
    for coin in coins:
        y += total // coin
        total = total % coin
    if total != 0:
        return -1
    return y
