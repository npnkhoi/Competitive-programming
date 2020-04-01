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

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d%d%d", &n, &m, &k);
        FOR(i, 1, n) scanf("%lld", &a[i]);
        res = 0;
        FOR(i, 1, n) FOR(j, i, n) {
            long long tmp = 1;
            FOR(k, i, j) tmp = tmp * a[k] % m;
            res += (tmp == k);
            //cerr << i << " " << j << " " << tmp << '\n';
        }
        printf("%lld\n", res);
    }
}
