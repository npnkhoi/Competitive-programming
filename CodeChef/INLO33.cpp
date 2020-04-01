#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second

const int N = 300 + 5;
const long long oo = 1e18 + 7;

typedef pair<int, int> ii;
typedef pair<long long, int> li;
typedef pair<int, ii> iii;

int tc, n, m;
vector<ii> adj[N];
int s, t, Time[N];
long long dist[N];
priority_queue<li, vector<li>, greater<li> > heap;

void dijsktra() {
	for (int i = 1; i <= n; ++ i) dist[i] = oo;
	
	dist[s] = 0;
	heap.push(mp(0, s));
	
	while (!heap.empty()) {
		li tmp = heap.top();
		heap.pop();

		if (tmp.first != dist[tmp.second]) continue;

		long long t = (tmp.fi + Time[tmp.se] - 1) / Time[tmp.se] * Time[tmp.se];

		// cerr << tmp.se << " " << "wait till " << t << "\n";

		for (ii v : adj[tmp.second]) {
			if (t + v.second < dist[v.first]) {
				dist[v.first] = t + v.second;
				heap.push(make_pair(dist[v.first], v.first));
			} 
		}
	}
}

int main() {
	scanf("%d%d", &s, &t);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &Time[i]);
	}
	for (int i = 1; i <= m; ++ i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}
	dijsktra();
	// for (int i = 1; i <= n; ++ i) cerr << dist[i] << " ";
	// cerr << "\n";
	printf("%lld", dist[t]);
}