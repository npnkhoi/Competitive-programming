#include <bits/stdc++.h>
using namespace std;

const int N = 2000 * 512 + 3;
const string ROOT = "PAUL_ERDOS";

int cnt;
map<string, int> id;
int mark[N];
vector<int> authors, adj[N];
string name[N];

void add(string &a) {
	if (id.find(a) == id.end()) {
		id[a] = ++ cnt;
		name[cnt] = a;
	}
}

void input() {
	string line, a, b;
	int id_a, id_b;

	while (getline(cin, line)) {
		istringstream str(line);
		
		str >> a;
		// cerr << a << ' ';
		add(a);
		id_a = id[a];
		authors.push_back(id_a);

		while (str >> b) {
			// cerr << b << ' ';
			add(b);
			id_b = id[b];

			adj[id_a].push_back(id_b);
			adj[id_b].push_back(id_a);
		}
		// cerr << '\n';
	}
}

void flood() {
	memset(mark, -1, sizeof mark);
	queue<int> q;
	
	int root = id[ROOT];
	q.push(root);
	mark[root] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u]) {
			if (mark[v] == -1) {
				mark[v] = mark[u] + 1;
				q.push(v);
			}
		}
	}
}

void sorting() {
	// sort(authors.begin(), authors.end());
	// authors.resize(unique(authors.begin(), authors.end()) - authors.begin());

	// sort(authors.begin(), authors.end(), [](int a, int b) {
	// 	if ((mark[a] >= 0) ^ (mark[b] >= 0)) {
	// 		return mark[a] >= 0;
	// 	} else if (mark[a] >= 0) {
	// 		return mark[a] <= mark[b];
	// 	}
	// });
	for (int x : authors) {
		if (mark[x] == -1) {
			printf("%s no-connection\n", name[x].c_str());
		} else {
			printf("%s %d\n", name[x].c_str(), mark[x]);
		}
	}
}

int main() {
	// freopen("inp.txt", "r", stdin);
	input();
	flood();
	sorting();	
}