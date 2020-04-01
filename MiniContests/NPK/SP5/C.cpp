using namespace std;
#include <bits/stdc++.h>
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int N = 110;

int cow[N*N], cnt, n, sign[N*N];
vector<int> adj[N*N];

int id(int x, int y) {return n*(x-1) + y-1; }
/*int xx(int s) {return s / (n+1); }
int yy(int s) {return s % (n+1); }*/



bool inRange(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= n;}

void dfs(int u) {
    sign[u] = cnt;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != -1 && sign[v] == 0) dfs(v);
    }
}
int main() {
    int k, r;
    scanf("%d %d %d", &n, &k, &r);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    for (int z = 0; z < 4; z++) {
        int u = i + dx[z], v = j + dy[z];
        if (inRange(u, v)) adj[id(i, j)].push_back(id(u, v));
    }

    while (r--) {
        int x, y, u, v;
        scanf("%d %d %d %d", &x, &y, &u, &v);
        int a = id(x, y), b = id(u, v);
        for (int i = 0; i < adj[a].size(); i++)
            if (adj[a][i] == b) adj[a][i] = -1;
        for (int i = 0; i < adj[b].size(); i++)
            if (adj[b][i] == a) adj[b][i] = -1;
    }

    cnt = 0;
    for (int i = 0; i < n*n; i++)
    if (sign[i] == 0) cnt ++, dfs(i);

    for (int i = 1; i <= k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        cow[i] = id(u, v);
    }

    int res = 0;

    for (int i = 1; i < k; i++)
    for (int j = i+1; j <= k; j++) res += sign[cow[i]] != sign[cow[j]];

    //for (int i = 0; i < n*n; i++) cout << sign[i] << endl;

    cout << res;
}
