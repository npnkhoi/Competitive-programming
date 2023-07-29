#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int n, m, tin[N], low[N], mark[N], dfsTime, id[N], scc, in[N], out[N];
stack <int> st;
vector <int> adj[N];
vector <pair <int, int>> ed;

void dfs(int u) {
    low[u] = tin[u] = ++dfsTime;
    mark[u] = 1;
    st.push(u);

    for (int v : adj[u]) {
        if (!mark[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else {
            if (mark[v] == 2) {
                continue;
            }
            low[u] = min(low[u], tin[v]);
        }
    }

    if (low[u] == tin[u]) {
        scc++;
        while (st.top() != u) {
            int v = st.top();
            st.pop();
            id[v] = scc;
            mark[v] = 2;
        }
        mark[u] = 2;
        id[u] = scc;
        st.pop();
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("H.inp", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        ed.push_back({u, v});
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) if (!mark[i]) {
        dfs(i);
    }
    for (auto e : ed) {
        int u = e.first, v = e.second;
        if (id[u] == id[v]) {
            continue;
        }
        in[id[v]]++;
        out[id[u]]++;
    }

    if (scc == 1) {
        cout << 0 << endl;
        return 0;
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= scc; ++i) {
        if (in[i] == 0) {
            cnt1++;
        }
        if (out[i] == 0) {
            cnt2++;
        }
    }

    cout << max(cnt2, cnt1) << endl;

    return 0;
}
