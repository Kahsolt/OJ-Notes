#!/usr/bin/env python2

def getPassby(n):
    ret=[]
    while n!=1:
        if n%2==0:
            n=n/2
        else:
            n=(3*n+1)/2
        ret.append(n)
    return ret

raw_input()
numbers=list(set([int(i) for i in raw_input().split()]))
ans=[n for n in numbers]
for i in range(len(numbers)):
    passby=getPassby(numbers[i])
    for p in passby:
        if p in ans:
            ans.remove(p)
ans=[str(n) for n in ans][::-1]
print " ".join(ans)