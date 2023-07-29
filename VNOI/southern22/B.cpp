#include <bits/stdc++.h>

using namespace std;

const int N = 1005, M = 1e5 + 5;
int n, m, q, e[N][N], u[M], v[M], w[M], ans[M];

struct DSU {
    int n;
    vector <int> lab;

    DSU() {}
    DSU(int _n) {
        this -> n = _n;
        lab.assign(n + 5, -1);
    }

    int root(int x) {
        return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
    }

    void merge(int u, int v) {
        int x = root(u), y = root(v);
        if (x == y) return;
        lab[x] = y;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("B.inp", "r", stdin);

    cin >> n >> m >> q;
    set <array<int, 4>> ed;
    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        ed.insert({w[i], u[i], v[i], i});
    }
    ed.insert({-1, 1, 1, 0});

    vector <array<int, 4>> query;
    query.clear();
    memset(ans, -1, sizeof ans);
    for (int i = 1; i <= q; ++i) {
        char type;
        cin >> type;
        if (type == 'C') {
            sort(query.begin(), query.end());
            DSU cur(n);
            int r = query.size() - 1;
            if (query.size() == 0) {
                r = -1;
            }
            reverse(query.begin(), query.end());

            for (auto it = ed.rbegin(); it != ed.rend(); it++) {
                auto curEd = *it;
                while (r >= 0 && query[r][0] > curEd[0]) {
                    ans[query[3]] = (cur.root(query[r][1]) == cur.root(query[r][2]));
                    r--;
                }
                cur.merge(curEd[1], curEd[2]);

            }
            query.clear();

            int id, x;
            cin >> id >> x;
            ed.erase({w[id], u[id], v[id], id});
            w[id] = x;
            ed.insert({w[id], u[id], v[id], id})
        } else {
            int u, v, c;
            cin >> u >> v >> c;
            query.push_back({c, u, v, i});
        }

    }


}
