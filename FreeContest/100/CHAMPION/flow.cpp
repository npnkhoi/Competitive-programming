#include <bits/stdc++.h>
using namespace std;

template<typename flow_t = long long>
struct PushRelabel {
    struct Edge {
        int to, rev;
        flow_t f, c;
    };
    vector<vector<Edge> > g;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

    int addEdge(int s, int t, flow_t cap, flow_t rcap=0) {
        if (s == t) return -1;
        Edge a = {t, (int)g[t].size(), 0, cap};
        Edge b = {s, (int)g[s].size(), 0, rcap};
        g[s].push_back(a);
        g[t].push_back(b);

        // Return ID of forward edge.
        return b.rev;
    }

    flow_t maxFlow(int s, int t) {
        int v = g.size();
        H[s] = v;
        ec[t] = 1;
        vector<int> co(2*v);
        co[0] = v-1;
        for (int i = 0; i < v; ++i) {
            cur[i] = g[i].data();
        }
        for (auto &e : g[s]) {
            add_flow(e, e.c);
        }
        if (hs[0].size()) {
            for (int hi = 0; hi >= 0;) {
                int u = hs[hi].back();
                hs[hi].pop_back();
                while (ec[u] > 0) { // discharge u
                    if (cur[u] == g[u].data() + g[u].size()) {
                        H[u] = 1e9;
                        for (auto &e : g[u]) {
                            if (e.c && H[u] > H[e.to]+1) {
                                H[u] = H[e.to]+1;
                                cur[u] = &e;
                            }
                        }
                        if (++co[H[u]], !--co[hi] && hi < v) {
                            for (int i = 0; i < v; ++i) {
                                if (hi < H[i] && H[i] < v){
                                    --co[H[i]];
                                    H[i] = v + 1;
                                }
                            }
                        }
                        hi = H[u];
                    } else if (cur[u]->c && H[u] == H[cur[u]->to] + 1) {
                        add_flow(*cur[u], min(ec[u], cur[u]->c));
                    }
                    else {
                        ++cur[u];
                    }
                }
                while (hi>=0 && hs[hi].empty()) --hi;
            }
        }
        return -ec[s];
    }
private:
    vector<flow_t> ec;
    vector<Edge*> cur;
    vector<vector<int> > hs;
    vector<int> H;

    void add_flow(Edge& e, flow_t f) {
        Edge &back = g[e.to][e.rev];
        if (!ec[e.to] && f) {
            hs[H[e.to]].push_back(e.to);
        }
        e.f += f; e.c -= f;
        ec[e.to] += f;
        back.f -= f; back.c += f;
        ec[back.to] -= f;
    }
};

const int N = 105;
const long long oo = 1e18;

int tc, n;
int a[N][N], w[N];
long long s[N];
vector<int> ans;

bool check(int u, vector<int> &v) {
	long long mx = w[u] + s[u];
	PushRelabel<long long> flow(2 * n + 2);
	for (int x : v) {
		if (w[x] > mx) return 0;
		flow.addEdge(x, x + n, mx - w[x]);
		flow.addEdge(x + n, 2 * n + 1, oo);
	}
	long long sum = 0;
	for (int i = 0; i < v.size() - 1; ++ i) {
		for (int j = i + 1; j < v.size(); ++ j) {
			int x = v[i], y = v[j];
			sum += a[x][y];
			flow.addEdge(0, x, a[x][y]);
			flow.addEdge(x, y, a[x][y]); 
		}
	}
	// cerr << "at vtx " << u << ": ";
	// cerr << flow.maxFlow(0, 2 * n + 1) << ' ' << sum << ' ' << mx << '\n';
	return flow.maxFlow(0, 2 * n + 1) == sum;
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		memset(s, 0, sizeof s);
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				scanf("%d", &a[i][j]);
				s[i] += a[i][j];
			}
		}
		for (int i = 1; i <= n; ++ i) scanf("%d", &w[i]);
		ans.clear();
		for (int i = 1; i <= n; ++ i) {
			vector<int> v;
			for (int j = 1; j <= n; ++ j) {
				if (j != i) v.push_back(j);
			}
			if (check(i, v)) ans.push_back(i);
		}
		printf("%d ", (int) ans.size());
		for (int x : ans) printf("%d ", x);
		printf("\n");
	}
}