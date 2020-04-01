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

int n, m, l, r;
long long res;
vector<ii> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
  cin >> n >> m;
  FOR(i, 1, n) {
    cin >> l >> r;
    if (l <= r) continue;
    v.push_back(mp(r, 0));
    v.push_back(mp(l, 1));
  }
  sort(all(v));
  res = m;
  int cnt = 0, start;
  REP(i, v.size()) {
    if (v[i].se == 0) {
      if (cnt == 0) start = v[i].first;
      cnt ++;
    } else {
      if (cnt == 1) res += 2 * (v[i].first - start);
      cnt --;
    }
  }
  cout << res;
	return 0;
}
