#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.
    
    Args:
        boxes (list of list of int): A list where each index represents a box,
                                     and each box contains a list of keys.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    if not isinstance(boxes, list) or not all(isinstance(box, list) for box in boxes):
        return False

    n = len(boxes)
    if n == 0:
        return False
    if n == 1:
        return True

    opened = set([0])
    keys = set(boxes[0])

    while keys:
        key = keys.pop()
        if 0 <= key < n and key not in opened:
            opened.add(key)
            keys.update(boxes[key])

    return len(opened) == n
