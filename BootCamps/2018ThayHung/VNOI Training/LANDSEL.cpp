#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define mp make_pair
#define task "landsel"

int m, n, k;
vector<vector<int>> a;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    a.assign(n+2, vector<int>(m+2, 0));
    vector<int> ptr(n+2, 2);

    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
        scanf("%d", &a[j][i]);
}
