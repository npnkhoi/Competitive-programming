#include <bits/stdc++.h>
using namespace std;

int tc, n, k;
int a[100005];

int main() {
	cin >> tc;
	for (int iTest = 1; iTest <= tc; ++ iTest) {
		cin >> n >> k;
		
		int pre = 1, res = 0;
		multiset<int> s;

		for (int i = 1; i <= n; ++ i) {
			cin >> a[i];
			s.insert(a[i]);
			while (*s.rbegin() - *s.begin() > k) {
				s.erase(s.find(a[pre]));
				pre ++;
			}
			res = max(res, i - pre + 1);
		}
		cout << "Case #" << iTest << ": " << res << " day";
		if (res > 1) cout << "s\n";
		else cout << "\n"; 
	}
}