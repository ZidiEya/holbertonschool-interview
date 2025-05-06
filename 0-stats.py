#!/usr/bin/python3
import sys
import signal

# Metrics
status_codes = {}
valid_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
line_count = 0

def print_stats():
    """Print accumulated metrics."""
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        print(f"{code}: {status_codes[code]}")

try:
    for line in sys.stdin:
        try:
            parts = line.strip().split()
            if len(parts) < 7:
                continue
            # Extract status code and file size
            status_code = parts[-2]
            file_size = int(parts[-1])

            # Update file size
            total_size += file_size

            # Update status code count
            if status_code in valid_codes:
                if status_code not in status_codes:
                    status_codes[status_code] = 0
                status_codes[status_code] += 1

            # Every 10 lines, print stats
            line_count += 1
            if line_count % 10 == 0:
                print_stats()

        except (IndexError, ValueError):
            # Skip malformed lines
            continue

except KeyboardInterrupt:
    # Handle Ctrl+C
    print_stats()
    raise

# Final stats if the input ends without interruption
print_stats()
