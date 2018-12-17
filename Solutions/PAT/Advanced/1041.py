#!/usr/bin/env python3
# Be Unique (20)

num = [int(x) for x in input().split()][1:]
n = len(num)

for i in range(0, n-1):     # [0, n-2]
  unique = True
  x = num[i]
  for j in range(i+1, n):   # [i+1, n-1]
    if num[j] == x:
      num[j] = -1
      unique = False
  if not unique:
    num[i] = -1

found = False
for _, x in enumerate(num):
  if x != -1:
    print(x)
    found = True
    break
if not found:
  print('None')