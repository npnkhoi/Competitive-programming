using namespace std;
#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>

const int N = 2e3 + 10;

int n, m;
vector<int> adj[N];
int cnt, cntDfs, cntScc, num[N], low[N];
bool onStack[N], sign[N], cont;
stack<int> st;

void dfs(int u) {
    //printf("dfs %d\n", u);
    num[u] = low[u] = cntDfs++;
    st.push(u); onStack[u] = 1;

    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (num[v] == -1) dfs(v);
        if (onStack[v]) low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u]) {
            while (1) {
                int v = st.top();
                st.pop(); onStack[v] = 0;
                //printf("%d ", v);
                cnt ++;
                if (v == u) break;
            }
            //printf("\n");
            cntScc ++;
        }
}
int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    while (scanf("%d %d", &n, &m)) {
        if (!m && !n) break;

        for (int i = 0; i <= n; i++) adj[i].clear();
        while (!st.empty()) st.pop();
        memset(sign, -1, sizeof sign);
        memset(num, -1, sizeof num);
        memset(onStack, 0, sizeof onStack);

        while (m--) {
            int k, u, v;
            scanf("%d %d %d", &u, &v, &k);
            adj[u].push_back(v);
            if (k == 2) adj[v].push_back(u);
        }
        cntScc = cntDfs = cnt = 0;
        cont = 1;
        dfs(1);
        printf("%d\n", cntScc == 1 && cnt == n);
    }
}
