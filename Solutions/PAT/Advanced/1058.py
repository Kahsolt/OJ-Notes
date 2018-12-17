#!/usr/bin/env python3
# A+B in Hogwarts (20)

from sys import stdout

a, b = input().split()
ga, sa, ka = [int(i) for i in a.split('.')]
gb, sb, kb = [int(i) for i in b.split('.')]
kr = ka + kb
sr = sa + sb
gr = ga + gb

sr += kr // 29
kr %= 29
gr += sr // 17
sr %= 17
stdout.write("%d.%d.%d" % (gr, sr, kr))