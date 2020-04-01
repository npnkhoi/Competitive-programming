#include <bits/stdc++.h>
using namespace std;

int n;
string key, song;
vector<string> ans;

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);
	scanf("%d ", &n);
	getline(cin, key);
	// cerr << key << '\n';
	for (int i = 0; i < n; ++ i) {
		getline(cin, song);
		string abbr = "";
		abbr += tolower(song[0]);
		for (int j = 1; j < song.size(); ++ j) {
			if (song[j] == ' ') abbr += tolower(song[j + 1]);
		}
		// cerr << abbr << '\n';
		if (abbr == key) {
			ans.push_back(song);
		}
	}
	cout << ans.size() << '\n';
	for (string song : ans) {
		cout << song << '\n';
	}
}