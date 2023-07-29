#include <bits/stdc++.h>
using namespace std;

const int V = 10, E = 18, INF = 100;

vector<pair<int, int>> edges;
int edgeId[E+2][E+2], m, dp[(1 << E) + 5];

int getEdgeId(int u, int v) {
    if (u > v) swap(u, v);
    return edgeId[u][v];
}

int newTri(int e, int mask) {
    int u = edges[e].first, v = edges[e].second;
    int ret = 0;
    for (int t = 1; t <= V; ++t) {
        int x = getEdgeId(t, u), y = getEdgeId(t, v);
        if (x == -1 || y == -1) continue;
        if ((mask >> x & 1) && (mask >> y & 1)) ret ++;
    }
    return ret;
}

void prepare() {
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(2, 5));
    edges.push_back(make_pair(3, 5));
    edges.push_back(make_pair(3, 6));
    edges.push_back(make_pair(4, 5));
    edges.push_back(make_pair(5, 6));
    edges.push_back(make_pair(4, 7));
    edges.push_back(make_pair(4, 8));
    edges.push_back(make_pair(5, 8));
    edges.push_back(make_pair(5, 9));
    edges.push_back(make_pair(6, 9));
    edges.push_back(make_pair(6, 10));
    edges.push_back(make_pair(7, 8));
    edges.push_back(make_pair(8, 9));
    edges.push_back(make_pair(9, 10));

    memset(edgeId, -1, sizeof edgeId);
    int idx = 0;
    for (auto edge : edges) {
        edgeId[edge.first][edge.second] = idx;
        edgeId[edge.second][edge.first] = idx;
        idx ++;
    }

    // memset?

    // dp[mask] = gain
    // mask: set of selected edges
    // gain for the current player in the future
    dp[(1 << E) - 1] = 0;
    for (int mask = (1 << E) - 2; mask >= 0; --mask) {
        int res = -INF;
        for (int i = 0; i < E; ++ i) {
            if (mask >> i & 1) continue;
            int tmp = newTri(i, mask);
            int cand = (tmp > 0 ? (tmp + dp[mask | (1 << i)]) : -dp[mask | (1 << i)]);
            res = max(res, cand);
        }
        dp[mask] = res;
    }
}

int main() {
    freopen("A.inp", "r", stdin);
    int tc; cin >> tc;
    prepare();
    for (int itest = 1; itest <= tc; ++ itest) {
        bool onMove = 0;
        vector<int> scores(2, 0);
        int initMask = 0;

        cin >> m;

        for (int i = 0; i < m; ++ i) {
            int u, v;
            cin >> u >> v;
            int id = getEdgeId(u, v);

            int score = newTri(id, initMask);
            scores[onMove] += score;
            if (score == 0) onMove ^= 1;
            initMask |= (1 << id);
        }
        scores[onMove] += dp[initMask];

        printf("Game %d: %c wins.\n", itest, (scores[0] > scores[1] ? 'A' : 'B'));
    }

}
