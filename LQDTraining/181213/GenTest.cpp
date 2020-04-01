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

string toString(int num, int rem) {
	if (rem == 0) return "";
	else return toString(num / 10, rem - 1) + (char) (num % 10 + '0');
}

int main() {
	int l = 1, r = 9;
	for (int iTest = l; iTest <= r; ++ iTest) {
		testname = "test" + toString(iTest, 2);
        system(("copy tunnel.exe test" + testname + "\\tunnel.exe").c_str());
		system("tunnel" + testname + "\\tunnel.exe");

		cerr << "Generated test " << iTest << "\n";
	}
}
