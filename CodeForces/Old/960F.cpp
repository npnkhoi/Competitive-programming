// 5:54
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
map<int, int> myMap[N];
map<int, int>::iterator it;

int Get(int u, int c) {
    it = myMap[u].lower_bound(c);
    if (it == myMap[u].begin()) return 0;
    else {
        it --;
        return it -> second;
    }
}
void Add(int u, int c, int l) {
    it = myMap[u].upper_bound(c);
    if (it != myMap[u].begin()) {
        it --;
        if ((it -> second) >= l) return;
    }
    while (1) {
        it = myMap[u].lower_bound(c);
        if ((it != myMap[u].end()) && (it -> second) <= l) myMap[u].erase(it);
        else break;
    }
    myMap[u][c] = l;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        //Add(u, c, Get(v, c) + 1);
        //cerr << "ok1\n";
        Add(v, c, Get(u, c) + 1);
        //cerr << "ok2\n";
    }
    int res = 0;
    for (int i = 1; i <= n; i++) if (!myMap[i].empty()) res = max(res, myMap[i].rbegin() -> second);
    printf("%d", res);
}
