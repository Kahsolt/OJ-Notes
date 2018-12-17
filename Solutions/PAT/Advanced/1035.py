#!/usr/bin/env python3
# Password (20)

N = int(input())
records = []
cnt = 0
for _ in range(N):
  name, pswd = input().split()
  if '1' in pswd or '0' in pswd or 'l' in pswd or 'O' in pswd:
    cnt += 1
    records.append((name, pswd.replace('1','@').replace('0','%').replace('l','L').replace('O','o')))

if cnt > 0:
  print(cnt)
  for (n, p) in records:
    print(n + ' ' + p)
else:
  print('There %s %d account%s and no account is modified' 
        % (N>1 and 'are' or 'is', N, N>1 and 's' or ''))