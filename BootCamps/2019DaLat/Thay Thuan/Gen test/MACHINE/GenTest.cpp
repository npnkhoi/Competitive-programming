// Create a folder contain this generator and <task>.exe

#include <bits/stdc++.h>
using namespace std;
#define task "MACHINE"
typedef long long ll;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}

string toString(int num, int rem) {
	if (rem == 0) return "";
	else return toString(num / 10, rem - 1) + (char) (num % 10 + '0');
}

int main() {
	int l = 9, r = 9;
	for (int iTest = l; iTest <= r; ++ iTest) {
		string testname = "Test" + toString(iTest, 2);

		ofstream inp((testname + ".inp").c_str());
		// Create test here

		// Normal cases
		// int n = Rand(1, 1e6);
		// inp << n << "\n";
		// for (int i = 1; i <= n; ++ i) {
		// 	int l = Rand(1, 3e6 - 1);
		// 	int r = Rand(l + 1, 3e6);
		// 	inp << l << " " << r << "\n";
		// }

		// Huge cases
		int n = Rand(9e5, 1e6);
		inp << n << "\n";
		for (int i = 1; i <= n; ++ i) {
			int l = Rand(1, 3e6 - 1);
			int r = Rand(l + 1, 3e6);
			inp << l << " " << r << "\n";
		}

		// -1 case
		// int u = Rand(1, 3e6);
		// int v = Rand(u, 3e6);
		// int n = Rand(1, 1e6);
		// inp << n << "\n";
		// for (int i = 1; i <= n; ++ i) {
		// 	inp << Rand(1, u) << " " << Rand(v, 3e6) << "\n";
		// }

		inp.close();

		system((task".exe < " + testname + ".inp > " + testname + ".out").c_str());

		cerr << "Generated test " << iTest << "\n";
	}
}