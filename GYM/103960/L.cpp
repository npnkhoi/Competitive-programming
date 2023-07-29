#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, ans[N], c[N], cnt[N], temp[N], sz[N], tot[N];
vector <ii> adj[N];

void prepare(int u, int pre) {
    sz[u] = 1;
    for (ii d : adj[u]) {
        int v = d.first;
        if (v == pre) {
            continue;
        }
        prepare(v, u);
        sz[u] += sz[v];
    }
}

void get(int u, int pre, vector <int> &w) {
    w.push_back(u);
    for (ii d : adj[u]) {
        int v = d.first;
        if (v != pre) {
            get(v, u, w);
        }
    }
}

int dfs(int u, int pre, bool keep) {
    int maxSz = 0, bigChild = -1;
    for (ii d : adj[u]) {
        int v = d.first;
        if (v == pre) continue;
        if (sz[v] > maxSz) {
            maxSz = sz[v];
            bigChild = v;
        }
    }

    for (ii d : adj[u]) {
        int v = d.first;
        if (v == bigChild || v == pre) {
            continue;
        }
        vector <int> w;
        w.clear();
        get(v, u, w);
        for (int vv : w) {
            temp[c[vv]]++;
        }
        for (int vv : w) if (temp[c[vv]] != 0) {
            ans[d.second] += temp[c[vv]] * (tot[c[vv]] - temp[c[vv]]);
            temp[c[vv]] = 0;
        }
        if (v != bigChild && v != pre) {
            dfs(v, u, 0);
        }
    }
    int ret = 0;
    if (bigChild != -1)
        ret = dfs(bigChild, u, 1);
    for (ii d : adj[u]) {
        if (d.first == bigChild) {
            ans[d.second] = ret;
        }
    }
    for (ii d : adj[u]) {
        int v = d.first;
        if (v == pre) {
            continue;
        }
        if (d.first != bigChild) {
            vector <int> w;
            w.clear();
            get(v, u, w);
            for (int vv : w) {
                ret -= cnt[c[vv]] * (tot[c[vv]] - cnt[c[vv]]);
                cnt[c[vv]]++;
                ret += cnt[c[vv]] * (tot[c[vv]] - cnt[c[vv]]);
            }
        }
    }
    ret -= cnt[c[u]] * (tot[c[u]] - cnt[c[u]]);
    cnt[c[u]]++;
    ret += cnt[c[u]] * (tot[c[u]] - cnt[c[u]]);

    if (!keep) {
        vector <int> w;
        w.clear();
        get(u, pre, w);
        for (int v : w) {
            cnt[c[v]]--;
        }
        return 0;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("L.inp", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        tot[c[i]]++;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

     prepare(1, -1);
     dfs(1, -1, 0);

     for (int i = 1; i < n; ++i) {
        cout << ans[i] << ' ';
     }

    return 0;
}
