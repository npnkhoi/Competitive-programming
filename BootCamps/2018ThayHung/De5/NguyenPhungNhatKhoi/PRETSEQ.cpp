#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iostream>
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
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define task "pretseq"

const int N = 1e5 + 5;
int n, m, a[N], s[N], tmp, res;
ii x[N];
double timer;
bool cmp(ii a, ii b) {
    return a.se - a.fi < b.se - b.fi;
}
void TLE() {
    if ((clock() - timer) / CLOCKS_PER_SEC >= 0.95) {
        printf("%d", n-res);
        exit(0);
    }
}
void backTrack(int i) {
    if (i == m + 1) return;
    FOR(j, 1, n) if (s[j] > a[j]) return;
    res = max(res, tmp);
    TLE();

    FOR(j, x[i].fi, x[i].se) s[j] ++;
    tmp ++;
    backTrack(i+1);
    FOR(j, x[i].fi, x[i].se) s[j] --;
    tmp --;
    backTrack(i+1);
}
int main() {
    timer = clock();
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    //cerr << n << "\n";
    FOR(i, 1, n) scanf("%d", &a[i]);
    scanf("%d", &m);
    FOR(i, 1, m) scanf("%d%d", &x[i].fi, &x[i].se);
    sort(x+1, x+m+1, cmp);
    backTrack(1);
    printf("%d", n - res);
}
