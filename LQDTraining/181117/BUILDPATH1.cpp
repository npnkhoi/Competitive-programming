#include <bits/stdc++.h>
using namespace std;

typedef pair<double, int> Pack;

const int N = 1005;

int n, m, link[N][N], mark[N];
double x[N], y[N], mst, dist[N];
priority_queue<Pack, vector<Pack>, greater<Pack> > heap;

double calcDist(int u, int v) {
	if (link[u][v]) return 0;
	else return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lf%lf", &x[i], &y[i]);
	}
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		link[u][v] = link[v][u] = 1;
	}
	mark[1] = 1;
	for (int i = 2; i <= n; ++ i) {
		dist[i] = calcDist(1, i);
		heap.push(make_pair(dist[i], i));
	}
	for (int i = 1; i < n; ++ i) {
		while (1)	{
			Pack u = heap.top();
			heap.pop();
			if (u.first != dist[u.second]) continue;
			// cerr << "fix " << u.second << "\n";
			mark[u.second] = 1;
			mst += u.first;
			for (int i = 1; i <= n; ++ i) {
				if (!mark[i] && calcDist(i, u.second) < dist[i]) {
					dist[i] = calcDist(i, u.second);
					heap.push(make_pair(dist[i], i));
				}
			}
			break;
		}
		// cerr << "done " << i << "\n";
	}
	printf("%.2lf", mst);
}
