using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>

const int N = 110;

vector<int> adj[N];
map<string, int> data;
bool sign[N];
vector<int> ans;
string bev[N];

int n, m;


void dfs(int u) {
    //printf("dfs %d\n", u);
    sign[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (!sign[v]) dfs(v);
    }
    ans.push_back(u);
}

int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int tc = 0;

    while (scanf("%d\n", &n) != EOF) {
        tc ++;
        if (tc >= 2) printf("\n");
        //cout << n << endl;

        data.clear();
        memset(sign, 0, sizeof sign);
        ans.clear();
        for (int i = 0; i <= n; i++) adj[i].clear();

        for (int i = 1; i <= n; i++) {
            cin >> bev[i];
            //getline(cin, bev[i]);
            //cout << bev[i] << endl;
            data[bev[i]] = i;
        }

        scanf("%d\n", &m);
        //cout << m << endl;
        while (m--) {
            string u, v;
            cin >> u;
            cin >> v;
            adj[data[u]].push_back(data[v]);
        }

        for (int i = 1; i <= n; i++) if (!sign[i]) dfs(i);

        printf("Case #%d:", tc);
        printf(" Dilbert should drink beverages in this order: ");
        for (int i = n-1; i > 0; i--) printf("%s ", bev[ans[i]].c_str());
        printf("%s.\n", bev[ans[0]].c_str());
        //for (int i = n-1; i >= 0; i --) printf("%d ", ans[i]);
        //cout << endl;
        scanf("\n");
    }
}
