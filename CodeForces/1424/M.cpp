#include <bits/stdc++.h>
using namespace std;

const int CHAR = 26;
const int PAGES = 1e3 + 5;

bool in_dict[CHAR]; // must be all false initially
bool cyclic;
int mark[CHAR];
vector<int> adj[CHAR], topo_order;
string head_str[PAGES], tail_str[PAGES];

void get_info(string s1, string s2) {
	// cerr << "get info ... " << s1 + " " + s2 << '\n';
	int m = s1.size(), n = s2.size();
	for (int i = 0; i < min(m, n); ++ i) {
		if (s1[i] != s2[i]) {
			adj[s1[i] - 'a'].push_back(s2[i] - 'a');
			return;
		}
	}
	if (m > n) {
		// cerr << "length issue " + s1 + " " + s2 + '\n';
		cout << "IMPOSSIBLE";
		exit(0);
	}
}

void dfs(int u) {
	mark[u] = 1;
	for (int v: adj[u]) {
		if (mark[v] == 1) {
			cyclic = true;
			break;
		} else if (mark[v] == 0) {
			dfs(v);
		}
	}
	topo_order.push_back(u);
	mark[u] = 2;
}

string get_order() {
	cyclic = false;
	topo_order.clear();
	memset(mark, 0, sizeof mark);

	for (int c = 0; c < CHAR; ++ c) {
		if (mark[c] == 0 && in_dict[c]) {
			dfs(c);
		}
	}
	// cerr << "after dfs ... " << topo_order.size() << '\n';
	if (cyclic) {
		// cerr << "returning null\n";
		return "";
	}
	string res = "";
	for (int i = topo_order.size() - 1; i >= 0; -- i) {
		res += char(topo_order[i] + 'a');
	}	
	// cerr << '\n';
	// cerr << "returning\n";
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++ i) {
		int page;
		cin >> page;
		string head = "", curr, pre;
		for (int j = 0; j < k; ++ j) {
			pre = curr;
			cin >> curr;
			for (char c : curr) {
				in_dict[c - 'a'] = true;
			}
			if (head == "") {
				head = curr;
			} else {
				get_info(pre, curr);
			}
		}
		head_str[page] = head;
		tail_str[page] = curr;
		get_order();

		if (cyclic) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	// cerr << "done first phase\n";
	for (int i = 1; i < n; ++ i) {
		get_info(tail_str[i-1], head_str[i]);
	}
	// cerr << "done second phase\n";
	string res = get_order();

	if (cyclic) {
		cout << "IMPOSSIBLE";
	} else {
		cout << res;
	}
}