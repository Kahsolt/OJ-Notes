#!/usr/bin/env python3

import sys

DIGIT_LOW = [
  "tret", "jan", "feb", "mar", "apr", "may", 
  "jun", "jly", "aug", "sep", "oct", "nov", "dec"
]
DIGIT_HIGH = [
  "","tam", "hel", "maa", "huh", "tou", 
  "kes", "hei", "elo", "syy", "lok", "mer", "jou"
]

n = int(input())
for i in range(n):
  line = input()
  try:
    num=int(line)
    if num < 13:
      sys.stdout.write("%s\n" % DIGIT_LOW[num])
    else:
      sys.stdout.write("%s %s\n" % (DIGIT_HIGH[int(num/13)], DIGIT_LOW[num%13]))
  except:
    voc=line.split()
    if len(voc)==1:
      if voc[0]=='tam':
        sys.stdout.write("13\n")
      else:
        for i in range(len(DIGIT_LOW)):
          if DIGIT_LOW[i] == voc[0]:
            sys.stdout.write("%d\n" %i)
              break
    else:
      high = low = 0
        for i in range(len(DIGIT_HIGH)):
          if DIGIT_HIGH[i] == voc[0]:
            high = i
            break
            
    for i in range(len(DIGIT_LOW)):
        if DIGIT_LOW[i]==voc[1]:
            low=i
            break
    sys.stdout.write("%d\n" %(high*13+low))