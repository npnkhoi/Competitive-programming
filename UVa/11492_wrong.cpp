using namespace std;
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> ii;
const int N = 26 * 4010;
const int oo = 1e9 + 7;
priority_queue <ii> pq;
map<string, int> lang;
vector<ii> adj[N];
int d[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    while (scanf("%d", &m)) {
        if (!m) break;

        lang.clear();
        for (int i = 0; i < N; i++) adj[i].clear();
        while (!pq.empty()) pq.pop();

        string s, f;
        cin >> s >> f;
        lang[s] = 0; lang[f] = 1;
        int n = 1;

        while (m--) {
            string u, v, c;
            cin >> u >> v >> c;
            if (lang.find(u) == lang.end()) lang[u] = ++ n;
            if (lang.find(v) == lang.end()) lang[v] = ++ n;
            int x = 26 * lang[u] + c[0] - 'a';
            int y = 26 * lang[v] + c[0] - 'a';

            for (int z = y - y%26; z < y - y%26 + 26; z++)
            if (z != y)
            adj[x].push_back(mp(z, (int)c.size())),
            adj[z].push_back(mp(x, (int)c.size()));

            for (int z = x - x%26; z < x - x%26 + 26; z++)
            if (z != x)
            adj[y].push_back(mp(z, (int)c.size())),
            adj[z].push_back(mp(y, (int)c.size()));
        }

        /*for (int k = 0; k <= n; k++)
        for (int i = 0; i <= 24; i++)
        for (int j = i + 1; j <= 25; j++)
        adj[26*k + i].push_back(mp(26*k + j, 0)),
        adj[26*k + j].push_back(mp(26*k + i, 0));*/

        /*for (int i = 0; i < 26*(n+1); i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j].fi;
                if (abs(v - i) >= 26)
                    printf("%d\n", adj[i][j].fi);
            }
            //printf("\n");
        }*/
        //printf("\n");

        for (int i = 26; i <= 26*(n + 1); i++) d[i] = oo;

        for (int i = 0; i < 26; i++) {
            d[i] = 0;
            pq.push(mp(0, i));
        }

        while (!pq.empty()) {
            ii t = pq.top(); pq.pop();
            int dist = t.fi, u = t.se;
            //printf("try %d\n", u);
            if (d[u] < dist) continue;
            for (int j = 0; j < adj[u].size(); j++) {
                ii v = adj[u][j];
                if (dist + v.se < d[v.fi]) {
                    //printf("%d %d\n", v.fi);
                    d[v.fi] = dist + v.se;
                    pq.push(mp(d[v.fi], v.fi));
                }
            }
        }

        int res = oo;
        for (int i = 26; i < 52; i++) res = min(res, d[i]);
        if (res == oo) printf("impossivel\n");
        else printf("%d\n", res);
    }
}
