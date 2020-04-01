#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int N = 15e3 + 5;
const int oo = 1e9+7;

int n, k;
int a[N];
pair<int, int> v[2*N];
int id[2*N];
int IT1[8*N], IT2[8*N];
int dpMin[N], dpMax[N];

void updMin(int IT[], int p, int l, int r, int idx, int val) {
    if (idx < l || r < idx) return;

    if (l == r) IT[p] = min(IT[p], val);
    else {
        int mid = (l+r)/2;
        updMin(IT, 2*p, l, mid, idx, val);
        updMin(IT, 2*p+1, mid+1, r, idx, val);
        IT[p] = min(IT[2*p], IT[2*p+1]);
    }
}
void updMax(int IT[], int p, int l, int r, int idx, int val) {
    if (idx < l || r < idx) return;

    if (l == r) IT[p] = max(IT[p], val);
    else {
        int mid = (l+r)/2;
        updMax(IT, 2*p, l, mid, idx, val);
        updMax(IT, 2*p+1, mid+1, r, idx, val);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}
int rMin(int IT[], int p, int l, int r, int L, int R) {
    if (l > r || L > R || L > r || l > R) return -1;
    if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l+r)/2;
        int ans1 = rMin(IT, 2*p, l, mid, L, R);
        int ans2 = rMin(IT, 2*p+1, mid+1, r, L, R);
        if (ans1 == -1) return ans2;
        else if (ans2 == -1) return ans1;
        else return min(ans1, ans2);
    }
}
int rMax(int IT[], int p, int l, int r, int L, int R) {
    if (l > r || L > R || L > r || l > R) return -1;
    if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l+r)/2;
        int ans1 = rMax(IT, 2*p, l, mid, L, R);
        int ans2 = rMax(IT, 2*p+1, mid+1, r, L, R);
        if (ans1 == -1) return ans2;
        else if (ans2 == -1) return ans1;
        else return max(ans1, ans2);
    }
}
bool ok(int m) {
    //for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
    v[0] = mp(0, 0);
    for (int i = 1; i <= n; i++) {
        v[i] = mp(a[i], i);
        v[n+i] = mp(a[i] - m, n+i);
    }
    sort(v, v+2*n+1);

    int cnt = 0;
    for (int i = 0; i <= 2*n; i++)
    if (i == 0 || v[i].fi != v[i-1].fi)
        id[v[i].se] = ++cnt;
    else id[v[i].se] = cnt;

    for (int i = 1; i <= 4*cnt; i++) IT1[i] = oo;
    updMin(IT1, 1, 1, cnt, id[0], 0);

    for (int i = 1; i <= n; i++) {
        dpMin[i] = rMin(IT1, 1, 1, cnt, id[n+i], cnt) + 1;
        updMin(IT1, 1, 1, cnt, id[i], dpMin[i]);
    }
    for (int i = 1; i <= 4*cnt; i++) IT2[i] = -oo;
    updMax(IT2, 1, 1, cnt, id[0], 0);

    for (int i = 1; i <= n; i++) {
        dpMax[i] = rMax(IT2, 1, 1, cnt, id[n+i], cnt) + 1;
        updMax(IT2, 1, 1, cnt, id[i], dpMax[i]);
    }
    //for (int i = 1; i <= n; i++) cout << dpMin[i] << " "; cout << endl;
    //for (int i = 1; i <= n; i++) cout << dpMax[i] << " "; cout << endl;
    return dpMin[n] <= k && k <= dpMax[n];
}
int main() {
    //freopen("QBSEGPAR.inp", "r", stdin);
    //freopen("QBSEGPAR.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
    }
    int l = -oo, r = oo;
    //cout << "ok\n";
    while (l < r) {
        int mid;
        if (r <= 0) mid = (l+r-1)/2;
        else mid = (l+r)/2;

        //cerr << l << " " << r << " " << mid << endl;
        if (ok(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d\n", l);
    //cout << "-----\n";
    //cout << ok(-14382) << endl;
}
