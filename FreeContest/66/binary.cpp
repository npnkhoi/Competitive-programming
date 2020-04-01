using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int N = 1e5 + 5;
int a[N], b[N], n, m;
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, m) scanf("%d", &b[i]);
    int res = 0;
    FOR(i, 1, n-m+1) {
        int s = 0;
        FOR(j, i, i+m-1) s += a[j] * b[j-i+1];
        res = max(res, s);
    }
    printf("%d\n", res);

    return 0;
}
/** Happy Coding :D */
