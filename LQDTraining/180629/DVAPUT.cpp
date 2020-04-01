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
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;
const ll md = 1e9 + 7;
const int base1 = 26;
const int base2 = 37;

int n;
string s;
pll h[N], EXP[N];
vector<pll> v;

void hashInit() {
	EXP[0] = mp(1, 1);
	FOR(i, 1, n+1) {
		EXP[i].fi = EXP[i-1].fi * base1 % md;
		EXP[i].se = EXP[i-1].se * base2 % md;
	}
}
void hashBuild(string s, pll h[], int n) {
	h[0] = mp(0, 0);
	FOR(i, 1, n) {
		h[i].fi = (h[i-1].fi * base1 + s[i-1]) % md;
		h[i].se = (h[i-1].se * base2 + s[i-1]) % md;
	}
}
pll hashGet(pll h[], int l, int r) {
	pll res;
	res.fi = (h[r].fi - h[l-1].fi * EXP[r-l+1].fi + md * md) % md;
	res.se = (h[r].se - h[l-1].se * EXP[r-l+1].se + md * md) % md;
	return res;
}
bool ok(int x) {
	v.clear();
	FOR(i, x, n) v.pb(hashGet(h, i-x+1, i));
	sort(v.begin(), v.end());
	if ((int) v.size() >= 2) 
		REP(i, (int) v.size() - 1) if (v[i] == v[i+1]) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> s;
	hashInit();
	hashBuild(s, h, n);
	int l = 0, r = n-1, bs = l;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ok(mid)) bs = mid, l = mid + 1;
		else r = mid - 1;
	}	
	cout << bs;
}
