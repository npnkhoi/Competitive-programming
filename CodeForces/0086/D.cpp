using namespace std;
struct query {
    int l, r, id;
};
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>

const int N = 2e5 + 2;
const int A = 1e6 + 2;
int n, m, block;
int curL, curR;
query q[N];
int a[N], cnt[A];
long long ans[N];
long long res;

bool cmp(query a, query b) {
    if (a.l / block != b.l / block)
        return a.l < b.l;
    else return a.r < b.r;
}

int main() {
    //freopen("test.inp","r",stdin);
    scanf("%d%d", &n, &m); block = sqrt(n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m ; i++)
    {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
        //cout << q[i].l << " " << q[i].r << endl;
    }
    sort(q+1, q+m+1, cmp);
    memset(cnt, 0, sizeof cnt);
    //for (int i = 1; i <= m; i++) cout << q[i].l << " " << q[i].r << endl;
    curL = 2; curR = 1; res = 0;
    for (int i = 1; i <= m; i++) {
        //cout << q[i].l << " " << q[i].r << "-----------\n";
        while (curL < q[i].l) {
            cnt[a[curL]] -- ;
            res -= (long long) a[curL]*((long long) (cnt[a[curL]]<<1) + 1);
            curL ++;
            //cout << curL << " " << curR << res << endl;
        }
        //cout << endl;
        while (curL > q[i].l) {

            curL --;
            cnt[a[curL]] ++ ;
            res += (long long) a[curL]*((long long) (cnt[a[curL]]<<1) - 1);
            //cout << curL << " " << curR << res << endl;
        }
        //cout << endl;
        while (curR > q[i].r) {
            cnt[a[curR]] -- ;
            res -= (long long) a[curR]*((long long) (cnt[a[curR]]<<1) + 1);
            curR --;
            //cout << curL << " " << curR << res << endl;
        }
        //cout << endl;
        while (curR < q[i].r) {
            curR ++;
            cnt[a[curR]] ++ ;
            res += (long long) a[curR]*((long long)(cnt[a[curR]]<<1) - 1);
            //cout << curL << " " << curR << res << endl;
        }
        //cout << endl;
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= m ; i++) printf("%I64d\n",ans[i]);
}
