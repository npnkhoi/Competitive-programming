// Create a folder contain this generator and <task>.exe

#include <bits/stdc++.h>
using namespace std;
#define task ""
typedef long long ll;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}


string testname;

void test() {
	ofstream inp((testname + ".inp").c_str());
	int n = Rand(1, 1000);
	inp << n << "\n";
	int x, y;
	for (int i = 1; i <= n; ++ i) {
		x = Rand(-1e8, 1e8), y = Rand(-1e8, 1e8);
		inp << x << " " << y << ' ' << Rand(0, 1e8) << ' ';
		inp << Rand(0, 1e8) << "\n";
	}
	inp << "1\n" << x << " " << y << "\n";
	inp.close();
}

void testmax() {
	ofstream inp((testname + ".inp").c_str());
	int n = 1000;
	inp << n << "\n";
	int x, y;
	for (int i = 1; i <= n; ++ i) {
		x = Rand(-1e8, 1e8), y = Rand(-1e8, 1e8);
		inp << x << " " << y << ' ' << Rand(0, 1e8) << ' ';
		inp << Rand(0, 1e8) << "\n";
	}
	int m = 1000;
	inp << m << "\n";
	for (int i = 1; i <= m; ++ i) {
		inp << Rand(-1e8, 1e8) << " " << Rand(-1e8, 1e8) << "\n";
	}
	inp.close();
}

string toString(int num, int rem) {
	if (rem == 0) return "";
	else return toString(num / 10, rem - 1) + (char) (num % 10 + '0');
}

int main() {
	int l = 16, r = 25;
	for (int iTest = l; iTest <= r; ++ iTest) {
		testname = "NK" + toString(iTest, 2);

		// test();
		testmax();
		// system((task".exe < " + testname + ".inp > " + testname + ".out").c_str());

		cerr << "Generated test " << iTest << "\n";
	}
}