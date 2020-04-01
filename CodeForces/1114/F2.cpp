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

template<class X, class Y>
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }

const int N = 1505;

int n, res, sum;
int s[N];
map<int, int> f[N], g, tg;
map<int, ii> tf[N];

void trace(int last) {
	if (last == 0) return;
	trace(tf[last][sum].second);
	cout << tf[last][sum].first << ' ' << last << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) {
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	FOR(l, 1, n) {
		FOR(r, l, n) {
			if (f[r][s[r] - s[l - 1]] < g[s[r] - s[l - 1]] + 1) {
				f[r][s[r] - s[l - 1]] = g[s[r] - s[l - 1]] + 1;
				tf[r][s[r] - s[l - 1]] = {l, tg[s[r] - s[l - 1]]};
			}
		}
		for (auto it = f[l].begin(); it != f[l].end(); ++ it) {
			if (g[it -> first] < it -> second) {
				g[it -> first] = it -> second;
				tg[it -> first] = l;
			}
		}
	}
	int last;
	for (auto it = g.begin(); it != g.end(); ++ it) {
		if (res < it -> second) {
			res = it -> second;
			last = tg[it -> first];
			sum = it -> first;
		}
	}
	cout << res << '\n';
	trace(last);
}
