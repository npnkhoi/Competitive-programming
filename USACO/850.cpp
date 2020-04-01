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

#define task "cowpatibility"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;
typedef pair<ull, ull> Hash;

const int N = 5e4 + 5, M = 7, BASE1 = 1e7 + 19, BASE2 = 1e9 + 7;
int n, a[N][M], comb[M][M];
ll res, cnt[M];
vector<pll> v[M];

bool getBit(int x, int i) {
    return x & (1 << i);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    FOR(i, 1, 5) {
        comb[i][0] = comb[i][i] = 1;
        FOR(j, 1, i - 1) comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
    cin >> n;
    FOR(i, 1, n) {
        REP(j, 5) cin >> a[i][j];
        sort(a[i], a[i] + 5);
        REP(mask, 32) {
            Hash hashID = mp(0, 0);
            REP(j, 5) if (getBit(mask, j)) {
                hashID.fi = hashID.fi * BASE1 + a[i][j];
                hashID.se = hashID.se * BASE2 + a[i][j];
            }
            v[__builtin_popcount(mask)].push_back(hashID);
        }
    }
    FOR(l, 1, 5) {
        sort(all(v[l]));
        int tmp = 0;
        REP(i, v[l].size()) {
            tmp ++;
            if (i == v[l].size() - 1 || v[l][i] != v[l][i + 1]) {
                cnt[l] += (ll) tmp * (tmp - 1) / 2;
                tmp = 0;
            }
        }
    }
    //FOR(l, 1, 5) cerr << cnt[l] << ' '; cerr << '\n';
    res = (ll)n * (n - 1) / 2;
    /*FOR(i, 1, 4) cnt[i] -= cnt[i + 1] * (i + 1);
    FOR(l, 1, 5) cerr << cnt[l] << ' '; cerr << '\n';*/
    FORD(l, 5, 1) {
        res -= cnt[l];
        //cerr << cnt[l] << ' ';
        FOR(pre, 1, l - 1) {
            cnt[pre] -= cnt[l] * comb[l][pre];
        }
    }
    //cerr << "\n";
    cout << res;
}
