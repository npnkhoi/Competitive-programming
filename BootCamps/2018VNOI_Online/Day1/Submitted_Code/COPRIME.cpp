#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)
#define task "coprime"
typedef long long ll;
typedef pair<int, int> ii;
const int N = 1e5 + 5;
const int MASK = 35;
const int prime[] = {2, 3, 5, 7, 11};

int n, p, res, f[N], IT[MASK][N];
long long a[N];
vector<long long> v;
map<long long, int> id;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a%b);
}
void sub1() {
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        f[i] = 1;
        FOR(j, 1, i-1) if (a[j] < a[i] && GCD(a[i], a[j]) == 1) {
            f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    printf("%d", res);
}
int query(int IT[], int p, int l, int r, int L, int R) {
    if (l > r || L > R || l > R || L > r) return -1;
    if (L <= l && r <= R) return IT[p];
    else {
        int mi = (l+r) / 2;
        int x = query(IT, 2*p, l, mi, L, R);
        int y = query(IT, 2*p + 1, mi+1, r, L, R);
        return max(x, y);
    }
}
void update(int IT[], int p, int l, int r, int idx, int val) {
    if (idx < l || r < idx) return;
    if (l == idx && idx == r) IT[p] = max(IT[p], val);
    else {
        int mi = (l+r) / 2;
        update(IT, 2*p, l, mi, idx, val);
        update(IT, 2*p+1, mi+1, r, idx, val);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}
void sub2() {
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    p = 0;
    REP(i, n) if (i == 1 || v[i] != v[i-1])
        id[v[i]] = ++p;
    FOR(i, 1, n) {
        f[i] = 1;
        int pos = id[a[i]], tmp = 0;
        REP(j, 5) if (a[i] % prime[j] == 0) tmp += 1 << j;
        //cerr << a[i] << " " << tmp << " " << pos <<  "\n";
        REP(mask, 1<<5) if ((mask & tmp) == 0) {
            f[i] = max(f[i], 1 + query(IT[mask], 1, 1, p, 1, pos - 1));
        }
        res = max(res, f[i]);
        update(IT[tmp], 1, 1, p, pos, f[i]);
    }
    printf("%d", res);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    /*if (n <= 5000) sub1();
    else sub2();*/
    sub2();
}
