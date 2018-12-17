#!/usr/bin/env python3
# 成绩排名 (20)

n = int(input())
l = input()
maxRecord = l
minRecord = l
maxScore = int(l.split()[2])
minScore = int(l.split()[2])

for i in range(n-1):
  l = input()
  s = int(l.split()[2])
  if s < minScore:
    minScore = s
    minRecord = l
  if s > maxScore:
    maxScore = s
    maxRecord = l
print(' '.join(maxRecord.split()[:-1]))
print(' '.join(minRecord.split()[:-1]))