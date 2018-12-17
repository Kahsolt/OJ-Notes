#!/usr/bin/env python3
# Dating (20)

WEEK = [ "MON","TUE","WED","THU","FRI","SAT","SUN" ]

l1 = input()
l2 = input()
if len(l1) > len(l2):
  l1, l2 = l2, l1

i = 0
while i < len(l1):
  if l1[i] == l2[i] and 'A' <= l1[i] <= 'G':
    break
  else:
    i += 1

ans = ''
ans += WEEK[ord(l1[i]) - ord('A')]
ans += ' '

i += 1
while i < len(l1):
  if l1[i] == l2[i] and 'A' <= l1[i] <= 'N':
    break
  else:
    i += 1
if '0' <= l1[i] <= '9':
  ans += '0'
  ans += l1[i]
else:
  ans += str(10 + ord(l1[i]) - ord('A'))
ans += ':'

l1 = input()
l2 = input()
if len(l1) > len(l2):
  l1, l2 = l2, l1

i = 0
while i < len(l1):
  if l1[i] == l2[i] and 'a' <= l1[i] <= 'z' or 'A' <= l1[i] <= 'Z':
    break
  else:
    i+=1
if i < 10:
  ans += '0'
ans += str(i)

print(ans)