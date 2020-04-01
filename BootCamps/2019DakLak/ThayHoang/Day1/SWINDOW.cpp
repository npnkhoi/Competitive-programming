#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "swindow"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;
string s, t;
int m, n, q, f[N];
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s; m = s.size();
    cin >> t; n = t.size();
    cin >> k;
    q = f[0] = 0;
    FOR(i, 1, m-1) {
        while (q > 0 && s[q] != s[i]) q = f[q-1];
        if (s[q] == s[i]) ++q;
        f[i] = q;
    }

    q = 0;
    FOR(i, 0, n-1) {
        while (q > 0 && s[q] != t[i]) q = f[q-1];
        if (s[q] == t[i]) ++ q;
        if (q == m) {
            f[i] = 1;
            cerr << i << " ";
            q = f[m-1];
        }
    }
}
