using namespace std;

struct query {
    int l, r, id;
};

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>

const int N = 3e4 + 50;
const int Q = 2e5 + 50;
const int A = 1e6 + 50;

int n, m, block;
int curL, curR;
query q[Q];
int ans[Q], a[N];
map<int, int> cnt;
int res;

bool cmp(query a, query b) {
    if (a.l / block != b.l / block)
        return a.l < b.l;
    else return a.r < b.r;
}

int main() {
    //freopen("test.inp","r",stdin);
    scanf("%d", &n); block = sqrt(n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m ; i++)
    {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q+1, q+m+1, cmp);
    curL = 2; curR = 1; res = 0;
    for (int i = 1; i <= m; i++) {
        while (curL < q[i].l) {
            cnt[a[curL]] -- ;
            if (cnt[a[curL]] == 0) res --;
            curL ++;
        }
        while (curL > q[i].l) {
            curL --;
            cnt[a[curL]] ++ ;
            if (cnt[a[curL]] == 1) res ++;
        }
        while (curR > q[i].r) {
            cnt[a[curR]] -- ;
            if (cnt[a[curR]] == 0) res --;
            curR --;
        }
        while (curR < q[i].r) {
            curR ++;
            cnt[a[curR]] ++ ;
            if (cnt[a[curR]] == 1) res ++;
        }
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= m ; i++) printf("%d\n",ans[i]);
}
