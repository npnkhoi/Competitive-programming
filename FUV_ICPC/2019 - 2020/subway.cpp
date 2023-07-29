#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int tc;

void magic(string &s, int l, int r) {
	// cerr << l << ' ' << r << '\n'; 
	if (r - l == 1) return;

	vector<string> son;
	int pre = l, cnt = 0;

	for (int i = l; i <= r; ++ i) {
		if (s[i] == '0') {
			cnt ++;
		} else {
			cnt --;
			if (cnt == 0) {
				if (i == r && pre == l) {
					magic(s, l + 1, r - 1);
					return;
				}
				magic(s, pre, i); // This is recurrence!!!
				son.push_back(s.substr(pre, i - pre + 1));
				pre = i + 1;
			}
		}
	}
	sort(son.begin(), son.end());
	int idx = l;
	for (string str : son) {
		for (char c : str) {
			s[idx ++] = c;
		}
	}
}

int main() {
	// freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	while (tc --) {
		cin >> s1 >> s2;
		magic(s1, 0, s1.size() - 1);
		magic(s2, 0, s2.size() - 1);
		// cerr << s1 << ' ' << s2 << '\n';
		if (s1 == s2) {
			cout << "same\n";
		} else {
			cout << "different\n";
		}
	}
}