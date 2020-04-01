#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int oo = 1e9 + 7;

int n;
int d[N][N], cntSon[N], inSubTree[N][N], newDist[N][N];
vector<int> adj[N];

void buildTree(int u) {
	while (cntSon[u] > 0) {
		int minDist = oo, son = -1;
		for (int v = 1; v <= n; v ++) {
			if (inSubTree[u][v]) {
				if (d[u][v] < minDist) {
					minDist = d[u][v];
					son = v;
				}
			}
		}

		cntSon[u] --;
		inSubTree[u][son] = 0;
		adj[u].push_back(son);
		adj[son].push_back(u);
		//cerr << "new edge " << u << " " << son << "\n";

		for (int v = 1; v <= n; v ++) {
			if (inSubTree[u][v]) {
				if (d[u][son] + d[son][v] == d[u][v]) {
					cntSon[son] ++;
					inSubTree[son][v] = 1;
					cntSon[u] --;
					inSubTree[u][v] = 0;
				}
			}
		}

		buildTree(son);
	}
}

void dfs(int u, int par, int source) {
	for (int v : adj[u]) {
		if (v != par) {
			newDist[source][v] = newDist[source][u] + d[u][v];
			dfs(v, u, source);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%d", &d[i][j]);
			if (i == j) {
				if (d[i][j] != 0) {
					printf("NO\n");
					exit(0);
				}
			} else {
				if (d[i][j] == 0) {
					printf("NO\n");
					exit(0);
				}
				if (i > j && d[i][j] != d[j][i]) {
					printf("NO\n");
					exit(0);
				}
			}
		}
	}
	for (int i = 2; i <= n; i ++) {
		inSubTree[1][i] = 1;
	}
	cntSon[1] = n - 1;
	buildTree(1);
	for (int u = 1; u <= n; u ++) {
		dfs(u, -1, u);
	}

	// for (int i = 1; i <= n; i ++) {
	// 	for (int j = 1; j <= n; j ++) {
	// 		cerr << newDist[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (d[i][j] != newDist[i][j]) {
				printf("NO\n");
				exit(0);
			}
		}
	}
	printf("YES\n");
}