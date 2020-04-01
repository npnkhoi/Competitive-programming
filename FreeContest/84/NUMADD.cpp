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

int n, a[105];
queue<int> q;
set<int> nums;
set<int>::iterator it;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int tc; cin >> tc;	
	REP(khue, tc) {
		nums.clear();
		cin >> n;
		int u;
		REP(i, n) cin >> u, q.push(u);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (it = nums.begin(); it != nums.end(); it ++) {
				int v = abs(u - *it);
				if (nums.find(v) == nums.end()) {
					nums.insert(v);	
					q.push(v);
				}
				
			}
			nums.insert(u);
		}
		/*cerr << "\n";
		for (it = nums.begin(); it != nums.end(); it ++) cerr << *it << " "; cerr << "\n";
		cerr << "\n";*/
		cout << ((int) nums.size() - n - (*nums.begin() == 0)) % 2;
	}
}
