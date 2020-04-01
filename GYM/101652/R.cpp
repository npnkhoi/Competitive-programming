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

int n, x;
long double v0, deltaY, ang, v[N], Free, res, a, b;
int l[N], r[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> x >> v0; // v is real
	FOR(i, 1, n) {
		cin >> l[i] >> r[i] >> v[i];
		Free += l[i] - r[i - 1];
		deltaY += v[i] * (r[i] - l[i]);
	}

	ang = -deltaY / Free;
	b = v0 / sqrt(1 + ang * ang);
	a = ang * b;

	res = Free / b;
	FOR(i, 1, n) {
		res += (r[i] - l[i]) / (v[i] / (b * b + (a + v[i]) * (a + v[i])) * a);
	}
	if (res > 2 * x / v0) cout << "Too hard";
	else cout << fixed << setprecision(3) << res << '\n';
}
