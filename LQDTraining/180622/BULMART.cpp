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

const int N = 5e3 + 5;
int n, m;
vector<ii> store[N], reach;
vi adj[N];
int d[N][N];
queue<int> q;

void bfs(int s, int d[]) {
    FOR(i, 1, n) d[i] = -1; d[s] = 0;
    //FOR(i, 1, n) cerr << d[i] << " "; cerr << "\n";
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(j, adj[u].size()) {
            int v = adj[u][j];
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    //FOR(i, 1, n) cerr << d[i] << " "; cerr << "\n";
}
bool check(int city, int amount, int budget, int dist) {
    //cerr << "check " << city << " " << amount << " " << budget << " " << dist << "\n";
    //cerr << "done bfs\n";
    reach.clear();
    FOR(i, 1, n) if (d[city][i] <= dist && d[city][i] != -1) {
        REP(j, store[i].size()) reach.pb(store[i][j]);
    }
    sort(reach.begin(), reach.end());
    int amount2 = 0;
    ll price2 = 0;
    REP(i, reach.size()) {
        //cerr << reach[i].fi << " " << reach[i].se << "\n";
        if (amount2 + reach[i].se <= amount) {
            amount2 += reach[i].se;
            price2 += 1LL * reach[i].fi * reach[i].se;
        } else {
            price2 += 1LL * (amount - amount2) * reach[i].fi;
            amount2 = amount;
            break;
        }
        if (price2 > budget) break;
    }
    //cerr << "out check " << amount2 << " " << price2 << "\n";
    if (amount2 < amount || price2 > budget) return 0;
    else return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> m;
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i, 1, n) bfs(i, d[i]);
    /*FOR(i, 1, n) {
        FOR(j, 1, n) cerr << d[i][j] << " ";
        cerr << "\n";
    }*/
    int w, q;
    cin >> w;
    REP(i, w) {
        int city, amount, price;
        cin >> city >> amount >> price;
        store[city].pb(mp(price, amount));
    }
    cin >> q;
    REP(z, q) {
        int city, amount, budget;
        cin >> city >> amount >> budget;
        int l = 0, r = n, res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(city, amount, budget, mid))
                res = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (check(city, amount, budget, res)) cout << res << '\n';
        else cout << "-1\n";
    }
}
