#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
const int N = 205;
int n, cnt[N];
vector<int> adj[N], ans;
string line;
void dfs(int u) {
    cnt[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (cnt[v] == 0) {
            dfs(v);
            cnt[u] += cnt[v];
        }
    }
}
int main() {
    scanf("%d ", &n);
    for (int i = 1; i <= n; i++) {
        getline(cin, line);
        istringstream iss(line);
        int j;
        while (iss >> j) adj[i].push_back(j);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    if (adj[i].size() == 2 && abs(n-1 - 2 * (cnt[i] - 1)) <= 1) ans.push_back(i);
    if (ans.size() == 0) printf("0");
        else
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}
