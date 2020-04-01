#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;

int n, res;
string s[N];
unordered_map<string, int> cnt;

int main() {
	scanf("%d ", &n);
	for (int i = 1; i <= n; ++ i) {
		getline(cin, s[i]);
	}
	sort(s + 1, s + n + 1, [] (string &a, string &b) {
		return a.size() < b.size();
	});
	for (int x = 1; x <= n; ++ x) {
		int l = s[x].size();
		for (int i = 0; i < l; ++ i) {
			string tmp = "";
			for (int j = i; j < l; ++ j) {
				tmp += s[x][j];
				res += cnt[tmp];
			}
		}
		cnt[s[x]] ++;
	}
	printf("%d\n", res);
}