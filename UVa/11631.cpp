using namespace std;
#include <bits/stdc++.h>

vector< pair<int, pair<int, int> > > e;
long long res, sum;
int cnt;

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
    void UnionSet(int u, int v) {
        int x = FindSet(u), y = FindSet(v);
        if (Rank[x] > Rank[y]) p[y] = x;
        else {
            p[x] = y;
            if (Rank[x] == Rank[y]) Rank[y] ++;
        }
    }
};
int main () {
    int n, m;
    while (1)
{
    scanf("%d %d", &n, &m);
    if (m == n && n == 0) break;
    e.clear(); sum = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        e.push_back(make_pair(c, make_pair(u, v)));
        sum += c;
    }
    sort(e.begin(), e.end());
    //--------------------------------
    UnionFind UF(n+5); res = cnt = 0;
    for (int i = 0; i <= m-1; i++) {
        int c = e[i].first,
        u = e[i].second.first,
        v = e[i].second.second;
        if (!UF.SameSet(u, v)) {
            res += c;
            UF.UnionSet(u, v);
            cnt ++;
            if (cnt == n-1) break;
        }
    }
    printf("%lld\n", sum - res);
}
}
