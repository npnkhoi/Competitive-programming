#include <bits/stdc++.h>
using namespace std;

long long lso(long long x) {
	return x & (-x);
}

bool include(long long u, long long v) {
	return (u & v) == v;
}

int main() {
	long long q, u, v;
	cin >> q;
	while (q--) {
		cin >> u >> v;
		long long acc_u = u;
		while (u < v) {
			if (include(acc_u, lso(u ^ v))) {
				u += lso(u ^ v);
				acc_u |= u;
			} else {
				break;
			}
		}
		cout << (u == v ? "YES" : "NO") << '\n';
	}
}