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

const int N = 1e5 + 5, oo = 1e9;

int n, x;
int a[N][7];

int get(int a[], int mask) {
	int res = 0;
	REP(i, x) {
		res += ((mask & (1 << i)) ? + a[i + 1] : - a[i + 1]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> x;
	FOR(i, 1, n) {
		FOR(j, 1, x) cin >> a[i][j];
	}
	int res = 0;
	REP(mask, (1 << x)) {
		int revMask = (1 << x) - mask - 1;
		int tmp = -oo;
		FOR(i, 1, n) {
			if (i > 1) {
				res = max(res, get(a[i], mask) + tmp);
			}
			tmp = max(tmp, get(a[i], revMask));
		}
	}
	cout << res;
}