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

const int N = 5e4 + 5, md = 1e9 + 7;

int tc, n;
ii a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> tc;
	while (tc --) {
		cin >> n;
		REP(i, n) cin >> a[i].X, a[i].Y = i + 1;
		REP(i, n) cin >> b[i].X, b[i].Y = i + 1;
		sort(a, a + n);
		sort(b, b + n);
		int i = n - 1, j = n - 1;
		lint res = 0;
		while (i >= 0 && j >= 0) {
			if (a[i].X > b[j].X) --i;
			else if (a[i].X < b[j].X) --j;
			else {
				res = (res + (lint) a[i].X * a[i].Y * b[j].Y) % md;
				--i; --j;
			}
		}
		cout << res << '\n';
	}	
}
