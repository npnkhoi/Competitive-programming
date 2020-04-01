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

#define task "sol"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5, MAX_VAL = 1e7,
  MED_VAL = 1e6, MID = sqrt(1e7);

int n, a[N], lab[N];
vector<ii> edge[MED_VAL];
set<int> mul;
set<int> :: iterator it;

int root(int u) {
  if (lab[u] < 0) return u;
  return lab[u] = root(lab[u]);
}

void merge(int u, int v) {
  u = root(u); v = root(v);
  if (lab[u] > lab[v]) swap(u, v);
  lab[u] -= (lab[u] == lab[v]);
  lab[v] = u;
}

void sub1() {
  memset(lab, -1, sizeof lab);
  FOR(i, 1, n - 1) {
    FOR(j, i + 1, n) {
      edge[a[j] % a[i]].push_back(mp(i, j));
    }
  }
  long long res = 0;
  REP(c, a[n]) {
    REP(i, edge[c].size()) {
      int u = edge[c][i].fi, v = edge[c][i].se;
      //cerr << u << " " << v << " " << c << "\n";
      if (root(u) != root(v)) {
        merge(u, v);
        res += c;
        //cerr << u << " " << v << " " << c << "\n";
      }
      //cerr << "done\n";
    }
  }
  cout << res;
}

void marking(int x) {
  for (int v = x; v <= MAX_VAL; v += x) {
    mul.insert(v);
  }
}

void sub2() {
  marking(a[1]);
  long long res = 0;
  FOR(i, 2, n) {
    it = mul.upper_bound(a[i]);
    -- it;
    res += a[i] - *it;
    marking(a[i]);
  }
  cout << res;
}

void sub3() {
  long long res = 0;
  if (a[1] >= MID) marking(a[1]);
  FOR(i, 2, n) {
    int minEdge = a[i];
    if (a[i] < MID) {
      FOR(j, 1, i - 1) minEdge = min(minEdge, a[i] % a[j]);
    } else {
      FOR(j, 1, i - 1) {
        if (a[j] >= MID) break;
        minEdge = min(minEdge, a[i] % a[j]);
      }
      it = mul.upper_bound(a[i]); -- it;
      minEdge = min(minEdge, *it);
      marking(a[i]);
    }
    cerr << minEdge << '\n';
    res += minEdge;
    //cerr << res << "\n";
  }
  cout << res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  sub3(); return 0;
  if (n <= 1000) sub1();
  else sub2();
	return 0;
}
