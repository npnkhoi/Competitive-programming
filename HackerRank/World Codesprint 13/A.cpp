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

const int N = 105;
int a[N], n;
vi ans;
bool mark[N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    REP(z, n) {
        int x;
        scanf("%d", &x);
        mark[x] = 1;
    }
    FOR(i, 1, n) if (!mark[i]) ans.pb(i);
    printf("%d\n", (int)ans.size());
    REP(i, ans.size()) printf("%d ", ans[i]);
}
