from collections import defaultdict

MOD = 1000000007

def A(x):
    r = 1
    for i in range(1,x+1):
        r *= i
    return r

def solution(S):
    if S is None: return 0
    L = len(S)
    if L == 0: return 0

    cntV = 0
    cnt = defaultdict(int)
    for s in S:
        cnt[s] += 1
        if s in ['A', 'E', 'I', 'O', 'U']:
            cntV += 1
    cntC = L - cntV

    if not (cntC == cntV or cntC == cntV + 1):
        return 0

    r = A(cntC) * A(cntV)
    s = 1
    for _, v in cnt.items():
        s *= A(v)
    return r // s % MOD

print(solution(""))
print(solution("A"))
print(solution("C"))
print(solution("BAR"))
print(solution("AABB"))
print(solution("AABCY"))
print(solution("AAAB"))
print(solution("AABBAABBAABBAABBAABBAABB"))
print(solution("AABBAABBAABBAABBAABBAABBC"))
print(solution("AABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABB"))
print(solution("AABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBC"))
