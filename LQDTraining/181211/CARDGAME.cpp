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

#define task "CARDGAME"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 22, MASK = (1 << 20) + 5;
const ll oo = 1e18;

int tc, n, a[N], b[N];
ll f[MASK][N], res;

bool getBit(int x, int i) {
    return x & (1 << i);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> tc;
    REP(khue, tc) {
        cin >> n;
        REP(i, n) cin >> a[i];
        REP(i, n) cin >> b[i];
        REP(mask, (1 << n)) {
            REP(i, n) {
                f[mask][i] = oo;
                if (getBit(mask, i) == 0) continue;
                if (__builtin_popcount(mask) == 1) {
                    f[mask][i] = 0;
                    continue;
                }
                REP(j, n) {
                    if (i == j || getBit(mask, j) == 0) continue;
                    f[mask][i] = min(f[mask][i],
                        f[mask ^ (1 << i)][j] + min(a[i] ^ b[j], a[j] ^ b[i]));
                }
            }
        }
        /*REP(mask, (1 << n)) {
            REP(i, n) cerr << mask << ' ' << i << ' ' << f[mask][i] << '\n';
        }*/
        long long res = oo;
        REP(i, n) res = min(res, f[(1 << n) - 1][i]);
        cout << res << '\n';
    }
}

