#include <bits/stdc++.h>
using namespace std;

const vector<char> vow = {'a', 'e', 'i', 'o', 'u', 'w', 'y'};

bool isUpper(char ch) {
	return 'A' <= ch && ch <= 'Z';
}

bool isVow[30];
int stt[30];

char toLower(char ch) {
	if (isUpper(ch)) return ch + 'a' - 'A';
	else return ch;
}

bool check(string a, string b) {
	if (a.size() != b.size()) return false;

	int n = a.size();
	for (int i = 0; i < n; ++ i) 
		if (!isalpha(a[i]) || toLower(a[i]) != toLower(b[i])) return false;

	memset(stt, -1, sizeof stt);
	for (int i = 0; i < n; ++ i) {
		int tmp = toLower(a[i]) - 'a';
		if (stt[tmp] == -1) stt[tmp] = isUpper(a[i]);
		else if (stt[tmp] != isUpper(a[i])) {
			return 0;
		}
	}

	int x = 0, y = 0;

	for (int i = 1; i < n; ++ i) {
		if (isVow[toLower(a[i - 1]) - 'a'] || isVow[toLower(a[i]) - 'a']) continue;
		x += (isUpper(a[i-1]) ^ isUpper(a[i]));
		y += (isUpper(b[i-1]) ^ isUpper(b[i]));
	}
	return x == y;
}

int main() {
	for (char ch : vow) isVow[ch - 'a'] = 1;
	cerr << check("strength", "StRenGtH");
}