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
int n, a[N], b[N], v[N], res;

int count(int v[], int l, int r) {
	//cerr << "count " << l << " " << r << "\n";
	//cerr <<  upper_bound(v, v+n, r) - upper_bound(v, v+n, l-1) << "\n";
	return upper_bound(v, v+n, r) - upper_bound(v, v+n, l-1);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];	
	REP(i, 29) {
		//cerr << "bit " << i << "\n";
		REP(j, n) {
			v[j] = b[j] & ((1 << (i+1)) - 1);
			//cerr << v[j] << " ";
		}
		//cerr << "\n";
		sort(v, v + n);
		REP(j, n) {
			int tmp = a[j] & ((1 << (i+1)) - 1);
			//cerr << tmp << " ";
			if ((count(v, (1 << i) - tmp, (1 << i+1) - 1 - tmp) + count(v, (3 << i) - tmp, (3 << i+1) - 1 - tmp)) % 2) {
				res ^= (1 << i);
			}
		}
		//cerr << res << "\n";
	}
	cout << res;
}
