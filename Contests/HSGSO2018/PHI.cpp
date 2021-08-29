#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

long long save, m, n;
vector<long long> data;
int t, nfact, res;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> save;

    m = save;

    t = 0;
    bool flag = 0;
    for (int p = 2; p <= sqrt(m); p++) if (m % p == 0) {
        int cnt = 0;
        while (m % p == 0) m /= p, cnt ++;
        if (p == 2) t = cnt;
        else if (save % (p-1) == 0) data.push_back(p);
        if (p == 3) flag = 1;
    }
    if (!flag) data.push_back(3);
    if (save % (m-1) == 0) {
        if (m == 2) t ++;
        else data.push_back(m);
    }
    /*REP(j, data.size()) cerr << data[j] << " ";
    cerr << "\n";*/

    nfact = data.size();
    //cerr << t << "\n";
    REP(mask, (1 << nfact)) if (__builtin_popcount(mask) <= t) {
        bool ok = 1;
        n = save;
        REP(i, nfact) if ((mask & (1 << i)) > 0) {
            int tmp = data[i] - 1;
            if (n % tmp) ok = 0;
            else n /= tmp;
        }
        while (n % 2 == 0) n /= 2;
        REP(i, nfact) if ((mask & (1 << i)) > 0)
        while (n % data[i] == 0) n /= data[i];
        if (ok && (n == 1)) {
            res ++;
            if (__builtin_popcount(mask) == t) res ++;
        }
    }
    cout << res;
}
