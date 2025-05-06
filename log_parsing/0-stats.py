#!/usr/bin/python3

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
