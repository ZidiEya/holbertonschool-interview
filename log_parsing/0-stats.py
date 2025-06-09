#!/usr/bin/python3


import sys
import signal

# Initialize metrics
total_size = 0
status_codes = {}
valid_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
line_count = 0

def print_stats():
    """Print accumulated statistics"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        print("{}: {}".format(code, status_codes[code]))

try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()

        if len(parts) < 9:
            continue

        # Extract status code and file size
        code = parts[-2]
        size = parts[-1]

        try:
            total_size += int(size)
        except ValueError:
            continue

        if code in valid_codes:
            status_codes[code] = status_codes.get(code, 0) + 1

        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise

print_stats()
