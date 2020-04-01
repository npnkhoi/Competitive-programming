#include <bits/stdc++.h>
using namespace std;

struct Node{
	*Node nxt[MAX_CHAR];
	vector<int> ids;
}

void Init(Node &*p) {
	p = new Node;
	memset(p -> nxt, 0, sizeof p -> nxt);
	p -> ids.clear();
}

void Insert(char s[], int id) {
	int n = strlen(s);
	Node *p = T;
	for (int i = 0; i < n; ++ i) {
		tmp = s[i] - 'a';
		if (p -> nxt[tmp] == NULL) {
			Init(p -> nxt[tmp]);
		}
		p = p -> nxt[tmp];
		p -> 
	}
}

int main() {
	Node *Trie;
	Init(Trie);
	scanf("%d ", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", s);
		Insert(s, i);
	}
}