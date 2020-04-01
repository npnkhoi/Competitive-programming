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
#define task "ISPITI"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;
int n, idx;
ii a[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".ans", "w", stdout);
	cin >> n;
	REP(i, n) {
		char type;
		cin >> type;
		if (type == 'D') {
			idx ++;
			cin >> a[idx].fi >> a[idx].se; 
		} else {
			bool flag = 0;
			int k, res;
			cin >> k;
			FOR(i, 1, idx) if (i != k && a[i].fi >= a[k].fi && a[i].se >= a[k].se) {
				//cerr << i << "\n";
				if (!flag) res = i;
				else if (a[i].se < a[res].se) res = i;
				else if (a[i].se == a[res].se && a[i].fi < a[res].fi) res = i;
				flag = 1;
			}
			if (flag) cout << res << "\n";
			else cout << "NE\n";
		}
		//cerr << "done query " << i << "\n";
	}	
}
