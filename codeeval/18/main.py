#!/usr/bin/python

from __future__ import print_function
import sys


def main():
    with open(sys.argv[1], 'r') as f:
        for line in f:
            x,n = map(int, line.split(','))
            k = 2
            while True:
                p = n*k
                if p >= x:
                    print(p)
                    break

                k += 1


if __name__ == '__main__':
    main()

