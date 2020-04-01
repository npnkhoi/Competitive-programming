using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const ll md = 1e9 + 7;
ll res;
int x, y;
ll Exp(int a, int x) {
    if (x == 0) return 1;
    else {
        ll res = Exp(a, x/2);
        res = res * res % md;
        if (x&1) res = res * a % md;
        return res;
    }
}
ll choose(int n, int k) {
    ll res = 1;
    for (int i = k+1; i <= n; i++) res = res * i % md;
    FOR(i, 2, n-k) res = res * Exp(i, md - 2) % md;
    return res;
}
void calc(int x) {
    //cerr << x << "\n";
    res = res * choose(x+y-1, y-1) % md;
}
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int q;
    scanf("%d", &q);
    while (q--) {
        //int x, y;
        scanf("%d%d", &x, &y);
        res = 1;
        for (int i = 2; i*i <= x; i++) if (x % i == 0) {
            int cnt = 0;
            do {
                x /= i;
                cnt ++;
            } while (x%i == 0);
            calc(cnt);
        }
        if (x > 1) calc(1);
        res = res * Exp(2, y-1) % md;
        printf("%lld\n", res);
    }
    return 0;
}
/** Happy Coding :D */
