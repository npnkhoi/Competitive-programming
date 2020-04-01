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

int n, x, idx, cnt[N], d[N], ft[N], pre[N];
bool odd;
unordered_map<ll, int> lo, hi;
ll bound, l[N], r[N];

void update(int i, int val) {
	if (i == 0) return;
	for (; i <= n; i += i & -i) ft[i] += val;
}

int get(int i) {
	int res = 0;
	for (; i; i -= i & -i) res += ft[i];
	return res;
}

int get(int l, int r) {
	if (l == 0) return get(r);
	return get(r) - get(l - 1);
}

void push(unordered_map<ll, int> &m, ll val) {
	m[val] ++;
}

void del(unordered_map<ll, int> &m, ll val) {
	if (m[val] == 1) m.erase(val);
	else m[val] --;
}

void marking(ll l, ll r) {
	l = max(l, 0LL);
	r = min(r, (ll)n);
	if (l > r) return;
	pre[l] ++;
	pre[r + 1] --;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) {
		cin >> x;
		cnt[x] ++;
		update(x, +1);
		odd ^= (x % 2);
	}

	FORD(i, n, 1) {
		REP(NhiThun, cnt[i]) d[++idx] = i;
	}
	
	l[1] = d[1];
	FOR(i, 2, n) r[1] += min(d[i], 1);

	push(lo, l[1] - r[1]);
	
	update(d[1], -1);
	FOR(i, 2, n) {
		l[i] = l[i - 1];
		r[i] = r[i - 1];

		l[i] += d[i];
		update(d[i], -1);
		r[i] += -min(d[i], i - 1) + get(i, n);

		push(lo, l[i] - r[i] - (ll) i * (i-1));
	}
	push(hi, (ll)n * (n + 1) - l[n]);

	marking(max(0LL, lo.rbegin() -> first), min((ll)d[n], hi.begin() -> first));
	d[0] = n;
	FORD(i, n, 1) {
		del(lo, l[i] - r[i] - (ll) i * (i-1));
		l[i] -= d[i];
		r[i] += min(d[i], i);
		push(hi, r[i] + (ll) i * (i-1) - l[i]);
		marking(max((ll)d[i], (lo.empty() ? 0LL : lo.rbegin() -> first)), min((ll)d[i - 1], hi.begin() -> first));
	}
	// cerr << "ok\n";
	bool flag = 0;
	int cur = 0;
	FOR(i, 0, n) {
		cur += pre[i];
		if (cur > 0 && i % 2 == odd) {
			cout << i << ' ';
			flag = 1;
		}
	}
	if (!flag) cout << -1;
}	
