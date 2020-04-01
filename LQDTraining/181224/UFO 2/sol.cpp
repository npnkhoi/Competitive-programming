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

const int N = 4000;

int n, m, k, res;
vi mark[N][N];
set<int> hub;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen("test.out", "w", stdout);
  cin >> n >> m >> k;
  FOR(i, 1, k) {
    int x, y, r;
    cin >> x >> y >> r;
    FOR(u, x - r, x + r) {
      int tmp = (int)floor(sqrt((double)r*r - (u - x) * (u - x)));
      mark[u][y - tmp].push_back(i);
      mark[u][y + tmp + 1].push_back(-i);
    }
  }
  FOR(i, 1, n) {
    hub.clear();
    FOR(j, 1, m) {
      REP(t, mark[i][j].size()) {
        int tmp = mark[i][j][t];
        if (tmp < 0) hub.erase(- tmp);
        else hub.insert(tmp);
      }
      //cout << (hub.empty() ? 0 : *hub.rbegin()) << ' ';
      res += k - (hub.empty() ? 0 : *hub.rbegin());
    }
    //cout << '\n';
  }
  cout << res;
}
