#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26];

int main() {
	cin >> s;
	int n = s.size();
	int last_char = 'a' - 1;
	int last_pos = n - 1;
	long long res = 0;

	for (int i = n - 1; i >= 1; -- i) {
		if (s[i] == s[i-1]) {
			if (s[i] == last_char) {
				res += last_pos - i;	
			} else {
				res += n - 1 - i;
			}
			last_pos = i - 2;
			last_char = s[i];

			res -= cnt[s[i] - 'a'];
			for (int c = 0; c < 26; ++ c) {
				cnt[c] = 0;
			}

			i --;
		} else {
			cnt[s[i] - 'a'] ++;
		}
	}
	cout << res;
}