using namespace std;
#include <stdio.h>
#include <algorithm>
#include <vector>
#define fi first
#define se second
const int N = 1e5 + 10;
int n, k;
vector<int> a[N];
vector< pair<int, int> > res;
int v[N];
int main() {
    scanf("%d%d", &n, &k);
    int m = -1;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[x].push_back(i);
        m = max(m, x);
    }
    if (a[0].size() != 1) { printf("-1"); return 0;}
    for (int i = 1; i <= m; i++) {
        if (a[i].empty()) { printf("-1"); return 0;}
        for (int j = 0; j < a[i].size(); j++) {
            int x = a[i-1][j%(a[i-1].size())];
            int y = a[i][j];
            if (v[x] >= k || v[y] >= k) {printf("-1"); return 0;}
            res.push_back(make_pair(x, y));
            v[x]++;
            v[y]++;
        }
    }
    printf("%d\n", n-1);
    for (int j = 0; j < n-1; j++) printf("%d %d\n", res[j].fi, res[j].se);
}
