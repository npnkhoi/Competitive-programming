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

const int oo = 1e8;
const int N = 1e3 + 5;
int n, a[N], f[5];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    f[1] = f[2] = f[3] = oo;
    FOR(i, 1, n) {
        int x;
        scanf("%d", &x);
        f[x] = min(f[x], a[i]);
    }
    printf("%d", min(f[1] + f[2], f[3]));
}
