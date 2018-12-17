#!/usr/bin/env python3

highScore, highName, highID = -1, None, None
lowSocre, lowName, lowID = 101, None, None

N = int(input())
for i in range(N):
  line = input().split()
  score = int(line[3])
  if line[1] == "F" and score > highScore:
    highScore = score
    highName, highID = line[0], line[2]
  elif line[1] == "M" and score < lowSocre:
    lowSocre = score
    lowName, lowID = line[0], line[2]

if highName and highID:
  print("%s %s" % (highName, highID))
else:
  print("Absent")

if lowName and lowID:
  print("%s %s" % (lowName, lowID))
else:
  print("Absent\n")

if highScore != -1 and lowSocre != 101:
  print(str(highScore - lowSocre))
else:
  print("NA")