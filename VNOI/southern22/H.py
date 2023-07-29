import sys


def solve(l, r):
    if len(l) > len(r):
        return 0
    
    l = '0' * (len(r) - len(l)) + l

    n = len(l)
    l = '0' + l
    r = '0' + r

    if (l > r):
        return 0
    
    N = 10**5 + 5

    dp = [
        [
            [
                [
                    0 for _ in range(2)
                ] for _ in range(2)
            ] for _ in range (2)
        ] for _ in range(N)
    ]

    dp[0][0][0][0] = 1
    res = 0
    for i in range(1, n + 1):
        for flag1 in range(2):
            for flag2 in range(2):
                for trailing in range(2):
                    r1 = 1 if flag1 else int(l[i])
                    r2 = 9 if flag2 else int(r[i])
                    if trailing == 0:
                        if (not flag1) and (int(l[i]) != 0):
                            continue
                    
                    for num in range(r1, r2 + 1):
                        nu = num
                        if num == 0 and trailing == 0:
                            nu = 1
                        cur = dp[i][flag1][flag2][trailing]
                        cur = max(cur, dp[i - 1][flag1][flag2][trailing] * nu)
                        ok1 = (flag1 and num > int(l[i]))
                        if (ok1):
                            cur = max(cur, dp[i - 1][flag1 ^ 1][flag2][trailing] * nu)
                        
                        ok2 = (flag2 and num < int(r[i]))
                        if (ok2):
                            cur = max(cur, dp[i - 1][flag1][flag2 ^ 1][trailing] * nu)
                        ok3 = trailing
                        if (ok3):
                            cur = max(cur, dp[i - 1][flag1][flag2][trailing ^ 1] * nu)
                        if (ok1 and ok2):
                            cur = max(cur, dp[i - 1][flag1 ^ 1][flag2 ^ 1][trailing] * nu)
                        if (ok1 and ok3):
                            cur = max(cur, dp[i - 1][flag1 ^ 1][flag2][trailing ^ 1] * nu)
                        if (ok2 and ok3):
                            cur = max(cur, dp[i - 1][flag1][flag2 ^ 1][trailing ^ 1] * nu)
                        if (ok1 and ok2 and ok3):
                            cur = max(cur, dp[i - 1][flag1 ^ 1][flag2 ^ 1][trailing ^ 1] * nu)
                        
                        dp[i][flag1][flag2][trailing] = cur

                        if i == n:
                            res = max(res, cur)
                
    return res % (10**9 + 7)

tmp = []
for line in sys.stdin:
    tmp.append(line.strip())
    if len(tmp) == 2:
        break
l, r = tmp
print(solve(l, r))