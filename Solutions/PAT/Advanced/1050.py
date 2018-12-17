#!/usr/bin/env python3
# String Subtraction (20)

from sys import stdout

s1 = input()
s2 = input()
for i in s1:
  if not i in s2:
    stdout.write(i)