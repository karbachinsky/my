#!/usr/bin/python

from __future__ import print_function
import sys

def parse_list(list_str):
    return map(int, list_str.split(','))


def main():
    with open(sys.argv[1], 'r') as f:
        for line in f:
            list1, list2 = map(parse_list, line.split(';'))

            intersactions = list(set(list1) & set(list2))

            print(','.join(map(str, intersactions)))  


if __name__ == '__main__':
    main()
