#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
"""

import sys

status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
status_count = {}
total_size = 0
line_count = 0


def print_stats():
    """Print accumulated metrics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_count.keys()):
        if code in status_count:
            print("{}: {}".format(code, status_count[code]))


try:
    for line in sys.stdin:
        line_count += 1
        parts = line.strip().split()

        if len(parts) >= 2:
            try:
                file_size = int(parts[-1])
                total_size += file_size
            except (ValueError, IndexError):
                pass

            status = parts[-2]
            if status in status_codes:
                if status not in status_count:
                    status_count[status] = 0
                status
