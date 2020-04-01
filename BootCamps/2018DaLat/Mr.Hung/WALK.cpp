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

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 3e5 + 5;
int a[N];
int n, d;
ll res;

int main() {
    freopen("WALK.inp", "r", stdin);
    freopen("WALK.out", "w", stdout);
    scanf("%d%d", &n, &d);
    FOR(i, 1, n) scanf("%d", &a[i]);
    int j = 1;
    FOR(i, 1, n) {
        while (j <= n && a[j] - a[i] <= d) ++j;
        res += j-i-1;
        //cerr << j << " " << res << "\n";
    }
    res = 1LL*n*(n-1)/2 - res;
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding :D */
