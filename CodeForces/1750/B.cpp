#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

string s;
int n;
long long cnt[2], sum[2];

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc --) {
        cnt[0] = cnt[1] = sum[0] = sum[1] = 0;

        cin >> n >> s;
        int pre = 0;
        long long res = 0;

        FOR(i, 0, (n-1)) {
            cnt[s[i] - '0'] ++;
            sum[s[i] - '0'] ++;
            while (cnt[0] > 0 && cnt[1] > 0) {
                cnt[s[pre] - '0'] --;
                pre ++;
            }
            long long tmp = max(cnt[0], cnt[1]);
            res = max(res, tmp * tmp);
        }
        res = max(res, sum[0] * sum[1]);
        cout << res << '\n';
    }
}