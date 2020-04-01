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

int n, a[N], cnt[N][25];
ll res;

bool ok(int l, int r) {
	REP(i, 20) if (cnt[r][i] - cnt[l-1][i] > 1) return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		REP(j, 20) cnt[i][j] = cnt[i-1][j] + ((a[i] & (1 << j)) > 0);
		int l = 1, r = i, bs = r;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (ok(mid, i)) bs = mid, r = mid - 1;
			else l = mid + 1;
		}
		res += i - bs + 1;
	}	
	cout << res;
}
