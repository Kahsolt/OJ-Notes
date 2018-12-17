#!/usr/bin/env python3

N, M = [int(i) for i in input().split()]
l = [i for i in input().split()]
L = ' '.join(l[N-M:])
R = ' '.join(l[:N-M])
mid = (L == '' or R == '') and '' or ' '
print(L + mid + R)