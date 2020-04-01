#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()
#define task ""
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 105;

int n, a[N], pos1, res;
vi pre;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	FOR(i, 1, n) {
		if (a[i] == 1) {
			pos1 = i;
			break;
		}
		pre.push_back(a[i]);
	}
	sort(all(pre));
	res = n;
	FORD(i, n, 1) {
		if (a[i] == 1) break;
		if (i < n && a[i] > a[i + 1]) break;
		res = min(res, n - ((upper_bound(all(pre), a[i]) - pre.begin() - 1) + (n - i + 1)) + i - 1);
	}
	cout << res;
}
