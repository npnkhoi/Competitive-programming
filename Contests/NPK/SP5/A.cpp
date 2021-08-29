using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>

typedef pair<int, int> ii;
#define fi first
#define se second
const int N = 2e4 + 10;

map<int, int> data;
int a[N], res;
pair<int, int> b[N];

bool cmp(ii a, ii b) {
    if (b.fi <= a.fi && a.se <= b.se) return 1;
    else if (a.fi <= b.fi && b.se <= a.se) return 0;
    else return a.fi <= b.fi;
}

void Push(int x) {
    if (data.find(x) != data.end()) data[x] ++;
    else data[x] = 1;
}

void Pop(int x) {
    if (data[x] == 1) data.erase(x);
    else data[x] --;
}
int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]), Push(a[i]);
    for (int i = 1; i <= n; i++) scanf("%d %d", &b[i].fi, &b[i].se);

    //sort(a+1, a+m+1);
    sort(b+1, b+n+1, cmp);

    res = 0;

    for (int  j = 1; j <= n; j++) {
        //while (i <= m && a[i] < b[j].fi) i++;
        //cout << i << " ";
        //if (i <= m && a[i] <= b[j].se) res ++, i++;
        //cout << i << endl;
        map<int, int>::iterator it;
        it = data.lower_bound(b[j].fi);
        if ((it->first) <= b[j].se) res ++, Pop(it -> first);
        if (data.empty()) break;
    }

    printf("%d", res);
}
/*for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        f[i][j] = max(f[i-1][j], f[i][j-1]);

        if (b[j].se <= a[i] && a[i] <= b[j].fi)
        f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
    }*/
