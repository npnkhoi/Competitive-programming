using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

const int N = 200;
int into[N], ans[N];
char a[N];
vector<int> adj[N];
int n;
bool NoSol, sign[N];

void BackTrack(int i) {
    //printf("BT %d\n", i);
    for (int j = 0; j < n; j++) if (!into[a[j]] && (!sign[j])){
        ans[i] = j;
        sign[j] = 1;
        int u = a[j];
        for (int k = 0; k < adj[u].size(); k++) into[adj[u][k]] --;

        if (i < n-1) BackTrack(i + 1);
            else {
                NoSol = 0;
                for (int k = 0; k < n-1; k++) printf("%c ", a[ans[k]]);
                printf("%c\n", a[ans[n-1]]);
            }

        for (int k = 0; k < adj[u].size(); k++) into[adj[u][k]] ++;
        sign[j] = 0;
    }
}
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int tc;
    scanf("%d\n", &tc);
    while (tc--) {
        string str;

        getline(cin, str);
        //cout << "ok" << "\n";
        for (int i = n = 0; i < str.size(); i += 2, n++) a[n] = str[i];
        //printf("n = %d\n", n);
        // -------------------
        for (int i = 'A'; i <= 'Z'; i ++) adj[i].clear();
        memset(into, 0, sizeof into);
        getline(cin, str);
        //printf("-%s-\n", str.c_str());

        for (int i = 0; i < str.size(); i += 4) {
            char x = str[i], y = str[i+2];
            adj[x].push_back(y);
            into[y] ++;
            //cout << i << "\n";
        }
        //cout << "ok\n";
        NoSol = 1;
        memset(sign, 0, sizeof sign);

        BackTrack(0);

        if (NoSol) printf("NO\n");
        if (tc) scanf("\n"), printf("\n");
    }
}
