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

int m, n, p, s;
int mark[N];
vi v[N], ps;
lint res = 0;
lint ans[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> p >> s;
		v[p].push_back(s);
		if (mark[p] == 0) {
			mark[p] = 1;
			ps.push_back(p);
		}
	} 	
	for (int x : ps) {
		sort(all(v[x]), greater<int>());
		lint sum = 0;
		REP(i, v[x].size()) {
			sum += v[x][i];
			if (sum <= 0) break;
			ans[i] += sum;
			res = max(res, ans[i]);
		}
	}
	cout << res << '\n';
}
