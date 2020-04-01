using namespace std;
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>

const int N = 30;
int tc;
vector<int> pre[N], adj[N];
long long t[N], memo[N];
bool isPre[N];

long long cal(int u) {
    if (memo[u] != -1) return memo[u];

    long long tmp = 0;
    for (int i = 0; i < pre[u].size(); i++)
        tmp = max(tmp, cal(pre[u][i]));

    memo[u] = tmp + t[u];
    return memo[u];
}

int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    scanf("%d\n\n", &tc);

    while (tc --) {

        int n = 0;
        for (int i = 0; i < N; i++) pre[i].clear();
        //for (int i = 0; i < N; i++) adj[i].clear();
        memset(t, 0, sizeof t);

        while (1) {
            string line;
            getline(cin, line);
            if (line == "") break; else n++;
            int u = line[0] - 'A';
            int i;
            for (i = 2; line[i] != ' ' && i < (int)line.size(); i++)
            t[u] = 10*t[u] + line[i] - '0';

            for (i++; i < line.size(); i++)
                pre[u].push_back(line[i] - 'A');
        }

        //cout << "ok\n" ;

        long long res = 0;
        for (int i = 0; i < N; i++) memo[i] = -1;

        for (int i = 0; i < n; i++)
            res = max(res, cal(i));
        printf("%lld\n", res);
        if (tc) printf("\n");
    }

}
