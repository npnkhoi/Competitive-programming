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

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, m, k, x[N], spe[N], lab[N], maxEdge[N];
pair<int, ii> e[N];

int root(int u) {
    if (lab[u] < 0) return u;
    else return lab[u] = root(lab[u]);
}

void merge(int u, int v, int c) {
    u = root(u); v = root(v);
    if (lab[u] > lab[v]) swap(u, v);
    if (spe[u] && spe[v]) maxEdge[u] = max(maxEdge[u], c);
    spe[u] |= spe[v];
    lab[u] -= (lab[u] == lab[v]);
    lab[v] = u;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n >> m >> k;
    FOR(i, 1, k) {
        cin >> x[i];
        spe[x[i]] = 1;
    }
    FOR(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        e[i] = mp(c, mp(u, v));
    }
    sort(e + 1, e + m + 1);
    memset(lab, -1, sizeof lab);
    FOR(i, 1, m) {
        int u = e[i].se.fi, v = e[i].se.se;
        if (root(u) != root(v)) {
            merge(u, v, e[i].fi);
        }
    }
    FOR(i, 1, k) cout << maxEdge[root(x[i])] << ' ';
}
