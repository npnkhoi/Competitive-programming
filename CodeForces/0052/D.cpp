using namespace std;
#include <vector>
#include <stdio.h>

int n;
vector< pair<int, int> > tmp;
class unionFind {
    private: vector<int> Rank, anc;
    public:
    unionFind(int n) {
        Rank.assign(n, 0);
        anc.assign(n, 0);
        for (int i = 0; i < n; i++) anc[i] = i;
    }
    int root(int u) {return (u == anc[u]) ? u : anc[u] = root(anc[u]);}
    bool sameSet(int u, int v) {return root(u) == root(v);}
    void join(int u, int v) {
        int x = root(u), y = root(v);
        if (!sameSet(x, y)) {
            if (Rank[x] > Rank[y]) anc[y] = x;
            else {
                anc[x] = y;
                if (Rank[x] == Rank[y]) Rank[y]++;
            }
        }
    }
};
int main() {
    scanf("%d", &n);
    unionFind UF(n+5);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (!UF.sameSet(u, v))
            UF.join(u, v);
        else tmp.push_back(make_pair(u, v));
    }
    printf("%d\n", tmp.size());
    int cur = 0;
    for (int i = 2; i <= n; i++)
    if (!UF.sameSet(1, i)) {
        printf("%d %d %d %d\n", tmp[cur].first, tmp[cur].second, 1, i);
        UF.join(1, i);
        cur++;
    }
}
