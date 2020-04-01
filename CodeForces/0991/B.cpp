#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "BULMART"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 105;
int a[N], n, t, s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n;
    int t = (9 * n + 1) / 2;
    FOR(i, 1, n) cin >> a[i], s += a[i];
    sort(a+1, a+n+1);
    if (s < t) FOR(i, 1, n) {
        s += 5 - a[i];
        if (s >= t) {
            cout << i;
            exit(0);
        }
    } else cout << 0;
}
