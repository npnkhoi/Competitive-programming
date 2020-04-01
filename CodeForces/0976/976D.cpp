#include <bits/stdc++.h>
using namespace std;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &d[i]);
    }
    m = d[n] + 1;
    for (int i = 1; i <= m; i++) data.push_back(i);

    for (int i = n; i >= 1; i--) {
        int u;
        do {
            u = vt.back();
            vt.pop_back();
        } while (deg[u] > d[i]);
        for (int i = 1; i <= d[i] - deg[u]; i++) {
            ans.push_back(mp(u, data[i-1]));
            deg[data[i-1]] ++;
        }
        sort(data.begin(), data.end(), cmp);
    }

}
