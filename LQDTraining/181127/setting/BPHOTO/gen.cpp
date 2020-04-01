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

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}
const int N = 3e5 + 5;
const int Q = 1e4 + 5;
string testname;

int a[N], b[5];
ii que[Q];

// void test() {
//   ofstream inp("BPHOTO.inp");
//   int n = 3e5, c = 1e4;
//   int q = 1e4;
//   b[1] = Rand(1, c);
//   b[2] = Rand(1, c);
//   b[3] = Rand(1, c);

//   inp << n << " " << c << "\n";
//   FOR(i, 1, n) inp << b[Rand(1, 2)] << " "; inp << "\n";
//   inp << q << "\n";
//   FOR(i, 1, q) {
//   	int l = Rand(1, n);
//   	inp << l << " " << Rand(l, n) << "\n";
//   }
//   inp.close();
// }

void test() {
  ofstream inp("BPHOTO.inp");
  int n = 3e5, c = 1e4;
  int q = 1e4;
  b[1] = Rand(1, c);
  b[2] = Rand(1, c);
  b[3] = Rand(1, c);
  FOR(i, 1, n) {
  	// a[i] = b[Rand(1, 2)];
    a[i] = Rand(1, c);
  }
  // FOR(i, 1, sqrt(n)) a[Rand(1, n)] = Rand(1, c);

  inp << n << " " << c << "\n";
  FOR(i, 1, n) inp << a[i] << " "; inp << "\n";
  inp << q << "\n";
  FOR(i, 1, q) {
  	int l = Rand(1, n);
  	inp << l << " " << Rand(l, n) << "\n";
  }
  inp.close();
}

string toString(int num, int rem) {
	if (rem == 0) return "";
	else return toString(num / 10, rem - 1) + (char) (num % 10 + '0');
}

int main() {
	srand(time(NULL));
	int l = 31, r = 40;
	for (int iTest = l; iTest <= r; ++ iTest) {
		testname = "Test" + toString(iTest, 2);

		test();
		
		system("bphoto.exe");
		string testname = "BPHOTO" + to_string(iTest);
		system(("mkdir " + testname).c_str());
		system(("move BPHOTO.inp " + testname + "\\BPHOTO.inp").c_str());
		system(("move BPHOTO.out " + testname + "\\BPHOTO.out").c_str());

		// system((task".exe < " + testname + ".inp > " + testname + ".out").c_str());

		cerr << "Generated test " << iTest << "\n";
	}
}