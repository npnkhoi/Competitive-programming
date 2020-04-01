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

#define task "convention"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, m, c, a[N];

bool ok(int x) {
    int idx = 1, cnt = 0;
    FOR(i, 1, n) {
        if (i == n || a[i + 1] - a[idx] > x || i - idx + 1 == c) {
            idx = i + 1;
            cnt ++;
        }
    }
    //debug(cnt);
    return cnt <= m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> m >> c;
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    //FOR(i, 1, n) cout << a[i] << ' '; cout << '\n';
    //cerr << ok(4) << '\n';
    int l = 0, r = a[n] - a[1], mid, bs = r;
    while (l <= r) {
        mid = (l + r) / 2;
        if (ok(mid)) {
            bs = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << bs;
}
