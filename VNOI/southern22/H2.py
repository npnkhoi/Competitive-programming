import sys
MOD = 10**9 + 7

def solve(l, r, hasHead):
    # print("solving", l, r, hasHead)
    # dump cases
    # while l[0] == '0':
    #     l = l[1:]
    # while r[0] == '0':
    #     r = r[1:]
    if len(l) > len(r):
        return 0
    l = '0' * (len(r) - len(l)) + l
    n = len(l)
    if (l > r):
        return 0
    
    # recursion
    i = 0
    ret = 1
    while i < n and l[i] == r[i]:
        ret = ret * int(l[i]) % MOD
        i += 1
    if i == n:
        return ret
    elif i > 0:
        return ret * solve(l[i:], r[i:], True)
    
    cur = 1
    cand = None
    # pos_cand = False
    # print(l, r)
    for i in range(n):
        if cand is not None:
            cand *= 9
            
            if int(r[i]) > 0:
                cand2 = cur * (int(r[i]) - 1)
                cand = max(cand, cand2)
        else:
            if r[i] != l[i]:
                if r[i] != '1':
                    cand = cur * (int(r[i]) - 1)
                elif not hasHead:
                    cand = 1 # ???


        
        cur *= int(r[i])

        # print(f'at {i}, cur = {cur}, cand = {cand}')

        if cand is not None and cand >= cur:
            # print("found!", cand)
            ret = cand % MOD
            for j in range(i+1, n):
                ret = ret * 9 % MOD
            return ret
        
    return cur % MOD

tmp = []
for line in sys.stdin:
    tmp.append(line.strip())
    if len(tmp) == 2:
        break
l, r = tmp
print(solve(l, r, False))