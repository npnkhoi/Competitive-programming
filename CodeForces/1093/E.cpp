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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;

const int N = 2e5 + 5;

int n, m, row[N];
pair<int, int> a[N];
ordered_set ft[N];

void ins(int x, int y) {
	for (; x <= n; x += x & -x) ft[x].insert(y);
}

void del(int x, int y) {
	for (; x <= n; x += x & -x) ft[x].erase(y);	
}

int get(int x, int l, int r) {
	if (x == 0) return 0;

	int ret = 0;
	for (; x; x -= x & -x) {
		ret += ft[x].order_of_key(r + 1) - ft[x].order_of_key(l);
	}
	return ret;
}

// lint Rand(lint l, lint r) {
//     lint res = l + (
//     1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
//     1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
//     1LL * rand() * (RAND_MAX + 1) +
//     1LL * rand()) % (r - l + 1);
//     if (res < 0) res += r - l + 1;
//     return res;
// }

// void test() {
// 	ofstream inp(task".inp");
// 	int n = 2e5, m = 2e5;
// 	inp << n << ' ' << m << '\n';
// 	int seq[n];
// 	REP(i, n) seq[i] = i + 1;
// 	random_shuffle(seq, seq + n);
// 	REP(i, n) inp << seq[i] << ' '; inp << '\n';
// 	random_shuffle(seq, seq + n);
// 	REP(i, n) inp << seq[i] << ' '; inp << '\n';
	
// 	REP(i, m) {
// 		int ask = Rand(1, 2);
// 		if (ask == 1) {
// 			int l1 = Rand(1, n - 1), l2 = Rand(1, n - 1);
// 			inp << ask << ' ' << l1 << ' ' << Rand(l1 + 1, n) << ' ' << l2 << ' ' << Rand(l2 + 1, n) << '\n';
// 		} else {
// 			int x = Rand(1, n - 1);
// 			inp << ask << ' ' << x << ' ' << Rand(x + 1, n) << '\n';
// 		}
// 	}
// 	inp.close();
// }

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// test();
	// freopen(task".inp", "r", stdin);
	// freopen(task".out", "w", stdout);

	// double Time = clock();
	cin >> n >> m;

	int x;
	FOR(i, 1, n) {
		cin >> x;
		a[x].X = i;
	} 
	FOR(i, 1, n) {
		cin >> x;
		a[x].Y = i;
	}

	FOR(i, 1, n) {
		ins(a[i].X, a[i].Y);
		row[a[i].Y] = a[i].X;
	}

	while (m --) {
		int ask, x, y, u, v;
		cin >> ask;
		if (ask == 1) {
			cin >> x >> u >> y >> v;
			cout << get(u, y, v) - get(x - 1, y, v) << '\n';
		} else {
			cin >> x >> y;
			del(row[x], x);
			del(row[y], y);
			swap(row[x], row[y]);
			ins(row[x], x);
			ins(row[y], y);
		}
	}
	// cerr << "Time = " << (clock() - Time) / 1000;
}
