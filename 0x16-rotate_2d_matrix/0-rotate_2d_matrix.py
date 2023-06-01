#!/usr/bin/python3
"""
func matrix rotation
"""


def rotate_2d_matrix(matrix):
    """ rotates a 2d matrix """
    tmp = [i[:] for i in matrix]
    i, j = int(), int()
    while j < len(tmp):
        for k in range(len(tmp) - 1, -1, -1):
            matrix[i][len(tmp) - 1 - k] = tmp[k][j]
        j += 1
        i += 1
