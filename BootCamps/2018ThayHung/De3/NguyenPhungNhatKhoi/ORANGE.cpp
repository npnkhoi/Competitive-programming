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
#define task "orange"
//ifstream inp(".inp");
//ofstream out(".out");
const int N = 1e5 + 5;
int a[N];

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int n, k;
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    scanf("%d", &k);
    sort(a, a+n);
    int res = n;
    REP(i, n) {
        int pos = upper_bound(a, a+n, a[i]+k-1) - a;
        res = min(res, n - (pos-i));
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
