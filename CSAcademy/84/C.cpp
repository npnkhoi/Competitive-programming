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

const int N = 1e5 + 5;
int n, a[N];
priority_queue<int> heap;
long long s; 
vector<ii> ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		heap.push(a[i]);
		s += a[i];
	}	
	if (s % 2) {
		cout << -1;
		return 0;
	}
	while (!heap.empty()) {
		if (heap.size() > 1) {
			int u = heap.top(); heap.pop();
			int v = heap.top(); heap.pop();
			if (u != v) {
				ans.pb(mp(u, u-v));
				heap.push(u-v);
			}
		} else {
			ans.pb(mp(heap.top(), heap.top()/2));
			break;
		}
	}
	cout << (int) ans.size() << '\n';
	REP(i, ans.size()) cout << ans[i].fi << ' ' << ans[i].se << '\n';
}
