// Create a folder contain this generator and <task>.exe

#include <bits/stdc++.h>
using namespace std;
#define task "GENETECH"
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
	int l = 1, r = 25;
	for (int iTest = l; iTest <= r; ++ iTest) {
		string testname = toString(iTest, 2);

		// ofstream inp((testname + ".inp").c_str());
		// Create test here

		// inp.close();

		double Time = clock();
		system((task".exe < " + testname + ".in > " + testname + ".out").c_str());
		cerr << "Time = " << (clock() - Time) / 1000 << "\n";

		// cerr << "Generated test " << iTest << "\n";
		system(("fc " + testname + ".out " + testname + ".ok").c_str());
	}
}