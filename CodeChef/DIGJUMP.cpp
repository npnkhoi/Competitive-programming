#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

int n, dist[N];
bool flooded[N];
vector<int> pos[10];
queue<int> q;
char s[N];

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++ i) {
		pos[s[i] - '0'].push_back(i);
	}
	q.push(0);
	for (int i = 1; i < n; ++ i) {
		dist[i] = oo;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int val = s[u] - '0';
		if (!flooded[val]) {
			flooded[val] = 1;
			for (int x : pos[val]) {
				if (dist[x] == oo) {
					dist[x] = dist[u] + 1;
					q.push(x);
				} 
			}
		}
		if (u > 0 && dist[u - 1] == oo) {
			dist[u - 1] = dist[u] + 1;
			q.push(u - 1);
		}
		if (u < n - 1 && dist[u + 1] == oo) {
			dist[u + 1] = dist[u] + 1;
			q.push(u + 1);
		}
	}
	printf("%d", dist[n - 1]);
}