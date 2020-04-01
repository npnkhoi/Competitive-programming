#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second

const int N = 20000 + 5;
const int M = 40000 + 5;
const long long oo = 1e18 + 7;

typedef pair<int, int> ii;
typedef pair<long long, int> li;
typedef pair<int, ii> iii;

int tc, n, m;
vector<ii> adj[N];
iii e[M];

int reach;
long long sumPath;
li dist[N];
int minEdge[N];
priority_queue<li, vector<li>, greater<li> > heap;

long long mst;
int lab[N];

void dijsktra() {
	for (int i = 0; i < n; ++ i) dist[i].fi = oo;
	
	dist[0] = mp(0, 0);
	heap.push(mp(0, 0));
	
	while (!heap.empty()) {
		li tmp = heap.top();
		heap.pop();

		if (tmp.first != dist[tmp.second].fi) continue;

		for (ii v : adj[tmp.second]) {
			if (tmp.first + v.second < dist[v.first].fi) {
				dist[v.first] = mp(tmp.first + v.second, v.second);
				heap.push(make_pair(dist[v.first].fi, v.first));
			} else if (tmp.first + v.second == dist[v.first].fi && v.se < dist[v.fi].se) {
				dist[v.fi].se = v.se;
			}
		}
	}

	reach = sumPath = 0;

	// cerr << "dist \n";
	// for (int i = 1; i < n; ++ i) cerr << dist[i] << " ";
	// cerr << "\n";

	for (int i = 1; i < n; ++ i) {
		if (dist[i].fi != oo) {
			sumPath += dist[i].se;
			reach ++;
		}
	}
}

int root(int u) {
	if (lab[u] == -1) return u;
	else return lab[u] = root(lab[u]);
}

void merge(int u, int v) {
	u = root(u), v = root(v);
	if (lab[u] < lab[v]) {
		lab[v] = u;
	} else {
		lab[u] = v;
		lab[v] -= (lab[u] == lab[v]);
	}
}

void kruskal() {
	memset(lab, -1, sizeof lab);
	mst = 0;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; ++ i) {
		int u = e[i].se.fi, v = e[i].se.se;
		if (root(u) != root(v)) {
			merge(u, v);
			mst += e[i].fi;
		}
	}
}

int main() {

	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++ i) {
			adj[i].clear();
			minEdge[i] = 1e9 + 7;
		}
		for (int i = 1; i <= m; ++ i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			adj[u].push_back(make_pair(v, c));
			adj[v].push_back(make_pair(u, c));
			e[i] = mp(c, mp(u, v));
			if (v == 0) swap(u, v);
			if (u == 0) minEdge[v] = min(minEdge[v], c);
		}
		dijsktra();
		// if (reach != n - 1) {
		// 	printf("NO\n"); 
		// 	continue;
		// }
		// bool flag = 0;
		// for (int i = 1; i < n; ++ i) {
		// 	if (dist[i] != minEdge[i]) {
		// 		flag = 1;
		// 		printf("NO\n");
		// 		break;
		// 	}
		// }
		// if (flag == 0) printf("YES\n");
		kruskal();
		// cerr << reach << " " << sumPath << " " << mst << "\n";
		if (reach == n - 1 && sumPath == mst) printf("YES\n");
		else printf("NO\n");
	}	
}