#!/usr/bin/env python3
from sys import stdout

cards = []
for k in ['S', 'H', 'C', 'D']:
  for i in range(1, 14):
    cards.append(k + str(i))
cards.extend(['J1', 'J2'])

n = int(input())
box = [int(x) - 1 for x in input().split()]
for i in range(n):
  tmp = [0] * 54
  for i in range(len(cards)):
    tmp[box[i]] = cards[i]
  cards = tmp

print(' '.join(cards))