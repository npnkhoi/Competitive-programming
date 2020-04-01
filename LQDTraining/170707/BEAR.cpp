using namespace std;
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

#define fi first
#define se second

const int M = 1e5 + 50;
const int N = 1e4 + 50;
int s[N];
vector< pair<int, pair<int, int> > > e;
int res;


class UnionFind {
private: vector<int> p, Rank;
public:
    UnionFind(int N) {
        Rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int FindSet(int u) {
        return (p[u] == u) ? u : (p[u] = FindSet(p[u]));
    }

    bool SameSet(int u, int v) {
        return (FindSet(u) == FindSet(v));
    }

    UnionSet(int u, int v) {
        int x = FindSet(u), y = FindSet(v);
        if (Rank[x] > Rank[y]) p[y] = x;
        else {
            p[x] = y;
            if (Rank[x] == Rank[y]) Rank[y] ++;
        }
    }
};
int main () {
    int n, m, x;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        e.push_back(make_pair(c + s[u] + s[v], make_pair(u, v)));
    }
    sort(e.begin(), e.end());
    //--------------------------------
    UnionFind UF(n+5);
    for (int i = 0; i < m; i++) {
        int c = e[i].fi,
        u = e[i].se.fi,
        v = e[i].se.se;
        if (!UF.SameSet(u, v)) {
            cout << u << " " << v << "\n";
            res += c<<1;
            UF.UnionSet(u, v);
        }
    }
    cout << res;
}
