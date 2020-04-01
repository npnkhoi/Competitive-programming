using namespace std;
#include <stdio.h>
#include <vector>
#include <string.h>

const int N = 5e4 + 10;
vector <int> adj, s;
vector <bool> sign;

int dfs(int u) {
    //printf("dfs %d\n",u);
    sign[u] = 1;
    int sum = 0;
    if (adj[u] != -1 && !sign[adj[u]])
        sum += 1 + dfs(adj[u]);
    sign[u] = 0;
    return s[u] = sum;

}
int main() {
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        int n;
        scanf("%d", &n);

        sign.assign(n + 5, 0);
        s.assign(n + 5, -1);
        adj.assign(n + 5, -1);

        for (int i = 1; i <= n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u] = v;
        }

        int Max = 0, ans = 1;

        for (int i = 1; i <= n; i++) {
            if (s[i] == -1) dfs(i);
            printf("%d\n", s[i]);
            if (Max < s[i]) Max = s[i], ans = i;
        }
        printf("Case %d: %d\n", tc, ans);
    }
}
