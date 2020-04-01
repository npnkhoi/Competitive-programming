#include <bits/stdc++.h>
using namespace std;

int n, l, r, low;
string s;

int main() {
	cin >> n >> s;
	int tmp = 0;
	l = r = -1;
	for (int i = 0; i < n; ++ i) {
		if (s[i] == '(') tmp ++;
		else tmp --;
		if (tmp < 0) {
			r = i;
			if (l == -1) l = i;
			low = min(low, tmp);
		}
	}
	if (tmp != 0 || low < -1) {
		cout << "No";
		return 0;
	}
	if (l == - 1) {
		cout << "Yes";
		return 0;
	}
	for (int i = r + 1; i < n; ++ i) {
		if (s[i] == '(') {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}