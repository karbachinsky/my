#!/usr/bin/python

from __future__ import print_function
import sys
print(sum(map(lambda x: int(x), open(sys.argv[1], 'r').readlines())))

