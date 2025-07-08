#!/usr/bin/python3
"""
Change comes from within
"""


def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize DP array with total+1 (acts like infinity)
    dp = [total + 1] * (total + 1)
    dp[0] = 0  # Base case

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != total + 1 else -1
