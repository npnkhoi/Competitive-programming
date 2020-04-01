#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
struct Block{
	int le, ri, val;
	Block(): le(0), ri(0), val(0) {}
	Block(int _le, int _ri, int _val): le(_le), ri(_ri), val(_val) {}
};

int n, res, res2, cntEdge;
int minVal[7][7], cnt[7][7];
vector<Block> edge;

void updateRes() {
	for (int u = 1; u <= n; u ++) {

	}
} 

void backTrack(int u) {
	vis[u] = 1;
	bool flag = 1;
	for (int v = 1; v <= 4; ++ v) {
		if (v != u && cnt[u][v]) {
			flag = 0;
			cnt[u][v] = cnt[v][u] = 0;
			tmp += minVal[u][v];
			backTrack(v);
			tmp += minVal[u][v];
			cnt[u][v] = cnt[v][u] = 1;
		}
	}
	if (flag) updateRes();
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int u, val, v;
		scanf("%d", &u, &val, &v);
		if (u > v) swap(u, v);

		minVal[u][v] = min(minVal[u][v], val);
		sum[u][v] += val;
		cnt[u][v] ^= 1;
	}
	for (int u = 1; u <= n; ++ u) {
		for (int v = u + 1; v <= n; ++ v) {
			minVal[v][u] = minVal[u][v];
			cnt[v][u] = cnt[u][v];
			if (cnt[u][v]) {
				sum[u][v] -= minval[u][v];
			}
			sum[v][u] = sum[u][v];
		}
	}
	for (int i = 1; i <= 4; ++ i) {
		backTrack(i);
	}
	printf("%d", res);
}