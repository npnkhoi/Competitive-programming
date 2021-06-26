#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;
struct Matching {
    int n;
    vector<int> matchL, matchR, dist;
    vector<bool> seen;
    vector< vector<int> > ke;

    Matching(int n) : n(n), matchL(n+1), matchR(n+1), dist(n+1), seen(n+1, false), ke(n+1) {}

    void addEdge(int u, int v) {
        ke[u].push_back(v);
    }

    bool bfs() {
        queue<int> qu;
        for(int u = 1; u <= n; ++u)
            if (!matchL[u]) {
                dist[u] = 0;
                qu.push(u);
            } else dist[u] = inf;
        dist[0] = inf;

        while (!qu.empty()) {
            int u = qu.front(); qu.pop();
            for(__typeof(ke[u].begin()) v = ke[u].begin(); v != ke[u].end(); ++v) {
                if (dist[matchR[*v]] == inf) {
                    dist[matchR[*v]] = dist[u] + 1;
                    qu.push(matchR[*v]);
                }
            }
        }
        return dist[0] != inf;
    }

    bool dfs(int u) {
        if (u) {
            for(__typeof(ke[u].begin()) v = ke[u].begin(); v != ke[u].end(); ++v)
                if (dist[matchR[*v]] == dist[u] + 1 && dfs(matchR[*v])) {
                    matchL[u] = *v;
                    matchR[*v] = u;
                    return true;
                }
            dist[u] = inf;
            return false;
        }
        return true;
    }

    int match() {
        int res = 0;
        while (bfs()) {
            for(int u = 1; u <= n; ++u)
                if (!matchL[u])
                    if (dfs(u)) ++res;
        }
        return res;
    }
};

const int M = 1e5 + 5;

typedef pair<int, pair<int, int>> Edge;
Edge edge[M];

int m, n;

bool check(int max_weight) {
	Matching matching(n);
	for (auto e: edge) {
		if (e.first > max_weight) break;
		matching.addEdge(e.second.first, e.second.second);
	}
	return matching.match() == n;
}



int solve() {
	int edge_num_needed = m;
	for (int shift = floor(log2(m)); shift >= 0; -- shift) {
		if ((1 << shift) > edge_num_needed) continue;
		if (check(edge[edge_num_needed - (1 << shift) - 1].first)) {
			edge_num_needed -= (1 << shift);
		}
	}
	if (!check(edge[edge_num_needed - 1].first)) {
		return -1;
	}
	return edge[edge_num_needed - 1].first;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++ i) {
		int u, v, d;
		cin >> u >> v >> d;
		edge[i] = {d, {u, v}};
	}
	sort(edge, edge + m);
	cout << solve();
}