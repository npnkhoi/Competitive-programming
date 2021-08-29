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

#define task "SPC3"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105, md = 1e9 + 7, LOG = 30;

int tc, n;
int a[N], v[N];
ll cnt[N], cnt1[N], cnt0[N];
vi adj[N];

bool getBit(int x, int i) {
    return (x >> i) & 1;
}

void dfs(int u) {
    cnt[u] = 1;
    cnt0[u] = (a[u] == 0);

    REP(i, adj[u].size()) {
        int v = adj[u][i];
        dfs(v);
        cnt[u] = cnt[u] * (cnt[v] + 1) % md;
        cnt0[u] = cnt0[u] * (cnt0[v] + 1) % md;
    }
    cnt1[u] = cnt[u] - cnt0[u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> tc;
    REP(NhiThun, tc) {
        cin >> n;
        FOR(i, 1, n) adj[i].clear();
        FOR(i, 2, n) {
            int u;
            cin >> u;
            adj[u].push_back(i);
        }
        FOR(i, 1, n) cin >> v[i];
        ll res = 0;
        FOR(i, 0, LOG) {
            FOR(j, 1, n) {
                a[j] = getBit(v[j], i);
            }
            dfs(1);
            FOR(j, 1, n) res = (res + cnt1[j] * (1 << i) % md) % md;
        }
        cout << res << '\n';
    }
}
