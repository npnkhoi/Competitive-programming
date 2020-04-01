#include <bits/stdc++.h>
using namespace std;
const int N = 10;

#define fi first
#define se second

int n;
pair<int, int> a[N];
int b[N];

bool ok(int num) {
    int cur = a[b[1]].fi;

    for (int i = 2; i <= n; ++i) {
        cur = max(a[b[i]].fi, cur + num);
        if (cur > a[b[i]].se) return false;
    }
    return true;
}
int ans() {
    int l = 0;
    int r = 90000;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            res = max(res, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    return res;
}
int main() {
    freopen("PLANES.inp", "r", stdin);
    freopen("PLANES.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].fi, &a[i].se);
        a[i].fi *= 60;
        a[i].se *= 60;
    }
    for (int i = 1; i <= n; i++) b[i] = i;

    int res = 0;
    do {
        res = max(res, ans());
    } while (next_permutation(b+1, b+n+1));
    //cout << ok(450) << endl;
    printf("%d:%d",res/60, res%60);
}
