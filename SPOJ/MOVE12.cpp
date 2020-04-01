#include <bits/stdc++.h>
#define fi first
#define se second
#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;
const int N = 1e4 + 5;
int n, pos[N], c[N], l, r;
pair<int, int> a[N];
bool ok(int val) {
    priority_queue<int, vector<int>, greater<int> > pq;
    //printf("%d\n", val);
    REP(i, n) {
        a[i].fi = pos[i] - val/c[i] - 1;
        a[i].se = pos[i] + val/c[i] - 1;
    }
    sort(a, a+n);
    int j = 0;
    REP(i, n) {
        for (; j < n && a[j].fi <= i; j++) pq.push(a[j].se);
        while (!pq.empty() && pq.top() < i) pq.pop();
        if (pq.empty()) return false;
        else pq.pop();
    }
    //cout << "true\n";
    return true;
}
int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d %d", &pos[i], &c[i]);
    l = 0; r = (int) 1e8 + 2;
    while (l < r) {
        int mi = (l+r)/2;
        if (ok(mi)) r = mi;
        else l = mi+1;
    }
    printf("%d", l);
}
