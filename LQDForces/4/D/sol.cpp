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

const int N = 1e5 + 5;
const double EPS = 1e-9;

int n, m, tc;
int a[N];

bool check(double x) {
	int add = 0;
	FOR(i, 2, n) {
		add += (int)ceil((a[i] - a[i - 1]) / x) - 1;
	}
	return add <= m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("test2.inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> tc;
	while (tc --) {
		cin >> n >> m;
		cerr << m << ' ' << m << '\n';
		FOR(i, 1, n) cin >> a[i];
		sort(a + 1, a + n + 1);
		double l = 0, r = a[n] - a[1], mid, bs = r;
		while (r - l > EPS) {
			mid = (l + r) / 2;
			if (check(mid)) {
				bs = mid;
				r = mid - EPS;
			} else l = mid + EPS;
		}
		cout << fixed << setprecision(9) << bs << '\n';
	}
}
