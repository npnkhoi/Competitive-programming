#include <bits/stdc++.h>
using namespace std;

long long lso(long long x) {
	return x & (-x);
}

bool include(long long u, long long v) {
	return (u & v) == v;
}

bool reachable(long long u, long long v) {
	if (v >= 2*u) {
		return reachable(2*u, v);
	} else {
		v = v - u;
		return (u & v) == v;
	}
}

int main() {
	long long q, u, v;
	cin >> q;
	while (q--) {
		cin >> u >> v;
		cout << (reachable(u, v) ? "YES" : "NO") << "\n";
	}
}