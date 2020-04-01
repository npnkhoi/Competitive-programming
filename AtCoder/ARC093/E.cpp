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
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1000 + 5;
const int M = 2000 + 5;
const ll md = 1e9 + 7;
const int oo = 1e9 + 7;
struct Edge{
	int u, v, c;
	bool inMST;
	bool operator < (Edge oth) {
		return c < oth.c;
	}
} e[M]; 
int n, m, lab[N], rnk[N];
int cntLower, cntEqual, cntUpper;
vector<ii> adj[N];
ll x, mst;

ll Pow(int x) {
	if (x == 0) return 1;
	else {
		ll res = Pow(x / 2);
		res = res * res % md;
		if (x % 2) res = res * 2 % md;
		return res;
	}
}
int root(int u) {
	if (lab[u] == -1) return u;
	else return lab[u] = root(lab[u]);
}
void join(int u, int v) {
	u = root(u), v = root(v);
	if (rnk[u] > rnk[v]) {
		lab[v] = u;
	} else {
		lab[u] = v;
		if (rnk[u] == rnk[v]) rnk[v] ++;
	}
}
int maxEdge(int u, int des, int par) {
	if (u == des) return 0;
	else {
		REP(j, adj[u].size()) {
			ii v = adj[u][j];
			if (v.fi != par) {
				int tmp = maxEdge(v.fi, des, u);
				if (tmp != -1) return max(v.se, tmp);
			}
		}
		return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m >> x;
	REP(i, m) {
		cin >> e[i].u >> e[i].v >> e[i].c;
		e[i].inMST = 0;
	}	
	sort(e, e+m);
	memset(lab, -1, sizeof lab);
	REP(i, m) {
		int u = e[i].u, v = e[i].v;
		//cerr << u << " " << v << "\n";
		if (root(u) != root(v)) {
			mst += e[i].c;
			e[i].inMST = 1;
			join(u, v);
			adj[u].pb(mp(v, e[i].c));
			adj[v].pb(mp(u, e[i].c));
			//cerr << u << " " << v << " " << e[i].c << "\n";
		}
	}
	//cerr << "ok\n";
	REP(i, m) if (!e[i].inMST) {
		//cerr << i << "\n";
		ll tmp = mst + e[i].c - maxEdge(e[i].u, e[i].v, -1);
		//cerr << e[i].u << " " << e[i].v << " " << maxEdge(e[i].u, e[i].v, -1) << "\n";
		if (tmp < x) cntLower ++;
		else if (tmp == x) cntEqual ++;
		else cntUpper ++;
	}
	//cerr << cntLower << " " << cntEqual << " " << cntUpper << "\n";
	if (mst > x) cout << 0;
	else if (mst == x) cout << ((Pow(n-1) - 2) * Pow(m-n+1) % md + 2 * (Pow(cntEqual) - 1) * Pow(cntUpper) % md) % md;
	else cout << 2 * (Pow(cntEqual) - 1) % md * Pow(cntUpper) % md;
}
