#!/usr/bin/python

from __future__ import print_function
import sys


def main():
    with open(sys.argv[1], 'r') as f:
        for line in f:
            # Yeah, that's shit :)
            print(','.join(map(str,sorted(list(set(map(int, line.split(','))))))))
            

if __name__ == '__main__':
    main()
