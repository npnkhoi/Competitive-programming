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

const int N = 2e5 + 5;
int m, n, q, x[N], y[N];
int res;
int lab[N], rnk[N], lastAt[N];

int root(int u) {
	if (lab[u] == -1) return u;
	else return lab[u] = root(lab[u]);
}

void merge(int u, int v) {
	u = root(u), v = root(v);
	if (u == v) return;
	if (rnk[u] > rnk[v]) lab[v] = u;
	else {
		lab[u] = v;
		rnk[v] += (rnk[u] == rnk[v]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m >> q;
	memset(lab, -1, sizeof lab);
	memset(lastAt, -1, sizeof lastAt);
	FOR(i, 1, q) {
		cin >> x[i] >> y[i];
		if (lastAt[y[i]] != -1) merge(x[i], lastAt[y[i]]);
		lastAt[y[i]] = x[i];
	}	
	FOR(i, 1, n) res += (root(i) == i);
	res --;
	FOR(i, 1, m) res += (lastAt[i] == -1);
	cout << res;
}