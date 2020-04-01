using namespace std;
#include <stdio.h>
#include <vector>
#include <string.h>
//#include <>

const int N = 5e4 + 10;
vector <int> adj[N];
int sign[N], s[N];
void dfs(int u, int cnt) {
    //printf("visit %d\n", u);
    sign[u] = cnt; s[cnt] ++;
    int v = adj[u];
    if (sign[v] == 0) dfs(v, cnt);
    else if (sign[v] != cnt)
    s[cnt] += s[sign[v]];
    //printf("\n");
}
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) adj[i].clear();

        for (int i = 1; i <= n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u] = v;
        }

        int res = 0, ans, cnt = 0;
        //for (int i = 1; i <= n; i++) p[i] = i;
        memset(sign, 0, sizeof sign);
        memset(s, 0, sizeof s);

        for (int i = 1; i <= n; i++) {
            if (sign[i] == 0) dfs(i, ++cnt);
            if (res < s[sign[i]]) res = s[sign[i]], ans = i;
                //printf("%d %d %d\n",res,sign[i],ans);
            //for (int i = 1; i <= n; i++) printf("%d ", sign[i]);
            //printf("%d %d\n",res,ans);
        }
        //for (int i = 1; i <= cnt; i++) printf("%d ", s[i]); printf("\n");
        //printf("%d %d\n",sign[1297],s[sign[1297]]);
        printf("Case %d: %d\n", tc, ans);
    }
}
