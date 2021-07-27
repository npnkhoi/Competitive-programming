t = 'chokudai'
lt = len(t)
s = input()
ls = len(s)
MOD = 10**9+7;

dp = [[0] * (ls + 1) for i in range(lt + 1)]
dp[0] = [1] * (ls + 1)

for i in range(lt):
    for pos in range(ls):
        if s[pos] == t[i]:
            dp[i+1][pos] = dp[i][pos-1]
        else:
            dp[i+1][pos] = 0
        dp[i+1][pos] = (dp[i+1][pos] + dp[i+1][pos - 1]) % MOD;
    # print(dp[i+1])
print(dp[lt][ls-1])
