#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
const int N = 1e4 + 5;
const int R = 105;
const int M = 1e5 + 5;
int n, m, a[M], c[R], r[N], t[N];
long long dp[N];
int sum(int l, int r) {
    return a[r] - a[l-1];
}
int main() {
    scanf("%d %d", &n, &m);
    //-------------------------
    int minR = 102;
    rep(i, 1, n) {
        scanf("%d", &r[i]);
        minR = min(minR, r[i]);
    }
    //-----------------------
    char ch;
    rep(i, 1, m) {
        scanf(" %c", &ch);
        a[i] = (ch == '1') + a[i-1];
    }
    //-----------------------
    int pos, ans;
    rep(dist, minR, 102) {
        pos = 0; ans = 0;
        while (pos < m+1) {
            int l = pos, r = min(m+1, pos + dist);
            int last = r;
            while (l < r) {
                int mi = (l+r+1) / 2;
                if (sum(mi, last) < last - mi + 1) l = mi;
                else r = mi - 1;
            }
            pos = l; ans ++;
        }
        c[dist] = ans;
        //printf("%d %d\n", dist, c[dist]);
    }
    rep(i, 1, n) t[i] = c[r[i]];
    sort(t+1, t+n+1);
    //---------------------------------
    if (n == 1) printf("%d", t[1]);
    else if (n == 2) printf("%d", t[2]);
    else {
        dp[1] = t[1];
        dp[2] = t[2];
        rep(i, 3, n) dp[i] = min(dp[i-1] + t[i] + t[1], dp[i-2] + t[i] + 2*t[2] + t[1]);
        cout << dp[n];
    }
}
