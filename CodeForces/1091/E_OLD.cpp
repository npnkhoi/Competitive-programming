#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 5e5 + 5;

int n, x, idx, cnt[N], a[N], ft[N];
bool odd;
ll bound, l, r;

void update(int i, int val) {
	for (; i <= n; i += i & -i) ft[i] += val;
}

int get(int i) {
	int res = 0;
	for (; i; i -= i & -i) res += ft[i];
	return res;
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	odd = 0;
	FOR(i, 1, n) {
		cin >> x;
		cnt[x] ++;
		update(x, +1);
		odd ^= (x % 2);
	}
	FORD(i, n, 1) {
		REP(NhiThun, cnt[i]) a[++idx] = i;
	}
	
	l = a[1];
	FOR(i, 2, n) r += min(a[i], 1);

	bound = l - r;
	update(a[1], -1);
	cerr << l << ' ' << r << '\n';
	FOR(i, 2, n) {
		l += a[i];

		update(a[i], -1);
		r -= min(a[i], i - 1);
		r += get(i, n);
		bound = max(bound, l - r - (ll) i * (i-1));
		cerr << l << ' ' << r << '\n';
	}
 	if (odd ^ (bound % 2)) bound ++;
	cerr << "ok\n";
	cerr << bound << '\n';
	for (int i = bound; i <= a[n - 1]; i += 2) cout << i << ' ';
}	
