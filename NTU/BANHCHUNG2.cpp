#include <bits/stdc++.h>
using namespace std;

const int V = 5e4 + 5;
int f[V];
int n, v, v1;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> v >> n;
	f[0] = 1;
	for (int i = 0; i < n; ++ i) {
		int v1;
		cin >> v1;
		for (int i = v; i >= v1; i--) {
			if (f[i - v1] == 1) f[i] = 1;
		}
	}	
	for (int i = v; i >= 0; --i) if (f[i]) {
		cout << i;
		break;
	}
}
