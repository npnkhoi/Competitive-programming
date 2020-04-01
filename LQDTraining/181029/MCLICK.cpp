#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N = 1e4 + 5;

int n, mark[N], res;
pair<int, int> topLeft[N], botRight[N];
queue<int> q;

bool depend(int u, int v) {
	// cerr << "depend " << u << " " << v << "n";
	int x = topLeft[u].fi;
	int y = botRight[u].se;
	// cerr << x << " " << y << "\n";
	return (topLeft[v].fi <= x && x <= botRight[v].fi && topLeft[v].se <= y && y <= botRight[v].se);
}

int main() {
	freopen("MCLICK.inp", "r", stdin);
	freopen("MCLICK.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &topLeft[i].fi, &topLeft[i].se);
		scanf("%d%d", &botRight[i].fi, &botRight[i].se);
	}
	mark[1] = 1;
	q.push(1);
	res = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = u + 1; v <= n; ++ v) {
			if (!mark[v] && depend(u, v)) {
				mark[v] = 1;
				q.push(v);
				res ++;
			}
		}
	}
	printf("%d", res);
}