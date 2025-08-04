#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys

def print_stats(total_size, status_codes):
    """Prints the metrics"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes):
        print("{}: {}".format(code, status_codes[code]))

if __name__ == "__main__":
    total_size = 0
    status_codes = {}
    valid_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.strip().split()

            try:
                status_code = parts[-2]
                file_size = int(parts[-1])
                total_size += file_size

                if status_code in valid_codes:
                    if status_code not in status_codes:
                        status_codes[status_code] = 0
                    status_codes[status_code] += 1

            except (IndexError, ValueError):
                continue  # skip malformed lines

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        pass
    finally:
        print_stats(total_size, status_codes)
