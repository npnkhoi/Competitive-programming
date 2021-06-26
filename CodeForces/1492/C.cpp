#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, s_index, t_index, l[N], r[N];
string s, t;

int main() {
	cin >> n >> m >> s >> t;
	
	s_index = t_index = 0;
	for (int i = 0; i < m; ++ i) {
		while (s[s_index] != t[t_index]) {
			s_index ++;
		}
		l[t_index] = s_index;
		t_index ++;
		s_index ++;
	}

	s_index = n - 1;
	t_index = m - 1;
	for (int i = 0; i < m; ++ i) {
		while (s[s_index] != t[t_index]) {
			s_index --;
		}
		r[t_index] = s_index;
		t_index --;
		s_index --;
	}

	int res = 0;
	for (int i = 1; i < m; ++ i) {
		res = max(res, r[i] - l[i - 1]);
	}

	// for (int i = 0; i < m; ++ i) {
	// 	printf("at %d: %d, %d\n", i, l[i], r[i]);
	// }
	cout << res << '\n';
}