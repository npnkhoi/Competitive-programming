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

#define task "XORARRAY"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int LOG = 20, N = 1e5 + 5, md = 1e9 + 7;

int n, q, cnt;
int Pow[N], ans[N];
vi query[N];
bitset<2*N> f[LOG];
bool done[LOG];

bool getBit(int x, int i) {
	return x >> i & 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> n >> q;
	int pos, x;
	FOR(i, 1, n) {
		cin >> x;
		REP(j, LOG) if (getBit(x, j)) f[j].set(i);
	}	
	FOR(i, 1, q) {
		cin >> pos >> x;
		query[pos].push_back(i);
		REP(j, LOG) if (getBit(x, j)) f[j].set(i + n);
	}
	Pow[0] = 1;
	FOR(k, 1, n) {
		Pow[k] = Pow[k - 1] * 2 % md;
		// update Gauss
		REP(i, LOG) if (f[i].test(k) && !done[i]) {
			REP(j, LOG)
				if (j != i && f[j].test(k)) f[j] ^= f[i];
			done[i] = 1;
			cnt ++;
			break;
		}
		// answer query
		REP(i, query[k].size()) {
			int x = query[k][i];
			bool flag = 1;
			REP(j, LOG) if (!done[j] && f[j].test(n + x)) {
				flag = 0;
				break;
			}
			if (flag == 1) ans[x] = Pow[k - cnt];
		}
	}
	FOR(i, 1, q) cout << ans[i] << '\n'; 
}
