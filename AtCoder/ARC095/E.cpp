#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "0"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 15;
int h, w;
string s[N];
bool vis[N];
vi half1, half2, id;

bool same(int u, int v) {
	REP(i, h) if (s[id[i]][u] != s[id[i]][v]) return false;
	return true;
}
bool rev(int u, int v) {
	REP(i, h) if (s[id[i]][u] != s[id[h-1-i]][v]) return false;
	return true;
}
bool palin(int u) {
	REP(i, h/2) if (s[id[i]][u] != s[id[h-1-i]][u]) return false;
	return true;
}
void check() {
	id.clear();
	REP(i, half1.size()) id.pb(half1[i]);
	REP(i, half2.size()) id.pb(half2[i]);
	//REP(i, (int) id.size()) cerr << id[i] << " "; cerr << "\n";
	memset(vis, 0, sizeof vis);
	bool flagPalin = 0;
	REP(i, w) if (!vis[i]) {
		int cntSame = 1, cntRev = 0;
		FOR(j, i+1, w-1) if (!vis[j]) {
			if (same(i, j)) cntSame ++, vis[j] = 1;
			else if (rev(i, j)) cntRev ++, vis[j] = 1;
		}
		if (palin(i)) {
			if (cntSame % 2) {
				if (!flagPalin) flagPalin = 1;
				else return;
			}
		} else {
			if (cntSame != cntRev) return;
		}
	}	
	cout << "YES";
	exit(0);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> h >> w;
	REP(i, h) cin >> s[i];
	//cerr << "ok\n";
	REP(mask, (1 << h)) if (__builtin_popcount(mask) == h/2) {
		half1.clear(); half2.clear();
		REP(i, h) {
			if ((mask & (1 << i)) > 0) 
				half1.pb(i);
			else half2.pb(i);
		}
		do check();
		while (next_permutation(half2.begin(), half2.end()));
	}
	cout << "NO";
}
