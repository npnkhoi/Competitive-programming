using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define task "fibistr"

const int N = 1e5 + 5;
const int maxL = 1e6 + 5;
string t[N], s;
int n, l[maxL], r[maxL], z[maxL], delta[2][2];
ull k, f[N];

ull appear(string &s, string &t) {
    string x = s + '.' + t;
    int n = x.size(), res = 0;
    //cerr << x << "\n";
    memset(z, 0, sizeof z);
    int l = 0, r = 0;
    FOR(i, 1, n - 1) {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < n && x[i + z[i]] == x[z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
        if (z[i] == s.size()) res ++;
    }
    return res;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> t[1] >> t[2] >> s >> k;
    //cerr << t[1] << t[2] << s << k << "\n";
    //cerr << "ok\n";
    for (int i = 2;; i++) {
        t[i+1] = t[i] + t[i-1];
        //cerr << t[i+1] << "\n";
        if (t[i].size() >= s.size()) {
            n = i;
            break;
        }
        //cerr << i << "\n";
    }
    //cerr << "ok\n";
    f[n] = appear(s, t[n]);
    f[n+1] = appear(s, t[n+1]);
    //cerr << "ok\n";
    if (f[n] >= k) {
        cout << n;
        exit(0);
    } else if (f[n+1] >= k) {
        cout << n+1;
        exit(0);
    }
    REP(i, 2) REP(j, 2) {
        string tmp = t[n+i] + t[n+j];
        delta[i][j] = appear(s, tmp) - f[n+i] - f[n+j];
        //cerr << i << " " << j << " " << delta[i][j] << "\n";
    }
    //cerr << "ok2\n";
    l[n] = r[n] = 0;
    l[n+1] = r[n+1] = 1;
    for (int i = n+2;; i++) {
        f[i] = f[i-1] + f[i-2];
        l[i] = l[i-1]; r[i] = r[i-2];
        f[i] += delta[r[i-1]][l[i-2]];
        if (f[i] >= k) {
            cout << i;
            exit(0);
        }
        if (f[i] == 0 && i >= n + 5) {
            cout << 0;
            exit(0);
        }
    }
    return 0;
}
/** Happy Coding ^^ */

