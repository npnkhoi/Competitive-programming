#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, res, a[N];

int main() {
	// scanf("%d", &n);
	n = 6;
	for (int i = 1; i <= n; ++ i) a[i] = i;
	do {
		int s = 0;
		for (int i = 2; i <= n; ++ i) s += abs(a[i] - a[i-1]);
		if (s >= res) {
			res = s;
			// cerr << res << ": ";
			// for (int i = 1; i <= n; ++ i) cerr << a[i] << " ";
			// cerr << "\n";
		} 
	} while (next_permutation(a + 1, a + n + 1));
	for (int i = 1; i <= n; ++ i) a[i] = i;
	do {
		int s = 0;
		for (int i = 2; i <= n; ++ i) s += abs(a[i] - a[i-1]);
		if (s == res) {
			for (int i = 1; i <= n; ++ i) cerr << a[i] << " ";
			cerr << "\n";
		} 
	} while (next_permutation(a + 1, a + n + 1));
}