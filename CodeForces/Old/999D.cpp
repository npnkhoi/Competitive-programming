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
#define task "0"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;
int a[N], n, m;
vi rem[N], tmp;
ll res;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i];
		rem[a[i] % m].pb(i);
	}	
	//REP(i, m) cerr << rem[i].size() << ' '; cerr << '\n'; 
	REP(i, 2*m) {
		res += (int) tmp.size();
		//cerr << res << '\n';
		int j = (i < m ? i : i-m);
		while ((int) rem[j].size() > n/m) {
			tmp.pb(rem[j].back());
			rem[j].pop_back();
		}
		while ((int) tmp.size() > 0 && (int) rem[j].size() < n/m) {
			rem[j].pb(tmp.back());
			tmp.pop_back();
		}
	}
	REP(i, m) REP(j, (int) rem[i].size()) {
		int u = rem[i][j];
		a[u] += (i - a[u] % m + m) % m;
	}
	cout << res << '\n';
	FOR(i, 1, n) cout << a[i] << ' ';
}
