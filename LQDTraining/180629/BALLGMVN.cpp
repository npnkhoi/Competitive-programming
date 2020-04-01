using namespace std;
#include <stdio.h>
#include <utility>
#include <set>
#include <cmath>
#include <ctime>
#include <map>
#define mp make_pair
#define task "ballgmvn"
typedef pair<int, int> ii;
const int N = 2010;
int x[N], y[N], n;
long long res;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a%b);}
void simply(int &u, int &v) {
    if (u == 0) v = 1;
    else if (v == 0) u = 1;
    else {
        int t = gcd(abs(u), abs(v));
        u /= t; v /= t;
        if (v < 0) v = -v, u = -u;
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        map<ii, int> data;
        for (int j = n+1; j <= 2*n; j++) {
            int u = x[j] - x[i];
            int v = y[j] - y[i];
            simply(u, v);
            if (data.find(mp(u, v)) != data.end()) {
                printf("%d %d %d\n", i, data[mp(u, v)], j);
                return 0;
            }
            data[mp(u, v)] = j;
        }
    }
    for (int i = n+1; i <= n+n; i++) {
        map<ii, int> data;
        for (int j = 1; j <= n; j++) {
            int u = x[j] - x[i];
            int v = y[j] - y[i];
            simply(u, v);
            if (data.find(mp(u, v)) != data.end()) {
                printf("%d %d %d\n", i, data[mp(u, v)], j);
                return 0;
            }
            data[mp(u, v)] = j;
        }
    }
    printf("-1\n");
    return 0;
}