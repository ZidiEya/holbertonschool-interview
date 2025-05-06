#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
"""

import sys
import signal

# Valid status codes
status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
status_count = {}
total_size = 0
line_count = 0


def print_stats():
    """Print accumulated metrics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_count.keys()):
        print("{}: {}".format(code, status_count[code]))


try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()

        # Basic format check
        if len(parts) >= 9:
            status = parts[-2]
            file_size = parts[-1]

            # Try parsing file size
            try:
                total_size += int(file_size)
            except ValueError:
                pass

            # Count valid status codes
            if status in status_codes:
                status_count[status] = status_count.get(status, 0) + 1

        # Print stats every 10 lines
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise

print_stats()
