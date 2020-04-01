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

#define task ""

typedef long long lint;
typedef unsigned long long ul;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 5e4 + 5;

int n;
ii a[N];
lint f[N];
vector<ii> b;
vector<ll> lines;

bool redun(ll a, ll b, ll c) {
	return (lint)(a.Y - b.Y) * (a.X - c.X) <= (lint)(a.Y - c.Y) * (a.X - b.X);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
  cin >> n;
  FOR(i, 1, n) {
  	cin >> a[i].X >> a[i].Y;
  }
  sort(a + 1, a + n + 1);
  FOR(i, 1, n) {
  	while (!b.empty() && b.back().X <= a[i].X && b.back().Y <= a[i].Y)
  		b.pop_back();
  	b.push_back(a[i]);
  }
  // for (ii x : b) cerr << x.X << ' ' << x.Y << '\n';
  // x: inc, y: dec

  int j = 0;
  REP(i, b.size()) {
  	// add line y = b[i].Y + f[i - 1]
  	#define sz lines.size()
  	ll newLine = mp(b[i].Y, f[i]);
  	while (lines.size() >= 2 && redun(lines[sz - 2], lines[sz - 1], newLine))
  		lines.pop_back();
  	lines.push_back(newLine);

  	// find optimal j
  	if (j >= sz) j = sz;
  	while (j < sz - 1 && 
  		(lint)b[i].X * lines[j].X + lines[j].Y >= (lint)b[i].X * lines[j + 1].X + lines[j + 1].Y)
  		++j;
  	f[i + 1] = (lint)b[i].X * lines[j].X + lines[j].Y;
  }
  cout << f[b.size()];
}

