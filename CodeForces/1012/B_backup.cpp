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
int res, cnt[2], emp[2], lastAtRow[N], lastAtCol[N];
int lab[2][N], rnk[2][N], markRow[N], markCol[N];

int root(int id, int u) {
	if (lab[id][u] == -1) return u;
	else return lab[id][u] = root(id, lab[id][u]);
}

void merge(int id, int u, int v) {
	u = root(id, u), v = root(id, v);
	if (u == v) return;
	cnt[id] --;
	if (rnk[id][u] > rnk[id][v]) lab[id][v] = u;
	else {
		lab[id][u] = v;
		rnk[id][v] += (rnk[id][u] == rnk[id][v]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m >> q;
	memset(lab, -1, sizeof lab);
	memset(lastAtCol, -1, sizeof lastAtCol);
	memset(lastAtRow, -1, sizeof lastAtRow);
	emp[0] = n; emp[1] = m;
	FOR(i, 1, q) {
		cin >> x[i] >> y[i];
		if (!markRow[x[i]]) {
			cnt[0] ++;
			emp[0] --;
			markRow[x[i]] = 1; 
		}
		if (lastAtCol[y[i]] != -1) {
			merge(0, x[i], lastAtCol[y[i]]);
		}

		if (!markCol[y[i]]) {
			cnt[1] ++;
			emp[1] --;
			markCol[y[i]] = 1;
		}
		if (lastAtRow[x[i]] != -1) {
			merge(1, y[i], lastAtRow[x[i]]);
		}
		lastAtRow[x[i]] = y[i];
		lastAtCol[y[i]] = x[i];
	}
	cout << max(0, min(cnt[0], cnt[1]) - 1) + emp[0] + emp[1];
}
