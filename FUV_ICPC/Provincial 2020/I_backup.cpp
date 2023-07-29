#include <bits/stdc++.h>
using namespace std;

const int LEN_P = 102;
const int LEN_S = 2e5 + 2;

string p_origin, p, s;
int f[LEN_P][LEN_S];

void preprocess_pattern() {
	string new_p = "";
	for (auto c : p) {
		if (c == '*') {
			if (new_p == "") continue;
			if (new_p.back() == '*') continue;
		} 
		new_p += c;
	}
	while (new_p.back() == '*') new_p.pop_back();
	if (new_p == "") {
		cout << s.size();
		exit(0);
	}
	p = new_p;
}

int main() {
	cin >> p_origin >> s;
	preprocess_pattern();
	s += s;
	// cerr << p << ' ' << s << '\n';
	int p_len = p.size(), s_len = s.size();

	for (int j = 0; j < s_len; ++ j) {
		f[0][j] = -1;
	}

	for (int j = 1; j <= s_len; ++ j) {
		if (p[i - 1] == '*') {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		} else {
			if ()
		}

		if (s[j] == p[0])
			f[0][j] = j;
		else if (j > 0)
			f[0][j] = f[0][j-1];
		else
			f[0][j] = -1;
		// f[0][j] = (s[j] == p[0] ? j : -1);
	}

	for (int i = 1; i < p_len; ++ i) {
		for (int j = 0; j < s_len; ++ j) {
			// cerr << "calculating " << i << ' ' << j << '\n';
			if (j < i) {
				f[i][j] = -1;
				continue;
			}

			f[i][j] = f[i][j - 1];
			// cerr << "initial: " << f[i][j] << '\n';
			if (p[i] == s[j])
				f[i][j] = max(f[i][j], f[i-1][j-1]);
		}
	}
	int ori_s = s_len / 2, result = 0;
	for (int j = ori_s - 1; j < s_len - 1; ++ j) {
		// cerr << j << ' ' << f[p_len-1][j] << '\n';
		if (f[p_len - 1][j] > j - ori_s) {
			result ++;
		}
	}
	cout << result;
}