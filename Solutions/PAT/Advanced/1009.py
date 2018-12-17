#!/usr/bin/env python3
# Product of Polynomials (25)

poly1 = [x for x in input().split()][1:]
poly2 = [x for x in input().split()][1:]

d1 = {}
for i in range(0, len(poly1), 2):
  d1[int(poly1[i])] = float(poly1[i+1])
d2 = {}
for i in range(0, len(poly2), 2):
  d2[int(poly2[i])] = float(poly2[i+1])
d = {}
for k1 in d1:
  for k2 in d2:
    if k1+k2 in d.keys():
      d[k1+k2] += d1[k1] * d2[k2]
    else:
      d[k1+k2] = d1[k1] * d2[k2]

from sys import stdout
stdout.write("%d " % (len(d)))
cnt = 0
for e in sorted(d.keys(), reverse=True):
  if cnt != 0:
    stdout.write(' ')
  cnt += 1
  if d[e] > 1e-5:
    stdout.write("%d %0.1f" % (e, d[e]))