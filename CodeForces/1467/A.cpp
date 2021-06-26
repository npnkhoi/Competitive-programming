#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc, n;
	cin >> tc;
	while (tc --) {
		cin >> n;
		if (n == 1) {
			cout << "9\n";
		} else {
			cout << "98";
			n -= 2;
			int x = 9;
			for (int i = 0; i < n; ++ i) {
				cout << x;
				x ++;
				if  (x > 9) x = 0;
			}
			cout << '\n';
		} 
	}
}