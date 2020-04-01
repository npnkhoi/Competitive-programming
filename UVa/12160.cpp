using namespace std;
#include <stdio.h>
#include <queue>
#include <string.h>

queue<int> q;
int a[15], d[10010];

int main() {
    int tc = 0;
    while (++ tc) {
        int s, f, n;
        scanf("%d %d %d", &s, &f, &n);
        if (!s && !f && !n) break;
        for (int  i = 0; i < n; i++) scanf("%d", &a[i]);

        memset(d, -1, sizeof d);
        q.push(s); d[s] = 0;
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (int i = 0; i < n; i++) {
                int x = (t + a[i]) % 10000;
                if (d[x] == -1)
                d[x] = d[t] + 1, q.push(x);
            }
        }

        if (d[f] == -1) printf("Case %d: Permanently Locked\n", tc);
        else printf("Case %d: %d\n", tc, d[f]);
    }
}
