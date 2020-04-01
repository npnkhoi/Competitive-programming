#include <bits/stdc++.h>
using namespace std;

int q, n, p, k;
string s;

int main() {
	scanf("%d ", &q);
	while (q --) {
		getline(cin, s);
		s = '0' + s;
		n = s.size();
		p = 1;
		while (p + 1 < n && s[p - 1] != s[p]) ++ p;

		while (1) {
			if (p == 0) {
				s[p] = '1';	
				break;
			}
			if (s[p] < '8') {
				if (s[p] + 1 != s[p - 1]) s[p] += 1;
				else s[p] += 2;
				break;
			}
			if (s[p] == '8' && s[p] + 1 != s[p - 1]) {
				s[p] += 1;
				break;
			}
			-- p;
		}

		k = 0;
		for (int i = p + 1; i < n; ++ i) s[i] = '0' + k, k ^= 1;
		for (int i = 0 + (s[0] == '0'); i < n; ++ i) printf("%c", s[i]);
		printf("\n");
	}
}