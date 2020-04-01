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

#define task "BUILD"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5, sh = 1e5, K = 1e3 + 5, oo = 1e9 + 7;

int a, b, c, n, k;
int hei[N], last[2 * N];
vector<vector<int> > cost;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> a >> b >> c >> n >> k;

    cost.resize(n + 2);
    REP(i, n + 2) cost[i].resize(k + 2);
    cost[0][0] = 0;
    FOR(j, 1, k) cost[0][j] = oo;

    memset(last, -1, sizeof last);
    last[sh] = 0;

    FOR(i, 1, n) {
        char ch;
        cin >> ch;
        if (ch == 'R') {
            cost[i][0] = cost[i - 1][0] + a;
            hei[i] = hei[i - 1];
        } else {
            cost[i][0] = cost[i - 1][0] + b;
            hei[i] = hei[i - 1] + (ch == 'G' ? +1 : -1);
        }

        int tmp = hei[i] + sh;
        FOR(j, 1, k) {
            cost[i][j] = cost[i - 1][j] + (ch == 'R' ? a : b);
            if (last[tmp] != -1 && last[tmp] != i - 1) {
                cost[i][j] = min(cost[i][j],
                                 cost[last[tmp]][j - 1] + c * (i - last[tmp]));
            }
        }

        last[tmp] = i;
    }
    int res = cost[n][0];
    FOR(i, 1, k) res = min(res, cost[n][i]);
    cout << res << '\n';
}
