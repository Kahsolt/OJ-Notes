#!/usr/bin/env python3

from sys import stdout

ls = [int(x) for x in input().split()]
FLAG = False
FIRST = True
for i in range(len(ls), 2):
  exp = ls[i] * ls[i+1]
  coeff = ls[i+1] - 1
  if exp != 0:
    if not FIRST:
      stdout.write(' ')
    stdout.write('%d %d' % (exp, coeff))
    FIRST = False
    FLAG = True
    
if not FLAG:
  stdout.write('0 0')