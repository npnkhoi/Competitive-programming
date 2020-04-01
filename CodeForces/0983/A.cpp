#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "A"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

long long t, p, q, b;
long long GCD(long long x, long long y) {
    if (x == 0) return y;
    else return GCD(y%x, x);
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    REP(z, tc) {
        cin >> p >> q >> b;
        t = __gcd(p, q); q /= t;
        while (1) {
            t = __gcd(q, b);
            if (t == 1) break;
            q /= t;
            b = t;
        }
        if (q == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
}
