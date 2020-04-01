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

const int N = 1e5 + 5;

int n, a[N], b[N], id[N], id2[N];
ll res, res2;

void solve(ll &res, int id[]) {
  FOR(i, 1, n) id[i] = i;
  sort(id + 1, id + n + 1, [](int u, int v) {
        return a[u] + max(b[u], a[v]) + b[v] < a[v] + max(b[v], a[u]) + b[u];
  });
  res = 0;
  ll sumA = 0;
  FOR(i, 1, n) {
    sumA += a[id[i]];
    res = max(res, sumA) + b[id[i]];
  }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  solve(res, id);
  cout << res << '\n';
  FOR(i, 1, n) cout << id[i] << ' ';

}
