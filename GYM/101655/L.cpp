#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
string lang[N], line, word;
map<string, int> id;

bool ok(char ch) {
	return isalpha(ch) || ch == '\'' || ch == '-';
}
void toLower(string &s) {
	for (int i = 0; i < s.size(); ++ i) {
		if (isalpha(s[i]) && s[i] < 'a') {
			s[i] += 'a' - 'A';
		}
	}
}

int main() {
	// freopen("L.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin.ignore();

	for (int i = 1; i <= n; ++i) {
		getline(cin, line);
		istringstream iss(line);
		iss >> lang[i];
		while (iss >> word) {
			toLower(word);
			id[word] = i;
		}
	}
	getline(cin, line);
	while (getline(cin, line)) {
		word = "";

		bool flag = 0;
		for (int i = 0; i < line.size(); ++ i) {
			if (ok(line[i])) {
				word += line[i];
			} else {
				toLower(word);
				if (id.find(word) != id.end()) {
					cout << lang[id[word]] << '\n';
					flag = 1;
					break;
				}
				// if (word != "") cerr << word << "\n";
				word = "";
			}
		}
		if (!flag) {
			toLower(word);
			cout << lang[id[word]] << '\n';		
		}
	}
}