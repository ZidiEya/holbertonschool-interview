#!/usr/bin/python3
import sys

def print_stats(total_size, status_codes):
    """
    This function prints the total file size and the count of each status code.
    It only prints status codes that have appeared in the logs.
    """
    print(f"File size: {total_size}")
    for code in sorted(status_codes):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")

def main():
    total_size = 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            # Parse the line to extract the relevant information
            parts = line.split()
            if len(parts) != 9:
                continue  # Skip lines that don't match the format

            # Extract file size and status code
            try:
                status_code = int(parts[8])
                file_size = int(parts[7])
            except ValueError:
                continue  # Skip lines where status_code or file_size isn't an integer

            # Only count the allowed status codes
            if status_code in status_codes:
                total_size += file_size
                status_codes[status_code] += 1
                line_count += 1

            # Print stats every 10 lines or on interrupt
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        # Handle keyboard interruption (CTRL+C)
        print_stats(total_size, status_codes)
        sys.exit(0)

if __name__ == "__main__":
    main()
