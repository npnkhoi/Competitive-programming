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
#define task "E"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 1000 + 5;
const ll oo = 1e18 + 7;
int n, a[N];
ll f[N][N], le[N][N], ri[N][N];
ll res;
ii traceF[N][N], traceRes;
int traceLe[N][N], traceRi[N][N];
void doTrace(int l, int r, int pos) {
	if (l == r) return;
	else {
		doTrace(l, traceF[l][r].fi, pos);
		doTrace(traceF[l][r].fi + 1, traceF[l][r].se - 1, pos + 1);
		doTrace(traceF[l][r].se, r, pos + 2);
		printf("%d\n", pos + 1);
	}
}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", a + i);
	res = -oo;
	FOR(i, 1, n) {
		f[i][i] = le[i][1] = ri[i][1] = a[i];
		res = max(res, (ll) a[i]);
		traceLe[i][1] = i;
		traceRi[i][1] = i;
	}
	for (int d = 3; d <= n; d += 2) {
		FOR(l, 1, n-d+1) {
			int r = l+d-1;
			f[l][r] = -oo;
			for (int k = 1; k <= d - 2; k += 2) if (f[l][r] < le[l][k] + ri[r][d-k-1]) {
				f[l][r] = le[l][k] + ri[r][d-k-1];
				traceF[l][r] = mp(traceLe[l][k], traceRi[r][d-k-1]);
			}
			if (le[l][d-2] > f[l][r]) {
				le[l][d] = le[l][d-2];
				traceLe[l][d] = traceLe[l][d-2];
			} else {
				le[l][d] = f[l][r];
				traceLe[l][d] = r;
			}
			if (ri[l][d-2] > f[l][r]) {
				ri[r][d] = ri[r][d-2];
				traceRi[r][d] = traceRi[r][d-2];
			} else {
				ri[l][d] = f[l][r];
				traceRi[r][d] = l;
			}
			if (f[l][r] > res) {
				res = f[l][r];
				traceRes = mp(l, r);
			}
			cerr << l << " " << r << ": " << f[l][r] << ", " << traceF[l][r].fi << " " << traceF[l][r].se << "\n"; 
		}
	}	
	printf("%lld\n", res);
	cerr << " " << traceRes.fi << " " << traceRes.se << "\n";
	printf("%d\n", n - (traceRes.se - traceRes.fi + 1) + (traceRes.se - traceRes.fi + 1) / 2);
	FORD(i, n, traceRes.se + 1) printf("%d\n", i);
	FOR(i, 1, traceRes.fi - 1) printf("1\n");
	doTrace(traceRes.fi, traceRes.se, 1);
}
