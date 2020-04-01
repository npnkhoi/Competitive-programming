#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char ch;
string s, t;
int n;
double res;

double calc(string &s) {
	// cerr << "calc\n";
	n = s.size();
	int x = 0, y = 0, doub = 0, unsurePos = - 10;
	for (int i = 0; i < n; ++i) {
		if (s[i] != 'X') {
			if ((y + 1) % 2 == (s[i] == 'L')) {
				x ++;
				y ++;
			} else {
				// x ++;
				// y += 2;
				if (i >= 2 && unsurePos != -10 && s[i - 1] == 'X') {
					doub ++;
					x --;
					y -= 2;
					unsurePos = - 10;
				}
				unsurePos = i;
			}
		} else {
			y ++;
		}
		if (unsurePos != - 10) unsurePos = -10;
	}
	if (y % 2) {
		y ++;
	}
	if (2 * y > x) {
		x += doub;
		y += 2 * doub;
	}
	return (double) 100 * x / y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("MARCH.inp", "r", stdin);
	freopen("MARCH.out", "w", stdout);

	cin >> s;
	if (s[0] != 'X' && s[0] == s[s.size() - 1]) {
		t = 'X' + s;
		s.push_back('X');
		res = max(calc(t), calc(s));
	} else {
		res = calc(s);
	}
	cout << fixed << setprecision(7) << res;
}