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

lint a, b, res;
vector<lint> v, v1, v2, v3, v4;

void Merge(vector<lint> &v1, vector<lint> &v2) {
  reverse(all(v2));
  vector<lint> res;

  int i = 0, j = 0;
  while (i < v1.size() || j < v2.size()) {
    if (i == v1.size()) {
      res.push_back(v2[j]);
      ++j;
    } else if (j == v2.size()) {
      res.push_back(v1[i]);
      ++i;
    } else if (v1[i] < v2[j]) {
      res.push_back(v1[i]);
      ++i;
    } else {
      res.push_back(v2[j]);
      ++j;
    }
  }
  v1 = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
  cin >> a >> b;

  lint p = sqrt(b);
  FOR(i, 1, p) {
    v.push_back(i);
    if (i <= a) {
      v1.push_back(a / i);
      v2.push_back(a / i + 1);
    }   
    v3.push_back(b / i);
    v4.push_back(b / i + 1);
  }

  Merge(v, v1);
  Merge(v, v2);
  Merge(v, v3);
  Merge(v, v4);

  // sort(all(v));
  REP(i, v.size() - 1) {
    // cerr << v[i] << '\n';
    res += (b / v[i] - (a + v[i] - 1) / v[i] + 1) * (v[i + 1] - v[i]) * (v[i + 1] + v[i] - 1) / 2;
  }
  res += (b / v.back() - (a + v.back() - 1) / v.back() + 1) * v.back();

  cout << res;
}
