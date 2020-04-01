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

const int N = 4005, md = 1e9 + 7;

int tc, n, f[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	f[0] = f[1] = 1;
	FOR(i, 2, 4000) {
		FOR(j, 0, i - 1) f[i] = (f[i] + (lint) f[j] * f[i - j - 1] % md) % md;
	}
	cin >> tc;
	while (tc --) {
		cin >> n;
		n /= 2;
		cout << f[n] << '\n';
	}
}
