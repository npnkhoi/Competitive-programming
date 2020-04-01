// 5:24 - 5:38
#include <bits/stdc++.h>
using namespace std;
struct P {
    long long X, Y;
};
const int N = 1e5 + 5;
int n, id[N];
P a[N];
bool coline(P a, P b, P c) {
    return (b.X - a.X) * (c.Y - b.Y) == (b.Y - a.Y) * (c.X - b.X);
}
bool check(int u, int v) {
    int p = 0;
    for (int i = 1; i <= n; i++)
        if (!coline(a[u], a[v], a[i])) id[++ p] = i;
    for (int i = 3; i <= p; i++) if (!coline(a[id[1]], a[id[2]], a[id[i]])) return 0;
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%lld%lld", &a[i].X, &a[i].Y);
    int flag = -1;
    for (int i = 3; i <= n && flag == -1; i ++)
        if (!coline(a[1], a[2], a[i])) flag = i;
    //cerr << flag << endl;
    if (flag == -1) printf("YES");
    else {
        //cerr << check(1, 2, ) << " " << check(2, 1, flag) << " " << check(flag, 1, 2) << endl;
        if (check(1, 2) || check(1, flag) || check(flag, 2)) printf("YES");
        else printf("NO");
    }
}
