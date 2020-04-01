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

const int N = 5e5 + 5;
int k, n, d, a[N], f[N], s[N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d%d", &n, &k, &d);
    FOR(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a + n + 1);
    f[0] = 1, s[0] = 1;
    FOR(i, 1, k-1) f[i] = 0, s[i] = 1;
    int p = 1;
    FOR(i, k, n) {
        while (a[i] - a[p] > d) p ++;
        if (i - p + 1 >= k && s[i-k] - (p == 1 ? 0 : s[p-2]) > 0)
            f[i] = 1;
        s[i] = s[i-1] + f[i];
        //cerr << i << " " << f[i] << "\n";
    }
    if (f[n]) printf("YES");
    else printf("NO");
}
