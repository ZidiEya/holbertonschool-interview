#!/usr/bin/python3
"""Log parsing script"""

import sys

def print_stats(total_size, status_codes):
    """Prints the total file size and number of lines per status code"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        print("{}: {}".format(code, status_codes[code]))

def main():
    total_size = 0
    status_counts = {}
    valid_status_codes = {'200', '301', '400', '401', '403', '404', '405', '500'}
    line_count = 0

    try:
        for line in sys.stdin:
            try:
                parts = line.strip().split()
                if len(parts) < 7:
                    continue

                status_code = parts[-2]
                file_size = int(parts[-1])

                total_size += file_size

                if status_code in valid_status_codes:
                    if status_code not in status_counts:
                        status_counts[status_code] = 0
                    status_counts[status_code] += 1

                line_count += 1
                if line_count % 10 == 0:
                    print_stats(total_size, status_counts)

            except (ValueError, IndexError):
                continue

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise
