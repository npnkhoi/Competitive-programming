#include <bits/stdc++.h>
using namespace std;

int tc, n;
int a[52];

int main() {
	cin >> tc;
	while (tc --) {
		cin >> n;
		int s = 0;
		for (int i = 0; i < n; ++ i) {
			cin >> a[i];
			s += a[i];
		}
		if (s == 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			sort(a, a + n);
			if (s > 0) {
				reverse(a, a + n);
			}
			for (int i = 0; i < n; ++ i) {
				cout << a[i] << ' ';
			}
			cout << '\n';
		}
	} 
}