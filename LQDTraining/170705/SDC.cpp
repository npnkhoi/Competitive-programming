using namespace std;
#include <vector>
#include <iostream>
#include <stdio.h>
struct edge {int u, v, c; };
const int N = 1e3 + 50;
const int M = 1e5 + 50;
int m, n;
long long a, b, d[N];
long long _min, _max;
edge e[M];

int main() {
    freopen("sdc.inp","r",stdin);
    freopen("sdc.out","w",stdout);

    scanf("%d %d %lld %lld", &n, &m, &a, &b);

    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].c);

    for (int i = 1; i <= n; i++) {
        m++;
        e[m].u = 0;
        e[m].v = i;
        e[m].c = 0;
    }

    d[0] = 0;

    for (int i = 1; i <= n-1; i++)
    for (int j = 1; j <= m; j++) {
        int x = e[j].u, y = e[j].v, w = e[j].c;
        d[y] = min(d[y], d[x] + w);
    }

    for (int j = 1; j <= m; j++) {
        int x = e[j].u, y = e[j].v, w = e[j].c;
        if (d[y] > d[x] + w) {
            cout << "NO";
            return 0;
        }
    }
    _min = (long long)1e9; _max =  (long long)-1e9;
    for (int i = 1; i <= n; i++) _min = min(_min, d[i]), _max = max(_max, d[i]);
    if (_max - _min > b - a) cout << "NO";
    else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) printf("%lld ", d[i] + a - _min);
    }
}
