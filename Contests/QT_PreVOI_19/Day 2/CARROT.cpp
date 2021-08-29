#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "CARROT"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 7000 + 5, oo = 1e9 + 7;

int n, f[N][N];
lint s[N];

int getMax(int i1, int i2, int j) {
	int ret = -oo;
	FOR(i, i1, i2) ret = max(ret, f[i][j]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	FOR(i, 1, n) f[0][i] = 1;
	FOR(l, 1, n - 1) {
		int t = l - 1;
		int tmp = f[l - 1][l];
		FOR(r, l + 1, n) {
			if (s[l] - s[t] > s[r] - s[l]) f[l][r] = -oo;
			else {
				while (t > 0 && s[l] - s[t - 1] <= s[r] - s[l]) {
					--t;
					tmp = max(tmp, f[t][l]);
				}
				f[l][r] = 1 + tmp;
			}
		}
	}
	int res = 0;
	FOR(i, 0, n - 1) res = max(res, f[i][n]);
	cout << res;
}
