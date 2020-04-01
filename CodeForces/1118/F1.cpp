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

const int N = 3e5 + 5;

int n, sum1, sum2, res;
int a[N], cnt1[N], cnt2[N];
vi adj[N];


void dfs(int u, int par) {
	cnt1[u] = (a[u] == 1);
	cnt2[u] = (a[u] == 2);
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v, u);
		cnt1[u] += cnt1[v];
		cnt2[u] += cnt2[v];
	} 
	if ((cnt1[u] == sum1 && cnt2[u] == 0) || (cnt2[u] == sum2 && cnt1[u] == 0))
		res ++;
}

int main() {
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		if (a[i] == 1) sum1 ++;
		else if (a[i] == 2) sum2 ++;
	}
	REP(i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << res;
}