using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int N = 1e5 + 5;
const ll md = 1e9 + 7;
int n, k;
ll a[N];
bool mark[N];

ll Exp(int a, int x) {
    if (x == 0) return 1;
    else {
        ll res = Exp(a, x/2);
        res = res * res % md;
        if (x&1) res = res * a % md;
        return res;
    }
}
ll choose(int k, int n) {
    ll res = 1;
    FOR(i, k+1, n) res = res * i % md;
    FOR(i, 2, n-k) res = res * Exp(i, md - 2) % md;
    return res;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d%d", &n, &k);
    FOR(i, 1 ,n) {
        scanf("%lld", &a[i]);
        mark[i] = 1;
    }

    int curSize = n;
    ll res = 0;

    FORD(i, 62, 0) {
        int cnt = 0;
        FOR(j, 1, n) if (mark[j] && (a[j] & (1LL<<i)) > 0) cnt ++;
        if (cnt >= k) {
            res |= 1LL << i;
            FOR(j, 1, n) if (mark[j] && ((a[j] & res) != res)) mark[j] = 0;
        }
        /*printf("%d %lld\n", i, res);
        FOR(i, 1, n) cerr << mark[i] << " " ; cerr << "\n";*/
    }
    printf("%lld\n", res);

    int tmp = 0;
    FOR(i, 1, n) if ((a[i] & res) == res) tmp ++;
    printf("%lld\n", choose(k, tmp));
    return 0;
}
/** Happy Coding :D */
