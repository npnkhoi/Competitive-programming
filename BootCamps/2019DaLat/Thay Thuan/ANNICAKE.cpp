#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, maxTime, x, t, res;
long long s;
priority_queue<int> heap;

int main() {
	scanf("%d%d", &n, &maxTime);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &x, &t);
		s += t;
		heap.push(t);
		while (s > maxTime - x && !heap.empty()) {
			s -= heap.top();
			heap.pop();
		}
		res = max(res, (int) heap.size());
	}
	printf("%d\n", res);
}