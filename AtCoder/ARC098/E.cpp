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
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e3 + 5;
int n, k, q, a[N], res;
vi tmp1, tmp2, v;
void trans() {
	if ((int) tmp1.size() >= k) {
		sort(tmp1.begin(), tmp1.end());
		REP(i, (int) tmp1.size() - k + 1) tmp2.pb(tmp1[i]);
	}
	tmp1.clear();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> k >> q;
	FOR(i, 1, n) {
		cin >> a[i];
		v.pb(a[i]);
	}
	sort(v.begin(), v.end());
	res = v.back() - v[0];

	REP(i, n) if (i == 0 || v[i] != v[i-1]) {
		int bound = v[i];

		tmp1.clear(); tmp2.clear();
		FOR(j, 1, n) {
			if (a[j] >= bound) tmp1.push_back(a[j]);
			else trans();
		}
		trans();

		if ((int) tmp2.size() >= q) {
			sort(tmp2.begin(), tmp2.end());
			res = min(res, tmp2[q-1] - tmp2[0]);
		} else break;
	}
	cout << res;
}
