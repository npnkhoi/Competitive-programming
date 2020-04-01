#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e3 + 5;

int n, x[N], y[N], a[N], b[N];
set<ii> data;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) cin >> x[i] >> y[i];
	FOR(i, 1, n) cin >> a[i] >> b[i];
	FOR(i, 1, n) {
		data.clear();
		int u = x[1] + a[i], v = y[1] + b[i];
		//cerr << u << ' ' << v << '\n';
		FOR(j, 1, n) 
			if (j != i) data.insert(mp(a[j], b[j]));
		bool flag = 1;
		FOR(j, 2, n) {
			int z = u - x[j], t = v - y[j];
			if (data.find(mp(z, t)) == data.end()) {
				flag = 0;
				break;
			} else data.erase(mp(z, t));
		}
		if (flag) {
			cout << u << ' ' << v << '\n';
			return 0;
		}
	}
}
