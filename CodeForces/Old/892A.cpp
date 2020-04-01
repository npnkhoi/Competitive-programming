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
const int N = 1e5 + 5;
ll a[N], b[N], n, s;
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        s += a[i];
    }
    FOR(i, 1, n) scanf("%lld", &b[i]);

    sort(b+1, b+n+1, greater<int>());
    if (s <= b[1] + b[2]) printf("YES");
    else printf("NO");
    return 0;
}
/** Happy Coding :D */
