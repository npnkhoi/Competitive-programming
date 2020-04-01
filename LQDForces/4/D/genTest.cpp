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

lint Rand(lint l, lint r) {
    lint res = l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
    if (res < l) res += r - l + 1;
    return res;
}

set<int> data;

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	FOR(iTest, 6, 6) {
		ofstream inp((to_string(iTest) + ".inp").c_str());

		int tc = 10;
		inp << tc << '\n';
		while (tc --) {
			int n = 1e5, m = Rand(1e4, 1e5);
			inp << n << ' ' << m << '\n';
			data.clear();
			FOR(i, 1, n) {
				int x;
				do {
					x = Rand(-1e9, 1e9);
				} while (data.find(x) != data.end());
				inp << x << ' ';
				data.insert(x);
			}
			inp << '\n';
		}

		inp.close();
	}
}
