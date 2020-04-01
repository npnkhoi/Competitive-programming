#include <bits/stdc++.h>
using namespace std;
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
		int n = Rand(1, 1e5);
		int s = Rand(-1e9, 1e9);
		inp << n << " " << s << "\n";
		for (int i = 1; i <= n; ++ i) inp << Rand(-1e9, 1e9) << " ";
		inp.close();

		system(("COUNTS.exe < " + testname + ".inp > " + testname + ".out").c_str());
	}
}