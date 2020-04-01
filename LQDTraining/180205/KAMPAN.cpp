#include <cstdio>
using namespace std;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
    backTrack(1);
}
