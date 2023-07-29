#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
using namespace std;

const int M = 1e5 + 5, N = 2e5 + 5;
vector<int> tour;
vector<pair<int, int>> adj[M + N];
map<int, int> id;
bool del[M + N];
int deg[M + N], n[M];
char side[M + N];

// left: m, right: sum(n)
// all nodes all the right is offset by m

void dfs(int u, int depth) {
    // delete edge by setting it to -1
    // if (depth % 1000 == 0) cerr << depth << '\n';
    while (adj[u].size()) {
        int v = adj[u].back().first, edge_id = adj[u].back().second;
        adj[u].pop_back();

        if (!del[edge_id]) {
            del[edge_id] = 1;
            deg[u] --;
            deg[v] --;
            dfs(v, depth + 1);
            tour.push_back(edge_id);
        }
    }
    // cerr << "adding " << u << " to tour\n";
    // tour.push_back(u);
}

// void findEuler(int u) {
//     stack<int> st;
//     st.push(u);
//     while (!st.empty()) {
//         int v = st.top();
//         if (deg[v]) {

//         }
//     }
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // cerr << "start\n";
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int m, s = 0;
    cin >> m;
    // cerr << "m = " << m << '\n';
    FOR(i, 1, m) {
        cin >> n[i];
        FOR(j, 1, n[i]) {
            int x; cin >> x;
            if (!id.count(x)) {
                id[x] = id.size() + 1;
            }
            x = id[x];
            s ++;
            // cerr << "adding edge " << i << ' ' << x + m  << '\n';
            adj[i].push_back({x + m, s});
            adj[x + m].push_back({i, s});
            deg[i] ++; deg[x + m] ++;
        }
    }

    // Euler tour finding
    FOR(i, 1, m+id.size()) {
        if (adj[i].size() % 2) {
            cout << "NO\n";
            return 0;
        }
    }

    // cerr << "start euler\n";
    memset(del, 0, sizeof del);
    FOR(i, 1, m) {
        if (deg[i]) dfs(i, 0);
    }
    // cerr << "end euler\n";

    cout << "YES\n";
    FOR(i, 0, s-1) {
        side[tour[i]] = (i % 2 ? 'L' : 'R');
    }
    int idx = 0;
    FOR(i, 1, m) {
        string res = "";
        FOR(j, 1, n[i]) {
            res += side[++idx];
        }
        cout << res << '\n';
    }
    // cerr << "done\n";
}

