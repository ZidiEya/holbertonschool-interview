#!/usr/bin/python3
"""
Determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    Checks if a list of integers represents a valid UTF-8 encoding.

    Args:
        data (list): List of integers representing bytes (0-255)

    Returns:
        bool: True if valid UTF-8, False otherwise
    """
    n_bytes = 0

    for num in data:
        byte = num & 0xFF  # Only consider least 8 bits

        if n_bytes == 0:
            # Count leading 1's for a new UTF-8 character
            mask = 0x80
            while mask & byte:
                n_bytes += 1
                mask >>= 1

            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            # Check that the byte starts with '10'
            if not (byte & 0x80 and not (byte & 0x40)):
                return False

        n_bytes -= 1

    return n_bytes == 0
