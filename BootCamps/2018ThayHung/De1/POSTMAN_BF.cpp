#include <utility>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ii> vii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) for (int i = 0; i < n; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)

#define task "postman"

int n, k;
vii a, b;

ll sol(vii &a) {
    sort(a.begin(), a.end());
    //REP(i, a.size()) cerr << a[i].fi << " " << a[i].se << "\n";
    //cerr << "\n";
    ll res = 0;
    while (!a.empty()) {
        ii tmp = a.back(); a.pop_back();
        if (tmp.se >= k) {
            res += 1LL * tmp.fi * tmp.se / k;
            tmp.se %= k;
        } else if (tmp.se > 0) {
            res += tmp.fi;
            if (!a.empty()) a.back().se -= (k - tmp.se);
        } else if (tmp.se < 0) {
            if (!a.empty()) a.back().se += tmp.se;
        }
    }
    return 2 * res;
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    v.resize(n);
    REP(i, n) scanf("%d%d", &v[i].fi, &v[i].se);

    return 0;
}
