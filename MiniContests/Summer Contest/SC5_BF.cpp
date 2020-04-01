#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "sc5"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 405;
const int A = 405;
int a[N], cnt[A], mark[A];
int tmp, n, k, tc;
int mex(int l, int r) {
    memset(mark, 0, sizeof mark);
    FOR(i, l, r) mark[a[i]] = 1;
    FOR(i, 0, n) if (!mark[i]) return i;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d%d", &n, &k);
        memset(cnt, 0, sizeof cnt);
        FOR(i, 1, n) scanf("%d", &a[i]);
        int res = 0;
        FOR(l, 1, n) FOR(r, l, n)
            if (mex(l, r) <= k) res ++;
        printf("%d\n", res);
    }
}
