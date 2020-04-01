using namespace std;
#include <stdio.h>
#include <iostream>
#include <string>
#include <bitset>

const int N = 1e3 + 10;
bitset<N> sign;
bool adj[N][N];
string name[2*N];
int n;
int dfs(int u) {
    sign[u] = 1;
    for (int v = 0; v < 2*n; v++)
        if (!sign[v] && adj[u][v]) dfs(v);
}
int main () {
    //ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    //cout << n << endl;
    for (int i = 0; i < n; i++) {
        string x, y;
        cin >> x >> y;
        //cout << x[0] << y[0] << endl;
        name[i] = x[0]; name[i] += x[1]; name[i] += x[2];
        name[i+n] = x[0]; name[i+n] += x[1]; name[i+n] += y[0];
        //cout << name[i] << " " << name[i+n] << "\n";
    }
    //cout << "ok\n";

    /*for (int i = 0; i < n; i++) adj[i][i+n] = adj[i+n][i] = 1;
    for (int i = 0; i < n-1; i++)
    for (int j = i+1; j < n; j++) if (name[i] == name[j]) {
        adj[i][j] = 1;
        adj[j][i] = 1;
        adj[i][j+n] = 1;
        adj[j+n][i] = 1;
        adj[j][i+n] = 1;
        adj[i+n][j] = 1;
    }

    for (int i = 0; i < n-1; i++)
    for (int j = n; j < 2*n; j++) if (name[i] == name[j])
        adj[i][j] = adj[j][i] = 1;*/

    /*for (int i = 0; i < n-1; i++)
    for (int j = i+1; j < n; j++)
    if (name[i] != name[j])
        adj[i].pb(j), adj[j].pb(i);
    for (int i = n; i < 2*n; i++)
    for (int j = n; j < 2*n; j++)
    if (name[i] != name[j])
        adj[i].pb(j), adj[j].pb(i);
    for (int i = 0; i < n; i++)
    for (int j = n; j < 2*n; j++)*/

    for (int i = 0; i < 2*n; i++)
    for (int j = 0; j < 2*n; j++) {
        //cout << i << " " << j << "\n";
        if (name[i] == name[j]) adj[i][j] = 0;
        else if (name[i%n] == name[j%n])
            adj[i][j] = i>=n && j>=n;
        else adj[i][j] = 1;
    }
    //cout << "ok\n";

    for (int i = 0; i < 2*n; i++)
    for (int j = 0; j < 2*n; j++) cout << adj[i][j] << " \n"[j==2*n-1];


    dfs(0);
    bool ok = 1;
    for (int i = 0; i < n; i++) if (!sign[i] && !sign[i+n]) {ok = 0; break;}
    if (!ok) {
        ok = 1;
        sign.reset();
        dfs(1);
        for (int i = 0; i < n; i++) if (!sign[i] && !sign[i+n]) {ok = 0; break;}
    }
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            if (sign[i]) cout << name[i];
            else cout << name[i+n];
            cout << "\n";
        }
    }
    else cout << "NO\n";
}
