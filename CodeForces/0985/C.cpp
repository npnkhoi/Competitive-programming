#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
int n, k, l, m, a[N], p, q;
long long res;
bool mark[N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d%d", &n, &k, &l);
    m = k * n;
    FOR(i, 1, m) scanf("%d", &a[i]);
    sort(a + 1, a + m + 1);
    int p = m, q = m;
    mark[1] = 1; res = a[1];
    FOR(i, 1, n - 1) {
        FOR(j, 1, k-1) {
            while (mark[q]) q --;
            mark[q] = 1; q --;
        }
        while (p >= 1 && (mark[p] || a[p] - a[1] > l)) p --;
        if (p == 0) {
            printf("0");
            exit(0);
        } else {
            res += a[p];
            mark[p] = 1;
        }
        p --;
    }
    printf("%lld", res);
}
