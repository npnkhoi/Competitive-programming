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

const int N = 1e5 + 5 ;

int tc, n, q;
char s[N];
ordered_set data[26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> tc;
	FOR(iTest, 1, tc) {
		cin >> n >> q;
		cin >> s + 1;
		REP(c, 26) data[c].clear();
		FOR(i, 1, n) {
			data[s[i] - 'A'].insert(i);
		}
		int res = 0;
		REP(i, q) {
			int cnt = 0;
			int l, r;
			cin >> l >> r;
			REP(c, 26) {
				cnt += (data[c].order_of_key(r + 1) - data[c].order_of_key(l)) % 2;
			}
			if (cnt <= 1) res ++;
		}
		cout << "Case #" << iTest << ": " << res << '\n';
	}
}
