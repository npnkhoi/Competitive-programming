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
int a[N];

int main() {
    freopen("CASSIA.inp", "r", stdin);
    freopen("CASSIA.out", "w", stdout);
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    sort(a, a+n);
    int res = n;
    REP(i, n) {
        int pos = upper_bound(a, a+n, a[i]+n-1) - a;
        res = min(res, n - (pos-i));
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
