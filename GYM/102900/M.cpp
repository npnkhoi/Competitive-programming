#include <bits/stdc++.h>
using namespace std;

struct Node {
	vector<Node*> child;
	string name;
	int cnt = 0, cnt_ignore = 0;

	Node() {
		child = {};
		name = "";
	}

	Node(string &name, int cnt, int ignore) {
		this->name = name;
		this->cnt = cnt;
		cnt_ignore = ignore;
	}
};

Node *root;

void add_child(Node *&pointer, string &s, bool ignore) {
	for (Node *child : (pointer -> child)) {
		// cerr << "-- adding child " << s << " " << child -> name << '\n';
		if (child -> name == s) {
			pointer = child;
			(pointer -> cnt) ++;
			(pointer -> cnt_ignore) += ignore;
			return;
		}
	}
	// cerr << "adding new child with name " << s << '\n';
	Node *new_child = new Node(s, 1, ignore);
	(pointer -> child).push_back(new_child);
	pointer = new_child;
}

void add_string(string &str, bool ignore) {
	// cerr << "Root = " << root << '\n';
	int len = str.size();
	str += "/";
	Node* pointer = root;
	root -> cnt ++;
	root -> cnt_ignore += ignore;
	string s = "";

	for (auto c : str) {
		if (c == '/') {
			add_child(pointer, s, ignore);
			// cerr << "pointer = " << pointer << '\n';
			s = "";
		} else {
			s += c;
		}
	}
}

int dfs(Node *pointer) {
	if (pointer -> cnt == pointer -> cnt_ignore) {
		// cerr << "end at " << pointer -> name << '\n';
		if (pointer == root) {
			return (pointer -> child).size();
		}
		return 1;
	}
	int ret = 0;
	for (auto child : pointer -> child) {
		ret += dfs(child);
	}
	return ret;
}

int main() {
	int tc;
	cin >> tc;
	while (tc --) {
		int n, m;
		cin >> n >> m;
		root = new Node();

		for (int i = 0; i < m + n; ++ i) {
			string dir;
			cin >> dir;
			add_string(dir, i < n);
		}
		// cerr << "num child of root: " << root -> child.size() << '\n';
		cout << dfs(root) << '\n';
	}
}
