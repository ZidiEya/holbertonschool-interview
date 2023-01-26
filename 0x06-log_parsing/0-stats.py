#!/usr/bin/python3
"""
script that reads stdin line
by line and computes metrics:
"""
from sys import stdin


state_code = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

size = 0


def print_list():
    """the total file size"""
    print("File size: {}".format(size))
    for key in sorted(state_code.keys()):
        if state_code[key]:
            print("{}: {}".format(key, state_code[key]))


if __name__ == "__main__":
    count = 0
    try:
        for line in stdin:
            try:
                getdata = line.split()
                size += int(getdata[-1])
                key_statucode = getdata[-2]
                if key_statucode in state_code:
                    state_code[key_statucode] += 1
            except:
                pass
            if count == 9:
                print_list()
                count = -1
            count += 1
    except KeyboardInterrupt:
        print_list()
        raise
    print_list()
