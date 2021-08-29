#include  <bits/stdc++.h>
using namespace std;

const string s = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

char dir, ch;

char nxt(char ch, int sh) {
	for (int i = 0; i < s.size(); ++ i) {
		if (s[i] == ch) return s[i + sh];
	}
}

int main() {
	// freopen("test.inp", "r", stdin);
	cin >> dir;
	cin.ignore();
	while (cin >> ch) {
		// cerr << " -> " << ch << "\n";
		// cerr << "\n" << ch << " - >";
		if (dir == 'R') printf("%c", nxt(ch, -1));
		else printf("%c", nxt(ch, +1));
	}
}