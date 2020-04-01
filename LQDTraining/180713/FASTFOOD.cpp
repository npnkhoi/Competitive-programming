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
#define task "FASTFOOD"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1500 + 5;
int n, p, a[N][N];
vector<ii> pos[N*N];
int ft[N*N], cnt[2*N], f[N*N], g[N*N], v[N*N], mark[N*N], id[N];
void update(int pos, int val) {
	for (; pos <= p; pos += pos&-pos) ft[pos] = max(ft[pos], val);
}
int get(int pos) {
	int res = 0;
	for (; pos; pos -= pos & - pos) res = max(res, ft[pos]);
	return res;
}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	//cin >> n;
	scanf("%d", &n);
	FOR(i, 1, n) FOR(j, 1, n) {
		//cin >> a[i][j];
		scanf("%d", &a[i][j]);
		pos[a[i][j]].pb(mp(i, j));
	}
	FOR(val, 1, n*n) if (pos[val].size() > 0) {
		int m = pos[val].size();
		p = 0;
		REP(i, m) if (mark[pos[val][i].se] != val) {
			mark[pos[val][i].se] = val;
			v[++p] = pos[val][i].se;
		}
		sort(v + 1, v + p + 1);
		FOR(i, 1, p) id[v[i]] = i;

		FOR(i, 1, p) ft[i] = 0;
		REP(i, m) {
			f[i] = get(id[pos[val][i].se]) + 1;
			update(id[pos[val][i].se], f[i]);
		}
		FOR(i, 1, p) ft[i] = 0;
		FORD(i, m-1, 0) {
			int col = p - id[pos[val][i].se] + 1;
			g[i] = get(col) + 1;
			cnt[f[i] + g[i] - 1] ++;
			update(col, g[i]);
		}
	}
	FOR(i, 1, 2*n-1) 
		//cout << cnt[i] << '\n';
		printf("%d\n", cnt[i]);
}
