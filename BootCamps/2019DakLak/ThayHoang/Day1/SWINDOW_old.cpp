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

const int N = 1e7 + 5;
string s, t, str;
int z[N], f[N], m, n, p, k, res;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    getline(cin, s); m = s.size();
    getline(cin, t); n = t.size();
    p = m + n + 1;
    str = t + "a" + s;
    scanf("%d", &k);

    int l = 0, r = 0;
    z[0] = p;
    //cerr << str << "\n";
    FOR(i, 1, p-1) {
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i + z[i] < p && str[z[i]] == str[i+z[i]]) z[i] ++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
        if (i > n) f[i - 1] = f[i - 2] + (z[i] >= n);
        //cerr << z[i] << "\n";
    }
    //FOR(i, 1, m) cerr << f[i] << " "; cerr << "\n";
    FOR(i, k, m) if (f[i] - f[i-(k-n)-1] > 0) {
        res ++;
        //cerr << i << "\n";
    }
    printf("%d", res);
}
