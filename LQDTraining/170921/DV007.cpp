using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 3e5 + 10;
int n, r, a[N];
long long res;
int main() {
    freopen("DV007.inp", "r", stdin);
    freopen("DV007.out", "w", stdout);
    scanf("%d %d", &n, &r);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) {
        int pos = upper_bound(a, a+n, a[i]+r) - a;
        res += 1LL * (n - pos);
        //cout << a[i] + r << " " << upper_bound(a, a+n, a[i]+r) - a << endl;
    }
    cout << res;
    return 0;
}
/** Happy Coding ^^ */
