#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, cnt_black, cnt_white, visa_black, visa_white, a[N], visa[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		if (a[i]) cnt_black ++;
		else cnt_white ++;
	}

	for (int i = 0; i < m; ++ i) {
		int u, v;
		cin >> u >> v;
		if (a[u] != a[v]) {
			visa[u] ++;
			visa[v] ++;
		}
	}

	for (int i = 1; i <= n; ++ i) {	
		if (a[i] == 1 && visa[i] > 0) {
			visa_black ++;
		}
		else if (a[i] == 0 && visa[i] > 0) {
			visa_white ++;
		}
	}

	// Solve
	for (int i = 1; i <= n; ++ i) {
		int res;
		if (a[i] == 0) {
			res = 
			 cnt_white - 1
			 + visa[i]
			 + 2 * (visa_black - visa[i])
			 + (3 - (visa[i] > 0)) * (cnt_black - visa_black);
		} else {
			res = 
			 cnt_black - 1
			 + visa[i]
			 + 2 * (visa_white - visa[i])
			 + (3 - (visa[i] > 0)) * (cnt_white - visa_white);
		}
		cout << res << ' ';
	}
}