#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], b[N], c[N];
long long f[N][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	f[0][0] = a[0];
	f[0][1] = b[0];
	f[0][2] = c[0];
	for (int i = 1; i < n; ++ i) {
		f[i][0] = a[i] + max(f[i-1][1], f[i-1][2]);
		f[i][1] = b[i] + max(f[i-1][0], f[i-1][2]);
		f[i][2] = c[i] + max(f[i-1][0], f[i-1][1]);
	}
	cout << max(f[n-1][0], max(f[n-1][1], f[n-1][2]));
}