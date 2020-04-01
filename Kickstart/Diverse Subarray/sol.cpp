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
#define task "test"
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

struct STNode {
	int l, r, val, lazy;
};

struct LazySegmentTree {
private:
	vector<STNode> a;
public:
	void build(int p, int l, int r) {
		a[p].val = a[p].lazy = 0;
		a[p].l = l;
		a[p].r = r;
		if (l < r) {
			int mid = (l + r) / 2;
			build(2 * p, l, mid);
			build(2 * p + 1, mid + 1, r);
		}
	}
	void init(int n) {
		a.resize(8 * n + 1);
		build(1, 1, n);
	}
	void down(int p) {
		a[2 * p].lazy += a[p].lazy;
		a[2 * p + 1].lazy += a[p].lazy;
		// depend on type of query
		a[p].val += a[p].lazy;
		a[p].lazy = 0;
	}
	void update(int p, int l, int r, int val) {
		down(p);
		if (a[p].l > r || l > a[p].r) return;
		if (l <= a[p].l && a[p].r <= r) {
			a[p].lazy = val;
			down(p);
			return;
		}
		update(2 * p, l, r, val);
		update(2 * p + 1, l, r, val);
		// depend on type of query
		a[p].val = max(a[2 * p].val, a[2 * p + 1].val);
	}
	int get(int p, int l, int r) {
		down(p);
		if (a[p].l > r || l > a[p].r) return -1;
		if (l <= a[p].l && a[p].r <= r) {
			return a[p].val;
		}
		// depend on type of query
		return max(get(2 * p, l, r), get(2 * p + 1, l, r));
	}
} IT;	

const int A = 1e5 + 5, N = 1e5 + 5;

int tc, n, s;
vector<int> pos[A];
int a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> tc;
	FOR(iTest, 1, tc) {
		cin >> n >> s;

		IT.init(n);
		int res = 0;

		FOR(i, 1, n) {
			int val;
			cin >> val;
			a[i] = val;
			pos[val].push_back(i);

			int t = pos[val].size();
			IT.update(1, (t >= s + 1 ? pos[val][t - s - 1] + 1: 1), i, +1);
			// cerr << (t >= s + 1 ? pos[val][t - s - 1] + 1: 1) << ' ' << i << ' ' << "+ 1\n";

			if (t >= s + 1) {
				IT.update(1, (t >= s + 2 ? pos[val][t - s - 2] + 1: 1), 
					pos[val][t - s - 1], - s);
				// cerr << (t >= s + 2 ? pos[val][t - s - 2] + 1: 1) << ' ' << 
				// pos[val][t - s - 1] << " -" << s << '\n';
			}
			res = max(res, IT.get(1, 1, n));
			// cerr << "State at " << i << ": ";
			// FOR(j, 1, i) cerr << IT.get(1, j, j) << ' ';
			// cerr << '\n';
		}
		cout << "Case #" << iTest << ": " << res << '\n';
		FOR(i, 1, n) pos[a[i]].clear();
	}
}
