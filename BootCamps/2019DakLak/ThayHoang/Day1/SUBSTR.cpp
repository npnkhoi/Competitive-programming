#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "substr"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;
string s;
int n, sh;
int tmp[N], sa[N], rnk[N], lcp[N], q;
int inmod(int x) {
    x %= n;
    if (x < 0) x += n;
    return x;
}
int cmp(int x, int y) {
    if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
    else return rnk[inmod(x+sh)] < rnk[inmod(y+sh)];
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int tc;

    getline(cin, s);
    s += (char) 0; n = s.size();
    sh = 1;
    REP(i, n) rnk[i] = s[i] - '@';
    while (1) {
        REP(i, n) sa[i] = i;
        sort(sa, sa + n, cmp);
        int m = 0;
        tmp[sa[0]] = 0;
        REP(i, n-1) {
            m += cmp(sa[i], sa[i+1]);
            tmp[sa[i+1]] = m;
        }
        REP(i, n) rnk[i] = tmp[i];
        if (m == n-1) break;
        sh *= 2;
    }
    lcp[0] = 0;
    int q = 0;
    long long res = (ll) n * (n-1) / 2;
    REP(i, n-1) {
        int j = sa[rnk[i]-1];
        while (i + q < n && j + q < n && s[i + q] == s[j + q]) {
            ++q;
            //cerr << "ahihi\n";
        }
        lcp[rnk[i]] = q;
        res -= q;
        if (q > 0) -- q;
    }
    printf("%lld\n", res);
}
