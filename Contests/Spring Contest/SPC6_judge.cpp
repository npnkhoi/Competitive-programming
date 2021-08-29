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

#define task "SPC6"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

ll Rand(ll l, ll r) {
	ll res = l + (
	(ll) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +  
	(ll) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +  
	(ll) rand() * (RAND_MAX + 1) +  
	(ll) rand()) % (r - l + 1);
	if (res < 0) res += r - l + 1;
	return res;
}

const int N = 55;
string str;
int n;
ll m, f[N];
char a[N][N];

void test() {
	ofstream inp(task".inp");
	inp << "1\n";
	n = Rand(2, 50);
	debug(n);
	m =  Rand(1, (1LL << n -2));
	inp << n << " " << m;
	inp.close();
}

void check() {
	ifstream out(task".out");
	out >> str;
	if (str[0] == 'I') {
		cerr << "IMPOSSIBLE???";
		cerr << n << m << '\n';
		return;
	}
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			out >> a[i][j];
		}
	}
	f[1] = 1;
	FOR(i, 2, n) {
		f[i] = 0;
		FOR(j, 1, i - 1) if (a[j][i] == '1') f[i] += f[j];
	}
	if (f[n] == m) cerr << "CORRECT\n";
	else {
		cerr << "WRONG: " << m << ' ' << f[n] << '\n';
		exit(0);
	}
	out.close();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int nTest = 100;
	FOR(iTest, 1, nTest) {
		cerr << "Test " << iTest << '\n';
		test();
		cerr << "done test\n";
		system(task".exe");
		check();
	}
}
