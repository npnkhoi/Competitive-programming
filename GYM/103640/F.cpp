#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 3e5 + 5;

int counter = 0, n, mark[N];
vector<int> adj[N];

void dfs(int u) {
    for (int v : adj[u]) {
        if (mark[v] == 0 && v != n) {
            if (u == n) {
                counter ++;
                mark[v] = counter;
            } else {
                mark[v] = mark[u];
            }
            dfs(v);
        }
    }
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int m;
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(n);
    // FOR(i, 1, n) cerr << mark[i] << ' ';
    // cerr << '\n';

    FOR(i, 1, n) {
        if (mark[i] == mark[n-1]) cout << 'B';
        else cout << 'A';
    }
    cout << '\n';
}