#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define task "dolls"
const int N = 1e5 + 5;
int n, k, a[N];
long long res;
queue<int> q;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    for (int i = 1; i <= n; i++) {
        if (!q.empty() && q.front() >= a[i] + k)
            q.pop();
        else res += a[i];
        q.push(a[i]);
    }
    printf("%lld", res);
}
