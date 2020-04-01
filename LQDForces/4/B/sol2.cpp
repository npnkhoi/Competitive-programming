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
#define sqr(x) ((x) * (x))
#define task ""
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 405;

int n, tc;
int x[N], y[N];

double area(int i, int j, int k) {
	double a = sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
	double b = sqrt(sqr(x[j] - x[k]) + sqr(y[j] - y[k]));
	double c = sqrt(sqr(x[k] - x[i]) + sqr(y[k] - y[i]));
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> tc;
	while (tc --) {
		cin >> n;
		FOR(i, 1, n) cin >> x[i] >> y[i];
		double res = 0;
		FOR(i, 1, n - 2) {
			FOR(j, i + 1, n - 1) {
				FOR(k, j + 1, n) {
					res = max(res, area(i, j, k));
				}
			}
		}
		cout << fixed << setprecision(10) << res << '\n';
	}
}
