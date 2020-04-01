#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, int> li;
typedef pair<int, ii> Edge;

const int N = 3e5 + 5;
const long long oo = 1e18 + 7;

int n, m, k;
long long d[N];
vector<Edge> adj[N];
priority_queue<li, vector<li>, greater<li> > heap;
vector<int> ans;
int mark[N], preEdge[N];


int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++ i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back(make_pair(v, make_pair(c, i)));
		adj[v].push_back(make_pair(u, make_pair(c, i)));
	}
	for (int i = 2; i <= n; ++ i) d[i] = oo;
	heap.push(make_pair(0, 1));
	k ++;
	while (!heap.empty() && k > 0) {
		li u = heap.top();
		heap.pop();

		if (u.first != d[u.second]) continue;

		mark[preEdge[u.second]] = 1;
		k --;

		for (Edge v : adj[u.second]) {
			if (d[v.first] > d[u.second] + v.second.first) {
				d[v.first] = d[u.second] + v.second.first;
				preEdge[v.first] = v.second.second;
				heap.push(make_pair(d[v.first], v.first));
			}
		}
	}
	for (int i = 1; i <= m; ++ i) {
		if (mark[i]) ans.push_back(i);
	}
	printf("%d\n", (int) ans.size());
	for (int x : ans) printf("%d ", x);
}