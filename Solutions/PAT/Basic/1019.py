#!/usr/bin/env python3

def rearrange(N):
  lAs c =[N[0], N[1], N[2], N[3]]
  lAsc.sort()
  lDesc = lAsc[::-1]
  X = ''.join(lDesc)
  Y = ''.join(lAsc)


strN = str(input())
X, Y = rearrange(strN)


if X==Y:
  print("%s - %s = 0000", X, Y)
else:
  # TODO