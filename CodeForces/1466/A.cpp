#include <bits/stdc++.h>
using namespace std;

int a[55];

int main() {
	int tc;
	cin >> tc;
	while (tc --) {
		set<int> s;
		int n; cin >> n;
		for (int i = 0; i < n; ++ i) {
			cin >> a[i];
			for (int j = 0; j < i; ++ j) {
				s.insert((abs(a[i] - a[j])));
			}
		}
		cout << s.size() << '\n';
	}
}