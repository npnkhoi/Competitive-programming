// Create a folder contain this generator and <task>.exe

#include <bits/stdc++.h>
using namespace std;
#define task "BOTTLES"
typedef long long ll;

string testname;

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

void test1() {
	ofstream inp((testname + ".inp").c_str());
	// Create test here
	// int n = Rand(1, 1e6);
	int n = Rand(1, 100);
	int k = 3;
	inp << n << " " << k << "\n";
	while (n -- ) inp << Rand(1, 1e6) << " ";
	inp.close();
}

void test2() {
	ofstream inp((testname + ".inp").c_str());
	// Create test here
	// int n = Rand(1, 1e6);
	int n = Rand(1e3, 1e4);
	int k = Rand(2, 1e6 / n); //Rand(1, n);
	inp << n << " " << k << "\n";
	while (n -- ) inp << Rand(1, 1e6) << " ";
	inp.close();
}

void test3() {
	ofstream inp((testname + ".inp").c_str());
	// Create test here
	// int n = Rand(1, 1e6);
	int n = 1e6;
	int k = Rand(2, 1e6); //Rand(1, n);
	inp << n << " " << k << "\n";
	while (n -- ) inp << Rand(1, 1e6) << " ";
	inp.close();
}

int main() {
	int l = 1, r = 50;
	for (int iTest = l; iTest <= r; ++ iTest) {
		testname = "Test" + toString(iTest, 2);

		// test1();
		// test2();
		// test3();
		// test1_mini();

		double t = clock();
		system((task".exe < " + testname + ".inp > " + testname + ".out").c_str());
		cerr << "Exec time: " << (clock() - t) / 1000 << "\n";
		cerr << "Generated test " << iTest << "\n";
	}
}