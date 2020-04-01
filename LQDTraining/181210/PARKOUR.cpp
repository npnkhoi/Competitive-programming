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

#define task "parkour"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5, oo = 1e6;
const double EPS = 1e-9;

int tc, n, m, a[N], lo[N], hi[N];

bool check(double d) {
    double l = a[1] - d, r = a[1] + d;
    FOR(i, 2, n) {
        l = max(l - lo[i-1], a[i] - d);
        r = min(r + hi[i-1], a[i] + d);
        if (l - r > EPS) return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> tc;
    REP(khue, tc) {
        cin >> n >> m;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n - 1) lo[i] = hi[i] = oo;
        FOR(i, 1, m) {
            int l, r, u, d;
            cin >> l >> r >> u >> d;
            if (l > r) {
                swap(u, d);
                swap(l, r);
            }
            FOR(j, l, r - 1) {
                lo[j] = min(lo[j], d);
                hi[j] = min(hi[j], u);
            }
        }
        double l = 0, r = 1e6, mid, bs = r;
        while (r - l > EPS) {
            mid = (l + r) / 2;
            if (check(mid)) {
                bs = mid;
                r = mid - EPS;
            } else l = mid + EPS;
        }
        cout << fixed << setprecision(6) << bs << '\n';
    }
}
