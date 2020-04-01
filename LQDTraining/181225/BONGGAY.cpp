#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "BONGGAY"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 5e5 + 5;

int m, n;
ii a[N];
ll res;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> m >> n;
    FOR(i, 1, n) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1, greater<ii>());
    m *= 6;
    FOR(i, 1, n) {
        res += (ll)a[i].fi * min(a[i].se, m);
        m -= a[i].se;
        if (m <= 0) break;
    }
    cout << res;
}

