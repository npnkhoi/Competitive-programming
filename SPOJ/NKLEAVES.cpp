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

#define task ""

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5, K = 12;
const lint oo = 1e18 + 7;

int n, k;
int a[N];
lint dp[K][N], sum[N], p[N];
vector<ll> lines;

lint valAt(ll line, lint x) {
	return line.X * x + line.Y;
}

bool redun(ll a, ll b, ll c) {
	return (double) (b.Y - a.Y) / (a.X - b.X) >= (double) (c.Y - a.Y) / (a.X - c.X);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		p[i] = p[i - 1] + (lint)a[i] * i;
	}
	FOR(j, 1, n) dp[0][j] = oo;

	FOR(i, 1, k) {
		int l = 0;
		lines.clear();
		FOR(r, 1, n) {
			// add line
			ll newLine = mp(-r, dp[i - 1][r - 1] - p[r] + (lint)r * sum[r]);
			while (lines.size() >= 2 && redun(lines[lines.size() - 2], lines.back(), newLine)) 
				lines.pop_back();
			lines.push_back(newLine);
			// find next split point
			if (l >= lines.size()) l = lines.size() - 1;
			while (l + 1 < lines.size() && valAt(lines[l], sum[r]) >= valAt(lines[l + 1], sum[r]))
				++l;
			dp[i][r] = p[r] + valAt(lines[l], sum[r]);
			//cerr << i << ' ' << r << ' ' << dp[i][r] << '\n';
		}
	}
	cout << dp[k][n];
}
