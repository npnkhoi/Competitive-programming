#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii pair<int, ii>
#define X first
#define Y second
const int N = 111;
const double eps = 1e-4;
using namespace std;
vector<iii> e;
int n, m;
double d[N];

bool Relax(iii e, double w) {
    bool ret = d[e.Y.X] + e.X - w < d[e.Y.Y];
    if (ret)
        d[e.Y.Y] = d[e.Y.X] + e.X - w;
    return ret;
}

bool NC_exist(double avg) {
    //check if there is a negative cycle using BellmanFord Alg
    //each edge is decreased by avg
    int i, j; bool stop;
    for(i = 1; i <= n; i++) d[i] = 0;
    for(i = 1; i < n; i++) {
        stop = true;
        for(j = 0; j < m; j++)
            if (Relax(e[j], avg))
                stop = false;
        if (stop) break;
    }
    for(j = 0; j < m; j++)
        if (Relax(e[j], avg)) return true;
    return false;
}

int main()
{
    freopen("QBTRANS.inp", "r", stdin);
    freopen("QBTRANS.ans", "w", stdout);
    scanf("%d %d\n", &n, &m);
    int i, u, v, c;
    for(i=0; i<m; i++) {
        scanf("%d %d %d\n", &u, &v, &c);
        e.push_back(iii(c, ii(u, v)));
    }
    double l = 0, r = 1e9, mid, res = -1;
    while (r - l > eps) {
        mid = (l + r) / 2;
        if (NC_exist(mid)) {
            res = mid;
            r = mid;
        }
        else
            l = mid;
    }
    if (res < 0 || res > 1e8) printf("-1");
    else printf("%.2f", res);
    return 0;
}
