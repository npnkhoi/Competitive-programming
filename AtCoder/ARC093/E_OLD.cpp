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
struct Edge{
	int u, v, c;
	bool operator < (Edge oth) {
		return c < oth.c;
	}
} e[M]; 
int n, m, lab[N], rnk[N];
ll x;

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
ll MST() {
	ll res = 0;
	REP(i, m) {
		int u = e[i].u, v = e[i].v;
		if (root(u) != root(v)) {
			join(u, v);
			res += e[i].c;
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m >> x;
	REP(i, m) {
		cin >> e[i].u >> e[i].v >> e[i].c;
	}	
	sort(e, e+m);
	int cnt1 = 0, cnt2 = 0, cnt0 = 0;
	REP(i, m) {
		memset(lab, -1, sizeof lab);
		memset(rnk, 0, sizeof rnk);
		join(e[i].u, e[i].v);
		ll tmp = e[i].c + MST();
		if (tmp < x) cnt0 ++;
		else if (tmp == x) cnt1 ++;
		else if (tmp > x) cnt2 ++;
	}
	//cer  << cnt0 << " " << cnt1 << " " << cnt2 << "\n";
	if (cnt1 == 0) cout << 0;
	else if (cnt0 == 0) {
		//cout << ((Pow(n-1) - 2) * Pow(m-n+1) % md + 2 * (Pow(cnt1 - n + 1) - 1) % md * Pow(cnt2) % md) % md;
		cout << (Pow(cnt1) - 2) * Pow(cnt2) % md;
	} else cout << 2 * (Pow(cnt1) - 1) % md * Pow(cnt2) % md;
}
