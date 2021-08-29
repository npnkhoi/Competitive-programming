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

#define task "SPC2"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 7;

int tc, n;
int a[N][N], mark[N][N];

bool getBit(int x, int i) {
    return (x >> i) & 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> tc;
    REP(NhiThun, tc) {
        cin >> n;
        FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
        int res = n*n;
        REP(mask, (1 << n*n)) {
            REP(i, n*n) mark[i/n + 1][i % n + 1] = getBit(mask, i);
            bool flag = 1;
            FOR(i, 1, n) {
                FOR(j, 1, n - 1) FOR(k, j + 1, n) {
                    if (!mark[i][j] && !mark[i][k] && a[i][j] == a[i][k]) {
                        flag = 0;
                        break;
                    }
                    if (!mark[j][i] && !mark[k][i] && a[j][i] == a[k][i]) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) res = min(res, __builtin_popcount(mask));
        }
        cout << res << '\n';
    }
}
