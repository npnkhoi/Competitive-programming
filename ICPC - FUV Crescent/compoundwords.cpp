#include <bits/stdc++.h>
using namespace std;

vector<string> s;
string str;
set<string> comp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> str) {
		s.push_back(str);
	}
	for (int i = 0; i < s.size() - 1; ++ i) {
		for (int j = i + 1; j < s.size(); ++ j) {
			comp.insert(s[i] + s[j]);
			comp.insert(s[j] + s[i]);
		}
	}
	for (string s : comp) {
		cout << s << '\n';
	}
}