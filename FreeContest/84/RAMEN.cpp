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

const int Q = 1e5 + 5;
const int N = 3e5 + 5;
const int M = 3e5 + 5;

long long m;
int n, q;
ll a[N], b[N];
priority_queue<li> heap;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> m >> n >> q;
	FOR(i, 1, n) {
		cin >> a[i];
		if (a[i] - a[i-1] > 1) heap.push(mp(a[i] - a[i-1] - 1, - (a[i-1] + 1)));
	}
	if (m - a[n] > 0) heap.push(mp(m-a[n], -a[n] - 1));
	if (m <= 3e5) {
		FOR(i, n+1, m) {
			ll len = heap.top().fi, idx = - heap.top().se;
			heap.pop();
			ll u = (len-1) / 2, v = len - (len+1) / 2;
			a[i] = idx + u;
			heap.push(mp(u, -(idx)));
			heap.push(mp(v, - (idx + len - v)));
			//cerr << len << " " << idx << " -> " << u << " " << idx << " " << v << " " << n - v + 1 << "\n";
 			//cerr << a[i] << "\n";
		}
	}
	FOR(i, 1, q) {
		cin >> b[i];
		cout << a[b[i]] << "\n";
	}
}