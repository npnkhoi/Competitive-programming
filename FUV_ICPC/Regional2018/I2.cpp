#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 35;

int n;
string s;
int cntL[N], cntR[N];

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    string tmp;
    cin >> n >> tmp;
    FOR(i, 0, tmp.size()-1) {
        if (i == 0) {
            s += tmp[i];
        } else {
            if (tmp[i] == '1' || (tmp[i] == '*' && tmp[i-1] != *))
        }
    }
    int m = s.size();

    int l = n / 2, r = n - l;

    FOR(mask, 0, (1 << l) - 1) {
        int idx = 0;
        FOR(i, 0, l-1) {
            int curBit = mask >> i & 1;
            if ((s[idx] == '1' && curBit) || s[idx] == '*') {
                idx ++;
            }
            if (idx >= m) break;
        }
        cntL[idx] ++;
    }

    FOR(mask, 0, (1 << r) - 1) {
        int idx = 0;
        FOR(i, 0, r-1) {
            int curBit = mask >> i & 1;
            if ((s[m - idx - 1] == '1' && curBit) || s[m - idx - 1] == '*') {
                idx ++;
            }
            if (idx >= m) break;
        }
        cntR[idx] ++;
    }

    long long res = 0;
    FOR(i, 0, m) {
        FOR(j, m-i, m) {
            res += 1LL * cntL[i] * cntR[j];
        }
    }
    cout << res;
}