using namespace std;
#include <stdio.h>
#include <queue>
#include <algorithm>
#define mp make_pair
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
const int N = 5e4 + 10;
int n, m, k;
int a[N], b[N];

priority_queue<iii, vector<iii>, greater<iii> > q;
int main() {
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    sort(a+1, a+m+1);
    sort(b+1, b+n+1);

    for (int i = 1; i <= m; i++) q.push(mp(a[i] + b[1], ii(i, 1)));
    for (int i = 2; i <= n; i++) q.push(mp(a[1] + b[i], ii(1, i)));

    while (k--) {
        printf("%d\n", q.top());
        int x = q.top().se.fi, y = q.top().se.se;
        q.pop();
        if (x < m && y < n) q.push(mp(a[x+1] + b[y+1], ii(x+1, y+1)));
    }
}
