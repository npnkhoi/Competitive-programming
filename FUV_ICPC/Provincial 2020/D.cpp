#include <bits/stdc++.h>
using namespace std;

int sum_digit(string &s) {
	int res = 0, len = s.size();
	for (int i = 0; i < len; ++ i) {
		res += s[i] - '0';
	}
	return res;
}

void next_num(string &s) {
	int len = s.size();
	int pos = len - 1;
	while (pos >= 0 && s[pos] == '9')
		pos --;
	// cerr << "pos: " << pos << '\n';
	if (pos == -1) {
		s = "1";
		// cerr << s << '\n';
		for (int i = 0; i < len; ++ i) {
			s += "0";
			// cerr << s << '\n';
		}
		// cerr << "done next num\n";
	} else {
		s[pos] ++;
		for (int i = pos + 1; i < len; ++ i) {
			s[i] = '0';
		}
	}
}
string a, b, cur;
int prod;

int main() {
	// string foo = "99";
	// next_num(foo);
	// cerr << foo << '\n';

	cin >> a >> b;
	cur = a;
	prod = 1;
	for (int i = 0; i < 6; ++ i) {
		prod = prod * sum_digit(cur) % 9;
		// cerr << cur << ' ' << prod << '\n';
		if (cur == b) break;
		next_num(cur);
	}
	cout << (prod == 0 ? 9 : prod);
}