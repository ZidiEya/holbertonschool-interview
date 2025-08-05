#!/usr/bin/python3
"""Log parsing"""

import sys


def print_stats(file_size, status_counts):
    """Prints the current statistics"""
    print("File size: {}".format(file_size))
    for code in sorted(status_counts.keys()):
        print("{}: {}".format(code, status_counts[code]))


if __name__ == "__main__":
    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }
    total_size = 0
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1
            try:
                parts = line.strip().split()
                status = parts[-2]
                size = int(parts[-1])
                total_size += size
                if status in status_codes:
                    status_codes[status] += 1
            except Exception:
                pass

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise

    print_stats(total_size, status_codes)
