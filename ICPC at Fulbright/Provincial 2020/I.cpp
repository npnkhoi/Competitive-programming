#include <bits/stdc++.h>
using namespace std;

const int LEN_P = 102;
const int LEN_S = 2e5 + 2;
const int INF = 1e9 + 7;

string p_origin, p, s;
int f[LEN_P][LEN_S], cnt[LEN_S];

void preprocess_pattern() {
	p = "";
	for (int i = 0; i < p_origin.size(); ++ i) {
		char c = p_origin[i];
		// cerr << "char " << c << '\n';
		if (c == '*') {
			if (p == "") continue;
			if (p.back() == '*') continue;
		} 
		p += c;
	}
	while (p.size() > 0 && p.back() == '*') p.pop_back();
	if (p == "") {
		cout << s.size();
		exit(0);
	}
}

int main() {
	getline(cin, p_origin);
	getline(cin, s);
	preprocess_pattern();
	// cerr << "done pre\n";
	s += s;
	// cerr << p << ' ' << s << '\n';
	int p_len = p.size(), s_len = s.size();

	for (int j = 0; j < s_len; ++ j) {
		f[0][j] = -1;
	}

	for (int i = 1; i <= p_len; ++ i) {
		for (int j = 0; j < s_len; ++ j) {
			if (j < i - 1) {
				f[i][j] = -INF;
			} else if (p[i - 1] == '*') {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			} else {
				if (s[j] == p[i - 1]) {
					if (i == 1) {
						f[i][j] = j;
					} else {
						f[i][j] = f[i - 1][j - 1];
					}
				} else {
					f[i][j] = -INF;
				}
			}

		}
	}

	int ori_s = s_len / 2, result = 0;
	for (int j = p_len - 1; j < s_len - 1; ++ j) {
		// cerr << j << ' ' << f[p_len][j] << '\n';
		if (f[p_len][j] >= 0) {
			cnt[j] ++;
			cnt[min(f[p_len][j] + ori_s, s_len)] --;
		}
	}
	// for (int i = 0; i < s_len; ++ i) {
	// 	cerr << cnt[i] << ' ' << f[p_len][i] << " || ";
	// }
	for (int j = p_len - 1; j < s_len - 1; ++ j) {
		cnt[j] += cnt[j - 1];
		if (j >= ori_s - 1 && cnt[j] > 0) {
			result ++;
		}
	}
	cout << result;
}