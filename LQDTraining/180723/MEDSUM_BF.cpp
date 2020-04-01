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
#define task "MEDSUM"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 200 + 5;
const int L = 2e4 + 5;
const int md = 1e9;
int n, l, a[N][N], b[2*N];
int res;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".ans", "w", stdout);
	cin >> n >> l;
	FOR(i, 1, n) {
		FOR(j, 1, l) cin >> a[i][j];
		//sort(a[i] + 1, a[i] + l + 1);
	}
	FOR(i, 1, n-1) FOR(j, i+1, n) {
		FOR(k, 1, l) b[k] = a[i][k];
		FOR(k, 1, l) b[l+k] = a[j][k];
		sort(b + 1, b + 2*l + 1);
		res = (res + b[l]) % md;
	}
	cout << res;
}
