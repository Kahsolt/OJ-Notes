#!/usr/bin/env python3

M, N, K = [int(i) for i in input().split()]
for i in range(K):
  l = [int(x) for x in input().split()]
  stack = []
  num = 1
  ans = 'NO'
  while True:
    while len(l) > 0 and len(stack) > 0 and stack[-1] == l[0]:
      x = stack.pop()
      l = l[1:]
      if x == N:
        ans = 'YES'
        break
      if num == N + 1 and len(l) > 0 and len(stack) > 0:
        break
      while num != l[0] and num <= N:
        stack.append(num)
        num += 1
      if len(stack) > M:
        break
  print(ans)
