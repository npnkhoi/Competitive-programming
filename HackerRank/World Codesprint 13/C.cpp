#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "C"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 1e5 + 5;
multiset<long long> data;
long long a[N], p[N], res;
int tc, n, m, k, x;
long long POW(long long a, int x) {
    if (x == 0) return 1;
    else {
        long long res = POW(a, x / 2);
        res = res * res % m;
        if (x % 2) res = res * a % m;
        return res;
    }
}
void sub0() {
    int cnt = 0;
    res = (ll) n * (n+1) / 2;
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        if (a[i] % m == 0)
            res -= 1LL * cnt * (cnt + 1) / 2, cnt = 0;
        else cnt ++;
    }
    if (cnt > 0) res -= 1LL * cnt * (cnt + 1) / 2;
    printf("%lld\n", res);
}
void sub1() {
    p[0] = 1; res = 0;
    data.clear(); data.insert(1);
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        if (a[i] % m == 0) {
            p[i] = 1;
            data.clear();
            data.insert(1);
        } else {
            p[i] = p[i-1] * a[i] % m;
            res += data.count(p[i] * POW(k, m - 2) % m);
            //if (data.count(k * POW(p[i], m - 2) % m)) cerr << i << "\n";
            data.insert(p[i]);
        }
    }
    printf("%lld\n", res);
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d%d%d", &n, &m, &k);
        if (k == 0) sub0();
        else sub1();
    }
}
