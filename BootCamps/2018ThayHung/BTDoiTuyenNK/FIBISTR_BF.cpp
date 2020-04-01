#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "fibistr"

const int N = 1e5 + 5;
string t[N], s;
ull k;
int z[100*N];

ull appear(string &s, string &t) {
    string x = s + '.' + t;
    int n = x.size(), res = 0;
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
    freopen(task".ans", "w", stdout);
    cin >> t[1] >> t[2] >> s >> k;
    for (int i = 3; ;i ++) {
        t[i] = t[i-1] + t[i-2];
        if (appear(s, t[i]) >= k) {
            cout << i;
            exit(0);
        }
        if (t[i].size() >= 1e7) {
            cout << 0;
            exit(0);
        }
    }
}
/** Happy Coding :D */
