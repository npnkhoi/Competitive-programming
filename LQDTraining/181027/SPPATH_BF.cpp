#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second

const long long oo = 1e18 + 7;
const int N = 1e4 + 5;
const int MAX_EDGE = 1e4;

typedef pair<int, int> ii;
struct Pack {
	long long dist;
	int vtx, wei, slope;
	// slope: 0 -> decrease; 1 -> increase
	Pack(long long a, int b, int c, int d): dist(a), vtx(b), wei(c), slope(d) {}
};

bool operator > (const Pack a, const Pack b) {
	return a.dist > b.dist;
}

int n, m, s, t;
long long dist[N][MAX_EDGE + 5][2];
vector<ii> adj[N];
long long res;
priority_queue<Pack, vector<Pack>, greater<Pack> > heap;


bool checkRela(int e1, int e2, int flag) {
	if (e1 > e2) return flag == 0;
	else if (e1 < e2)  return flag == 1;
	else return false;
}

int main() {
	freopen("SPPATH.inp", "r", stdin);
	freopen("SPPATH.ans", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back(mp(v, c));
		adj[v].push_back(mp(u, c));
	}
	scanf("%d%d", &s, &t);

	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= MAX_EDGE; ++ j) {
			dist[i][j][0] = dist[i][j][1] = oo;
		}
	}
	for (ii v : adj[s]) {
		heap.push(Pack(v.se, v.fi, v.se, 0));
		dist[v.fi][v.se][0] = v.se;
	}

	while (!heap.empty()) {
		Pack t = heap.top();
		heap.pop();

		if (t.dist != dist[t.vtx][t.wei][t.slope]) continue;

		for (ii v : adj[t.vtx]) {
			if (checkRela(t.wei, v.se, t.slope) && t.dist + v.se < dist[v.fi][v.se][t.slope ^ 1]) {
				dist[v.fi][v.se][t.slope ^ 1] = t.dist + v.se;
				heap.push(Pack(t.dist + v.se, v.fi, v.se, t.slope ^ 1));
			}
		}
	}

	res = oo;
	for (int i = 0; i <= MAX_EDGE; ++i) {
		res = min(res, min(dist[t][i][0], dist[t][i][1]));
	}
	if (res == oo) printf("-1");
	else printf("%lld", res);
}