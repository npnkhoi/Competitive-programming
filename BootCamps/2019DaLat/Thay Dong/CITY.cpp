#include <bits/stdc++.h>
using namespace std;

const int MASK = (1 << 19) + 5;
const int oo = 1e9 + 7;

vector<vector<int> > adj = {
	{2, 3, 4, 5, 6, 7},
	{1, 3, 7, 8, 9, 10},
	{1, 2, 4, 10, 11, 12},
	{1, 3, 5, 12, 13, 14},
	{1, 4, 6, 14, 15, 16},
	{1, 5, 7, 16, 17, 18},
	{1, 2, 6, 8, 18, 19},
	{2, 7, 9, 19},
	{2, 8, 10},
	{2, 3, 9, 11},
	{3, 10, 12},
	{3, 4, 11, 13},
	{4, 12, 14},
	{4, 5, 13, 15},
	{5, 14, 16},
	{5, 6, 15, 17},
	{6, 16, 18},
	{6, 7, 17, 19},
	{7, 8, 18}
};

int tc, n, m, mask1, mask2;
int d[MASK];
pair<int, pair<int, int> > trace[MASK];
queue<int> q;

void doTrace(int mask) {
	if (mask == mask1) return;
	doTrace(trace[mask].first);
	printf("%d %d\n", trace[mask].second.first + 1, trace[mask].second.second + 1);
}

int main() {
	freopen("CITY.inp", "r", stdin);
	freopen("CITY.out", "w", stdout);
	n = 19;
	scanf("%d", &tc);
	while (tc --) {
		mask1 = mask2 = 0;
		scanf("%d", &m);
		int u;
		for (int i = 1; i <= m; ++ i) {
			scanf("%d", &u);
			mask1 |= (1 << (u - 1));
			// cerr << u - 1 << " ";
		}
		// cerr << "\n";
		for (int i = 1; i <= m; ++ i) {
			scanf("%d", &u);
			mask2 |= (1 << (u - 1));
			// cerr << u - 1 << " ";
		}
		// cerr << "\n";
		for (int i = 0; i < (1 << n); ++ i) {
			d[i] = oo;
		}
		d[mask1] = 0;
		q.push(mask1);

		while (!q.empty()) {
			int mask = q.front();
			q.pop();
			for (int i = 0; i < n; ++ i) {
				if ((mask & (1 << i)) == 0) continue;
				for (int v : adj[i]) {
					int j = v - 1;
					if ((mask & (1 << j))) continue;
					int newMask = (mask ^ (1 << i)) | (1 << j);
					if (d[newMask] == oo) {
						d[newMask] = d[mask] + 1;
						q.push(newMask);
						trace[newMask] = make_pair(mask, make_pair(i, j));
					}
				}
			}
		}
		printf("%d\n", d[mask2]);
		doTrace(mask2);
	}
}