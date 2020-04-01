// Create a folder contain this generator and <task>.exe

#include <bits/stdc++.h>
using namespace std;
#define task ""
typedef long long lint;

lint Rand(lint l, lint r) {
	lint res = l + (
	1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
	1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
	1LL * rand() * (RAND_MAX + 1) +
	1LL * rand()) % (r - l + 1);
	if (res < 0) res += r - l + 1;
	return res;
}

int main() {
	int l = 1, r = 10;
	for (int iTest = l; iTest <= r; ++ iTest) {
		string testname = "Test" + to_string(iTest);

		ofstream inp((testname + ".inp").c_str());
		// Create test here

		inp.close();

		system((task".exe < " + testname + ".inp > " + testname + ".out").c_str());
	}
}
