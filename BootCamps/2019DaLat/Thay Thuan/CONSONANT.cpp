#include <bits/stdc++.h>
using namespace std;

const vector<char> vow = {'a', 'e', 'i', 'o', 'u', 'w', 'y'};
const int NCON = 19, N = 1e6 + 5;

char s[N];
int n, e[NCON][NCON], isVow[30], id[30];
vector<char> con;

bool bitOn(int mask, int i) {
	return mask & (1 << i);
}

int main() {
	for (char ch : vow) isVow[ch - 'a'] = 1;
	for (int i = 0; i < 26; ++ i) if (!isVow[i]) {
		id[i] = con.size();
		con.push_back(i);
	}
	scanf("%s", s);
	n = strlen(s);
	for (int i = 1; i < n; ++ i) {
		int x = s[i-1] - 'a', y = s[i] - 'a';
		if (isVow[x] || isVow[y]) continue;
		x = id[x], y = id[y];
		e[x][y] ++;
		e[y][x] ++;
	}
	int saveMask = 0, res = 0;
	for (int mask = 0; mask < (1 << NCON); ++ mask) {
		int tmp = 0;
		for (int i = 0; i < NCON; ++ i) {
			for (int j = i + 1; j < NCON; ++ j) {
				if (bitOn(mask, i) ^ bitOn(mask, j)) tmp += e[i][j];
			}
		}
		if (tmp > res) {
			res = tmp;
			saveMask = mask;
		}
	}
	// cerr << s << "\n";
	// cerr << saveMask << "\n";
	for (int i = 0; i < n; ++ i) {
		char ch = s[i];
		// cerr << ch;
		if (isVow[ch - 'a']) printf("%c", ch);
		else printf("%c", (bitOn(saveMask, id[ch - 'a']) ? ch : ch - 'a' + 'A'));
	}
}