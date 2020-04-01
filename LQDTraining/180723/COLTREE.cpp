#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "COLTREE"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

struct Query {
	int l, r, id;
	Query(): l(0), r(0), id(0) {}
	Query(int _l, int _r, int _id): l(_l), r(_r), id(_id) {}
};

int n, m, root, idx, block, diff;
vi adj[N];
int num[N], tail[N], col[N], cnt[N], res[N];
vi hub;
vector<Query> que;

void dfs(int u, int par) {
	num[u] = tail[u] = ++ idx;
	REP(j, adj[u].size()) {
		int v = adj[u][j];
		if (v != par) {
			dfs(v, u);
			tail[u] = tail[v];
		}
	}
}

bool cmp(Query a, Query b) {
	if (a.l / block != b.l / block) {
		return a.l / block < b.l / block;
	}
	else return a.r < b.r;
}
void add(int val) {
	if (cnt[val] == 0) diff ++;
	cnt[val] ++;
}
void del(int val) {
	if (cnt[val] == 1) diff --;
	cnt[val] --;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> n >> m >> root;
	REP(i, n-1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(root, -1);
	//FOR(i, 1, n) cerr << num[i] << " "; cerr << "\n";
	//FOR(i, 1, n) cerr << tail[i] << " "; cerr << "\n";

	FOR(i, 1, n) {
		cin >> col[num[i]];
		//cerr << col[num[i]] << "\n";
		hub.pb(col[num[i]]);
	}
	//cerr << "\n";
	//FOR(i, 1, n) cerr << col[i] << " "; cerr << "\n";
	sort(hub.begin(), hub.end());
	int p = 1;
	FOR(i, 1, (int) hub.size() - 1) if (hub[i] != hub[i-1]) hub[p++] = hub[i];
	hub.resize(p);
	//REP(i, p) cerr << hub[i] << " "; cerr << "\n"; 
	FOR(i, 1, n) col[i] = upper_bound(hub.begin(), hub.end(), col[i]) - hub.begin();
	//FOR(i, 1, n) cerr << col[i] << " "; cerr << "\n";

	FOR(i, 1, m) {
		int u;
		cin >> u;
		que.pb(Query(num[u], tail[u], i));
	}
	block = (int) sqrt(n);
	sort(que.begin(), que.end(), cmp);
	int curL = 1, curR = 0;
	diff = 0;
	REP(i, m) {
		while (curL < que[i].l) {
			del(col[curL]);
			curL ++;
		}
		while (curL > que[i].l) {
			curL --;
			add(col[curL]);
		}
		while (curR > que[i].r) {
			del(col[curR]);
			curR --;
		}
		while (curR < que[i].r) {
			curR ++;
			add(col[curR]);
		}
		res[que[i].id] = diff;
	}
	FOR(i, 1, m) cout << res[i] << "\n";
} 
