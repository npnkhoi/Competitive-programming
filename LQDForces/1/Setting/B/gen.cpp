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
	// int n = Rand(5e4, 1e5);
	// int n = 1e5;
	// int n = Rand(1e6, 2e6);
	int n = 2e6;
	inp << n << "\n";
	while (n --) {
		// inp << Rand(5e8, 1e9) << " ";
		inp << (int)1e9 << " ";
	}
	inp.close();
}

string toString(int num, int rem) {
	if (rem == 0) return "";
	else return toString(num / 10, rem - 1) + (char) (num % 10 + '0');
}

int main() {
	int l = 50, r = 50;
	for (int iTest = l; iTest <= r; ++ iTest) {
		testname = "test" + toString(iTest, 2);

		test();
		// system((task".exe < " + testname + ".inp > " + testname + ".out").c_str());

		cerr << "Generated test " << iTest << "\n";
	}
}