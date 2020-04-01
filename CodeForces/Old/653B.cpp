using namespace std;
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

int n, q;
vector<int> adj[8];
int f[8][8];

int main () {
    scanf("%d %d\n", &n, &q);
    while (q--) {
        string line;
        getline(cin, line);
        adj[line[3] - 'a'].push_back(line[0] - 'a');
    }
    for (int i = 0; i < 6; i++) f[n][i] = 1;

    for (int i = n-1; i >= 1; i--)
    for (int u = 0; u < 6; u++)
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        f[i][u] += f[i+1][v];
    }
    printf("%d", f[1][0]);
}
