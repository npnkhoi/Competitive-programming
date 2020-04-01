#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "groups"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1005;
const ll md = 1e9 + 7;
ii a[N], b[N];
int minfact[(int)1e7 + 5], f[10000];
vector<long long> prime;
map<long long, long long> data;
int n, m;
long long res;

void sieve() {
    FOR(i, 2, 1e7) if (minfact[i] == 0) {
        minfact[i] = i;
        prime.push_back(i);
        //printf("%d\n", i);
        for (ll j = 1LL * i * i; j <= 1e7; j += i)
        if (minfact[j] == 0) minfact[j] = i;
    }
}
long long calc(long long x) {
    if (x == 0 || x == 1) return 0;
    if (data.find(x) != data.end()) return data[x];
    long long save = x;
    int p = 0;
    //cerr << "ok1\n";
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= x && x > 1e7; i ++) {
        //cerr << "prime " << i << "\n";
        if (x % prime[i] == 0) {
            f[++p] = prime[i];
            while (x % prime[i] == 0) x /= prime[i];
        }
    }
    if (x > 1e7) f[++p] = x;
    else {
        while (x > 1) {
            f[++p] = minfact[x];
            x /= minfact[x];
        }
    }
    long long res = 0;
    FOR(i, 1, p) if (i == 1 || f[i] != f[i-1]) res += f[i];
    data[save] = res;
    return res;
}
int main() {
    sieve();
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &a[i].fi);
    FOR(i, 1, n) scanf("%d", &a[i].se);
    FOR(i, 1, m) scanf("%d", &b[i].fi);
    FOR(i, 1, m) scanf("%d", &b[i].se);

    //cerr << "ok\n";
    FOR(i, 1, n) FOR(j, 1, m) {
        //cerr << i << " " << j << "\n";
        res = (res + 1LL * a[i].se * b[j].se % md * calc(abs(a[i].fi - b[j].fi)) % md) % md;
    }

    printf("%lld", res);
}
