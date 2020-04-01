#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)
#define task "mixperm"

const int N = 1e4 + 5;
int cnt[N], a[N], b[N];
int n, res;

int check(int a[]) {
    memset(cnt, 0, sizeof cnt);
    FOR(i, 1, n) if (cnt[a[i]]) return 0;
    else cnt[a[i]] = 1;
    return 1;
}
int ok(int l, int r) {
    FOR(i, l, r) swap(a[i], b[i]);
    int ans = check(a) | check(b);
    FOR(i, l, r) swap(a[i], b[i]);
    return ans;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &n);
    //cerr << n << "\n";
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) scanf("%d", &b[i]);
    FOR(i, 1, n) FOR(j, i, n) {
        res += ok(i, j);
    }
    printf("%d", res);
    return 0;
}
