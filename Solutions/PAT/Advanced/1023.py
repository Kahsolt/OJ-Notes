#!/usr/bin/env python3
# Have Fun with Numbers (20)

n = input()
ln = [i for i in n]
ln.sort()
ln2 = [i for i in str(int(n)*2)]
ln2.sort()
print(''.join(ln) == ''.join(ln2) and 'Yes' or 'No')
print(int(n)*2)