#include <cstdio>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
#define task "asummin"
#define fi first
#define se second
const int N = 1e5 + 5;
int m, n;
pair<int, int> a[N];
int b[N], x, y;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i].fi);
        a[i].fi = -a[i].fi;
        a[i].se = i;
    }
    sort(a+1, a+m+1);
    //for (int i = 1; i <= m; i++) printf("(%d, %d) ", a[i].fi, a[i].se);
    //cerr << "\n";
    int res = (int)2e9;
    for (int i = 1; i <= n; i++) {
        pair<int, int> val;
        scanf("%d", &val.fi);
        int pos = upper_bound(a+1, a+m+1, val) - a;
        //cerr << val.fi << " " << pos << "\n";
        //[] (pair<int, int> i, pair<int, int> j){ return a[i].fi < a[j].fi;}
        if (pos > 1 && abs(val.fi - a[pos-1].fi) < res) {
            //cerr << "ok1\n";
            //cerr << abs(val.fi - a[pos-1].fi) << "\n";
            res = abs(val.fi - a[pos-1].fi);
            x = a[pos-1].se;
            y = i;
        }
        if (pos <= m && abs(val.fi - a[pos].fi) < res) {
            //cerr << "ok2\n";
            res = abs(val.fi - a[pos].fi);
            x = a[pos].se;
            y = i;
        }
        //cerr << res << "\n";
    }
    printf("%d %d", x, y);
}

