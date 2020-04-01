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

#define task "SUM"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

int n;
stack<ii> stMin, stMax;

void push(stack<ii> &st, int val, int cnt) {
	if (!st.empty() && st.top().fi == val) {
		st.top().se += cnt;
	} else st.push(mp(val, cnt));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> n;
	long long res = 0, sumMin = 0, sumMax = 0;
	FOR(i, 1, n) {
		int val, cnt;
		cin >> val;

		cnt = 1;
		sumMax += val;
		while (!stMax.empty() && stMax.top().fi < val) {
			ii tmp = stMax.top();
			stMax.pop();
			cnt += tmp.se;
			sumMax += 1LL * (val - tmp.fi) * tmp.se;
		}
		push(stMax, val, cnt);

		cnt = 1;
		sumMin += val;
		while (!stMin.empty() && stMin.top().fi > val) {
			ii tmp = stMin.top();
			stMin.pop();
			cnt += tmp.se;
			sumMin += 1LL * (val - tmp.fi) * tmp.se;
		}
		push(stMin, val, cnt);

		res += sumMax - sumMin;
		// debug(sumMin);
		// debug(sumMax);
	}	
	cout << res;
	return 0;
}
