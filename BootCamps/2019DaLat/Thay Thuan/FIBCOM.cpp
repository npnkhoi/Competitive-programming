#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 1e4 + 5;

int n, p, m, res;
int mark[N];
pair<int, int> edge[M];

void update(int l, int r) {
	mark[l] ++;
	mark[r + 1] --;
}

int main() {
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= p; ++ i) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == r) continue;
		if (l > r) swap(l, r);
		edge[++ m] = make_pair(l, r);
	}
	res = n;
	for (int i = 1; i <= n; ++ i) {
		memset(mark, 0, sizeof mark);
		for (int j = 1; j <= m; ++ j) {
			if (edge[j].first <= i && i + 1 <= edge[j].second) {
				update(1, edge[j].first - 1);
				update(edge[j].second, n);
			} else {
				update(edge[j].first, edge[j].second - 1);
			}
		}
		int tmp = 0, cnt = 0;
		for (int i = 1; i <= n; ++ i) {
			tmp += mark[i];
			cnt += (tmp > 0);
		}
		res = min(res, cnt);
	}
	printf("%d", res);
}