#!/usr/bin/env python3

d = {}
for i in input():
  if i in d.keys():
    d[i] += 1
  else:
    d[i] = 1

for k in sorted(d.keys()):
  print("%s:%d" % (k, d[k]))