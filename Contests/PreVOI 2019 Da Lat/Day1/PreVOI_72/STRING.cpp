#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>
#include <complex>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i,b,a) for (int i = b; i >= a; --i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a << '\n'

#define task "STRING"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> pll;
typedef vector<int> vi;
typedef vector<pll> hashArr;

const int L = 1e6 + 5, N = 1e6, BASE1 = 37, BASE2 = 41;

int q, n;
string s[N], str;
hashArr h[N];
pll Exp[L];

void init() {
    Exp[0] = mp(1, 1);
    FOR(i, 1, 1e6) {
        Exp[i] = mp(Exp[i - 1].fi * BASE1, Exp[i - 1].se * BASE2);
    }
}

void build(string &s, hashArr &h) {
    h.resize(s.size() + 2);
    FOR(i, 1, s.size()) {
        h[i].fi = h[i - 1].fi * BASE1 + s[i - 1];
        h[i].se = h[i - 1].se * BASE2 + s[i - 1];
    }
}

pll get(hashArr &h, int l, int r) {
    return mp(h[r].fi - h[l - 1].fi * Exp[r - l + 1].fi,
              h[r].se - h[l - 1].se * Exp[r - l + 1].se);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    init();

    cin >> q;
    n = 0;
    FOR(i, 1, q) {
        int query;
        cin >> query;
        if (query == 1) {
            cin >> s[++n];
            int sz = s[n].size();
            build(s[n], h[n]);
            FOR(i, 1, n - 1) {
                if (s[i].size() == sz && get(h[i], 1, sz) == get(h[n], 1, sz)) {
                    -- n;
                    break;
                    //cerr << "removed\n";
                }
            }
        } else {
            cin >> str;
            int sz = str.size();
            build(str, h[0]);
            ll res = 0;
            FOR(i, 1, n) {
                if (s[i].size() > sz) continue;
                pll tmp = get(h[i], 1, s[i].size());
                int cnt = 0;
                FOR(j, s[i].size(), sz) {
                    if (get(h[0], j - s[i].size() + 1, j) == tmp) {
                        cnt ++;
                    }
                }
                //cerr << cnt << '\n';
                res += (ll)cnt * s[i].size();
            }
            cout << res << '\n';
        }
    }
}
