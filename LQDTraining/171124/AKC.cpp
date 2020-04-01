using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int N = 1e5 + 5;
int a[N];

int main() {
    freopen("AKC.inp", "r", stdin);
    freopen("AKC.out", "w", stdout);
    int n;
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    ll res = 0;
    FOR(i, 1, n) if (i%3) res += a[i];
    printf("%lld", res);
    return 0;
}
/** Happy Coding :D */
