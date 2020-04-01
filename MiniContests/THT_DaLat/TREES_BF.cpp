#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "TREES"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e3 + 5;
const int C = 1e6 + 5;
const int maxC = 1e6;
int n, a[N][N];
int res = 1e6;

bool getbit(int mask, int i) {
    return mask & (1 << i);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n-1) FOR(j, i+1, n) {
        int c;
        scanf("%d", &c);
        a[i][j] = a[j][i] = c;
    }
    REP(mask, (1 << n)) {
        int tmp = 0;
        FOR(i, 1, n) FOR(j, 1, n) if (getbit(mask, i-1) == getbit(mask, j-1))
        tmp = max(tmp, a[i][j]);
        res = min(res, tmp);
    }
    printf("%d", res);
}
