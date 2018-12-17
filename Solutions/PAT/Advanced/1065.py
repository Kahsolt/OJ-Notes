#!/usr/bin/env python3
# A+B and C (64bit) (20)

n = int(input())
for i in range(n):
  a, b, c = [int(x) for x in input().split()]
  print("Case #%d: %s" 
        % (i + 1, a + b > c and 'true' or 'false'))