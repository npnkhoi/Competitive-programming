#include <bits/stdc++.h>
using namespace std;

// const int N =

const int N = 4;
const int oo = 1e9 + 7;

int m, n, minEdge[N][N];
int link[N][N], mark[N], inSet[N], degIn[N], mask, cnt;
vector<int> vtx;
long long w[N][N], res;

void dfs(int u) {
	mark[u] = 1;
	cnt ++;
	for (int v = 0; v < 4; ++ v) {
		if (inSet[v] && link[u][v] && !mark[v]) {
			dfs(v);
		}
	}
}

bool canDel(int u, int v) {
	link[u][v] --;
	link[v][u] --;
	cnt = 0;
	memset(mark, 0, sizeof mark);
	dfs(vtx[0]);
	link[u][v] ++;
	link[v][u] ++;
	return cnt == n;
}

int main() {
	freopen("MATCHING.inp", "r", stdin);
	freopen("MATCHING.out", "w", stdout);
	for (int i = 0; i < 4; ++ i) {
		for (int j = i; j < 4; ++ j) {
			minEdge[i][j] = oo;
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++ i) {
		int u, c, v;
		scanf("%d%d%d", &u, &c, &v);
		u --; v --;
		if (u > v) {
			swap(u, v);
		}

		w[u][v] += c;
		link[u][v] ++;
		link[v][u] ++;

		if (u != v) {
			minEdge[u][v] = min(minEdge[u][v], c);
			degIn[u] ++;
			degIn[v] ++;
		}
	}
	// for (int i = 0; i < 4; ++ i) cerr << degIn[i] << " ";
	// cerr << "\n";

	for (mask = 1; mask < 16; ++ mask) {
		// create sub-graph
		vtx.clear();
		memset(inSet, 0, sizeof inSet);
		for (int i = 0; i < 4; ++ i) {
			if (mask & (1 << i)) {
				vtx.push_back(i);
				inSet[i] = 1;
			}
		}

		// check connection
		memset(mark, 0, sizeof mark);
		cnt = 0;
		dfs(vtx[0]);
		// cerr << "--------------\n";
		// cerr << mask << " " << cnt << "\n";
		if (cnt != vtx.size()) continue;
		n = cnt;

		// caculate sum of all edges
		long long tmp = 0;
		for (int i = 0; i < n; ++ i) {
			for (int j = i; j < n; ++ j) {
				tmp += w[vtx[i]][vtx[j]];
				// tmp += w[min(vtx[i], vtx[j])][max(vtx[j], vtx[i])];
			}
		}

		// remove spare edge
		if (mask == 15 && (degIn[0] & degIn[1] & degIn[2] & degIn[3]) % 2) {
			// cerr << " -- \n";
			int delEdge = oo;
			for (int i = 0; i < n; ++ i) {
				for (int j = i + 1; j < n; ++ j) {
					int u = vtx[i], v = vtx[j];
					if (canDel(u, v)) {
						delEdge = min(delEdge, minEdge[u][v]);
					}
				}
			}
			// cerr << delEdge << "\n";
			tmp -= delEdge;
		}
		// cerr << mask << " " << tmp << "\n";
		res = max(res, tmp);
	}
	printf("%lld", res);
}