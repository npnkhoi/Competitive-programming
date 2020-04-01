#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "PRODUCT"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
int n, k, a[N];
ll s[N];

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    FOR(i, 1, k) {
        int x;
        scanf("%d", &x);
        int p = upper_bound(a + 1, a + n + 1, x) - a;
        printf("%lld ", s[p - 1] + (ll) x * (n - p + 1));
    }

}

