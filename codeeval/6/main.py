#!/usr/bin/python

import sys

def get_longest_common_subsequence_old(x, y):
    """
    Using dynamic programming
    """
    x_len = len(x)
    y_len = len(y)

    max_len = max_i = 0

    solution = [0 for i in range(x_len + 1)]

    for i in range(x_len):
        new_solution = [0]
        for j in range(y_len):
            if x[i] == y[j]:
                val = solution[j] + 1
            else:
                val = 0

            new_solution.append(val)
            #print "i = %d  j = %d   val = %d  max = %d  x[i] = %s  y[j] = %s" % (i, j, val, max_len,  x[i], y[j])

            if val > max_len:
                max_len = val
                max_i = i

        solution = new_solution
    
    #print "max_i = %d   max_len = %d" % (max_i, max_len)
    return x[max_i - max_len + 1: max_i+1]



def get_longest_common_subsequence(x, y):
    """
    Strange variant forr ask.com with non-contiuous seqs.
    """
    x_len = len(x)
    y_len = len(y) 

    max_len = 0
    max_seq = ''

    for i in xrange(x_len):
        for j in xrange(y_len):
            if x[i] == y[j]:
                seq = x[i] + get_longest_common_subsequence(x[i+1:], y[j+1:])
                seq_len = len(seq)
                if seq_len > max_len:
                    max_len, max_seq = seq_len, seq

    return max_seq


def main():
    with open(sys.argv[1], 'r') as f:
        for line in f:
            if not line:
                continue
            str1, str2 = line.split(';')
            print get_longest_common_subsequence(str1, str2)


if __name__ == '__main__':
    main()

