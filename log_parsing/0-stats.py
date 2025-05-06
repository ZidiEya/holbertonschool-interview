#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics.
Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C),
prints the statistics from the beginning:
Total file size: File size: <total size>
Number of lines by status code:
possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
if a status code doesn’t appear or is not an integer, don’t print anything
for this status code
format: <status code>: <number>
status codes should be printed in ascending order
"""
import sys
import re

if __name__ == "__main__":
    total_size = 0
    status_counts = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0,
    }
    line_count = 0

    try:
        for line in sys.stdin:
            line = line.strip()
            pattern = r'^(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[(.*?)\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'
            match = re.match(pattern, line)
            if match:
                status_code = int(match.group(3))
                file_size = int(match.group(4))
                if status_code in status_counts:
                    status_counts[status_code] += 1
                    total_size += file_size

            line_count += 1
            if line_count % 10 == 0:
                print("File size: {}".format(total_size))
                for code in sorted(status_counts.keys()):
                    if status_counts[code] > 0:
                        print("{}: {}".format(code, status_counts[code]))

    except KeyboardInterrupt:
        print("File size: {}".format(total_size))
        for code in sorted(status_counts.keys()):
            if status_counts[code] > 0:
                print("{}: {}".format(code, status_counts[code]))
    finally:
        pass
