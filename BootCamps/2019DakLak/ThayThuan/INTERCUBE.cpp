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

bool inSide(int i, int j, int k, int l) {
    x0 = id[0][i-1];
    y0 = id[1][i-1];
    z0 = id[2][i-1];
    x1 = id[0][i];
    y1 = id[1][i];
    z1 = id[2][i];
    return (a[l][0][0] <= x0 && x0 <= a[l][1][0] &&
    a[l][0][1] <= y0 && y0 <= a[l][1][1] &&
    a[l][0][2] <= z0 && z0 <= a[l][1][2]);
}

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        REP(j, 2) REP(k, 3) scanf("%d", a[i][j][k]);
        nums[k].pb(a[i][j][k]);
    }
    REP(k, 3) {
        sort(nums[k].begin(), nums[k].end());
        REP(i, nums[k].size()) {
            if (i == 0 || nums[k][i] != nums[k][i-1]) id[k][nums[k][i]] = ++rr[k];
        }
    }
    FOR(i, 2, rr[0]) {
        FOR(j, 2, rr[1]) {
            FOR(k, 2, rr[2]) {
                int cnt = 0;
                FOR(l, 1, n) if (inSide(i, j, k, l)) cnt ++;
                if (cnt >= k) res += ;
            }
        }
    }
    printf("%lld\n", res);
}
