// Create a folder contain this generator and <task>.exe

#include <bits/stdc++.h>
using namespace std;
#define task "ADDS"
typedef long long ll;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}

int main() {
	int l = 1, r = 10;
	for (int iTest = l; iTest <= r; ++ iTest) {
		string testname = "Test" + to_string(iTest);

		ofstream inp((testname + ".inp").c_str());
		// Create test here
		int a = Rand(1, 1e9);
		int b = Rand(a, 1e9);
		int m = Rand(1, 1e9);
		inp << a << " " << b << " " << m << "\n";
		inp.close();

		system((task".exe < " + testname + ".inp > " + testname + ".out").c_str());
	}
}