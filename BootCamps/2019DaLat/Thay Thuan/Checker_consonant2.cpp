#include <bits/stdc++.h>
using namespace std;

const vector<char> vow = {'a', 'e', 'i', 'o', 'u', 'w', 'y'};

bool isUpper(char ch) {
	return 'A' <= ch && ch <= 'Z';
}

bool isVow[30];

bool check(string a, string b) {
	string c = a;

	int n = a.size();
	if (b.size() != n) return 0;

	for (int i = 0; i < n; ++ i) 
		if ('A' <= c[i] && c[i] <= 'Z')
			c[i] = c[i] - 'A' + 'a';

	int x = 0, y = 0;

	for (int i = 1; i < n; ++ i) {
		if (!isVow[c[i-1] - 'a'] || !isVow[c[i] - 'a']) continue;
		x += (isUpper(a[i-1]) ^ isUpper(a[i]));
		y += (isUpper(b[i-1]) ^ isUpper(b[i]));
	}
	return x == y;
}

int main() {
	for (char ch : vow) isVow[ch - 'a'] = 1;
	cerr << check("strength", "StRenGtH");
}