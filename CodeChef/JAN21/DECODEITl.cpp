#include <bits/stdc++.h>
using namespace std;

int tc, n;
string s;

int main() {
	cin >> tc;
	while (tc --) {
		cin >> n >> s;
		for (int i = 0; i < n; i += 4) {
			int id = 0;
			for (int j = 0; j < 4; ++ j) {
				id += (s[i + 3 - j] - '0') << j;
			}
			cout << char(id + 'a');
		}
		cout << '\n';
	}
}