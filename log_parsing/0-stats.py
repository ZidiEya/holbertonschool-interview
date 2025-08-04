#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
"""

import sys

def print_stats(total_size, status_counts):
    """Prints accumulated statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        print("{}: {}".format(code, status_counts[code]))

status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
status_counts = {}
total_size = 0
line_count = 0

try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) >= 7:
            status_code = parts[-2]
            file_size = parts[-1]

            # Validate and accumulate file size
            try:
                total_size += int(file_size)
            except Exception:
                continue

            # Validate and count status code
            if status_code in status_codes:
                if status_code not in status_counts:
                    status_counts[status_code] = 0
                status_counts[status_code] += 1

            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

except KeyboardInterrupt:
    pass
finally:
    print_stats(total_size, status_counts)
