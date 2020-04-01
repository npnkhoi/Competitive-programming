#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define task "smst"

const int N = 200 + 5;


struct Edge {
    int u, v, c;
};
bool operator < (Edge b, Edge a) { return b.c < a.c;}
vector<Edge> EdgeList;
int n, m, lab[N];

int root(int u) {
    if (lab[u] < 0) return u;
    else return lab[u] = root(lab[u]);
}
void join(int u, int v) {
    u = root(u), v = root(v);
    if (lab[u] < lab[v]) lab[v] = u;
    else {
        lab[u] = v;
        lab[v] -= lab[u] == lab[v];
    }
}
void solve() {
    int cnt = 0;
    long long res = 0;
    memset(lab, -1, sizeof lab);
    sort(EdgeList.begin(), EdgeList.end());
    for (int i = 0; i < EdgeList.size(); ++i) {
        int u = EdgeList[i].u;
        int v = EdgeList[i].v;
        if (root(u) != root(v)) {
            res += EdgeList[i].c;
            join(u, v);
            EdgeList[cnt ++] = EdgeList[i];
        }
    }
    EdgeList.resize(cnt);
    if (cnt == n-1) printf("%lld\n", res);
    else printf("123456789\n");
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d %d", &n, &m);
    while (m--) {
        Edge tmp;
        scanf("%d %d %d", &tmp.u, &tmp.v, &tmp.c);
        EdgeList.push_back(tmp);
        solve();
    }
}

