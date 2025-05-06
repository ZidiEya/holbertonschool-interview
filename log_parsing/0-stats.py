#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys
import signal

# Allowed status codes
status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
stats = {code: 0 for code in status_codes}
total_size = 0
line_count = 0

def print_stats():
    """Prints the accumulated statistics"""
    print("File size: {}".format(total_size))
    for code in sorted(stats.keys()):
        if stats[code]:
            print("{}: {}".format(code, stats[code]))

try:
    for line in sys.stdin:
        try:
            parts = line.strip().split()
            if len(parts) < 7:
                continue
            code = parts[-2]
            size = int(parts[-1])
            total_size += size
            if code in stats:
                stats[code] += 1
        except (IndexError, ValueError):
            continue

        line_count += 1
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise

print_stats()
