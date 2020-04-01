#include <bits/stdc++.h>
using namespace std;

string line, s;
int n, l, r;
vector<int> f;

int main() {
	getline(cin, line);
	n = line.size();
	// cerr << "ok\n";
	s.assign(2 * n - 1, ' ');
	// cerr << "ok\n";
	for (int i = 0; i < n; ++i) s[2 * i] = line[i];
	// cerr << "ok\n";
	n = 2 * n - 1;
	f.resize(n);

	// cerr << "ok\n";

	l = 0, r = -1;
	long long res = 0;
	for (int i = 0; i < n; ++ i) {
		int j = (i <= r ? min(r - i, f[l + r - i]) + 1 : 1);
		while (0 <= i - j && i + j < n && s[i - j] == s[i + j]) ++ j;
		// f[i] = j - i % 2;
		res += (j - i % 2 + 1) / 2;
		// res += f[i] + 1 - i % 2; 
		// cerr << j << " " << f[i] << " " << f[i] + 1 - i % 2 << "\n";
	}
	printf("%lld", res);
}