using namespace std;
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define mp make_pair
typedef pair<int, int> ii;
const int N = 4e3 + 10;
const int M = 1e4 + 10;

vector<pair<int, ii> > e;
int f[N][M];

class UnionFind {
private: vector<int> p, Rank, _range;
public:
    UnionFind(int N) {
        Rank.assign(N, 0);
        p.assign(N, 0);
        _range.assign(N, 1);
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
        if (Rank[x] > Rank[y]) p[y] = x, _range[x] += _range[y];
        else {
            p[x] = y;
            _range[y] += _range[x];
            if (Rank[x] == Rank[y]) Rank[y] ++;
        }
    }
    int Range(int u) { return _range[FindSet(u)]; }
};
int main() {
    freopen("EMOTOR.inp","r",stdin);
    freopen("EMOTOR.out","w",stdout);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);
        e.clear();

        for (int i = 0; i < m; i++){
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            e.push_back(mp(c, mp(u, v)));
        }
        sort(e.begin(), e.end());
        UnionFind UF(n+5);
        for (int j = 0; j < m; j++) {
            int x = e[j].second.first, y = e[j].second.second;
            if (!UF.SameSet(x, y)) UF.UnionSet(x, y);
            for (int i = 1; i <= n; i++) f[i][j] = UF.Range(i);
        }
        while (q--) {
            int Qi, Qd;
            scanf("%d %d", &Qi, &Qd);
            int lo = 0, hi = m-1, mi;
            while (lo < hi) {
                mi = (lo + hi + 1) / 2;
                if (e[mi].first <= Qd) lo = mi;
                else hi = mi - 1;
            }
            if (Qd < e[lo].first) printf("1\n");
            else printf("%d\n", f[Qi][lo]);
        }
    }
}
