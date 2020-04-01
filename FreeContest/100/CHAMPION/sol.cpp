#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int tc, n;
int a[N][N], w[N], delta[N], mark[N];
vector<int> newNode;
vector<pair<int, int>> edge;

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		edge.clear();
		newNode.clear();
		memset(mark, 0, sizeof mark);
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				scanf("%d", &a[i][j]);
				if (i < j) {
					if (a[i][j]) {
						newNode.push_back(i);
						newNode.push_back(j);
						for (int z = 0; z < a[i][j]; ++ z) {
							edge.push_back({i, j});
						}
					}
				}
			}
		}
		sort(newNode.begin(), newNode.end());
		newNode.resize(unique(newNode.begin(), newNode.end()) - newNode.begin());
		int mxOld = 0;
		bool okOld = 0;
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &w[i]);
			if (binary_search(newNode.begin(), newNode.end(), i) == 0)	mxOld = max(mxOld, w[i]);
		}
		for (int mask = 0; mask < (1 << (int)edge.size()); ++ mask) {
			for (auto i : newNode) delta[i] = 0;
			for (int i = 0; i < edge.size(); ++ i) {
				if (mask >> i & 1) delta[edge[i].first] ++;
				else delta[edge[i].second] ++;
			}
			int mx = 0;
			for (auto i : newNode) mx = max(mx, w[i] + delta[i]);
			if (mx <= mxOld) okOld = 1;
			if (mx >= mxOld) {
				for (auto i : newNode)
					if (mx == w[i] + delta[i]) mark[i] = 1;
			}
		} 
		if (okOld) {
			for (int i = 1; i <= n; ++ i) mark[i] = (w[i] == mxOld);
		}
		int res = 0;
		for (int i = 1; i <= n; ++ i) res += mark[i];
		printf("%d ", res);
		for (int i = 1; i <= n; ++ i) if (mark[i]) printf("%d ", i);
		printf("\n");
	}
}