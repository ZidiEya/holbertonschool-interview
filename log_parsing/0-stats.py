#!/usr/bin/python3
import sys

def print_stats(total_size, status_counts):
    """Print the accumulated metrics."""
    print(f"File size: {total_size}")
    for code in sorted(status_counts.keys()):
        print(f"{code}: {status_counts[code]}")

def main():
    total_size = 0
    status_counts = {}
    valid_codes = {'200', '301', '400', '401', '403', '404', '405', '500'}
    line_counter = 0

    try:
        for line in sys.stdin:
            line = line.strip()
            parts = line.split()
            if len(parts) < 7:
                continue

            # Extract status code and file size
            try:
                status_code = parts[-2]
                file_size = int(parts[-1])
            except (ValueError, IndexError):
                continue

            # Validate and update metrics
            total_size += file_size
            if status_code in valid_codes:
                status_counts[status_code] = status_counts.get(status_code, 0) + 1

            line_counter += 1
            if line_counter % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        sys.exit(0)

    # Final stats if not interrupted
    print_stats(total_size, status_counts)

if __name__ == "__main__":
    main()
