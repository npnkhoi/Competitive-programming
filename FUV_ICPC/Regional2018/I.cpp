#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 35;

int n;
string s;
int cntL[N], cntR[N];

int nxt(int x) {
    string t = s.substr(0, x);
    char nxtChar = ((s[x] - '0') ^ 1) + '0';
    t += nxtChar;

    
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> n >> s;
    int m = s.size();
    
    dp[0][0] = 1;

    FOR(i, 0, n-1) {
        FOR(x, 0, m - 1) {
            if (x == m || s[x] == '*') {
                dp[i+1][x+1] += 2 * dp[i][x];
            } else {
                dp[i+1][x+1] += dp[i][x];
                dp[i+1][nxt(x)] += dp[i][x];
            }
        }
    }
    cout << dp[n][m];
}