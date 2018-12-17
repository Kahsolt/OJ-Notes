#!/usr/bin/env python3
# 写出这个数 (20)

from sys import stdout

words = [
  'ling', 'yi', 'er', 'san', 'si',
  'wu', 'liu', 'qi', 'ba', 'jiu',
]
s = sum([int(i) for i in input()])
for idx, i in enumerate(str(s)):
  if idx != 0:
    stdout.write(' ')
  stdout.write(words[int(i)])