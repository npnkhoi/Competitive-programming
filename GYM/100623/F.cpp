using namespace std;
#include <bits/stdc++.h>
const int N = 1e5 + 10;
long long ft[N], a[N];
int n;
int LSOne(int x)
{
    return x&(-x);
}
void adjust(int pos, long long val)
{
    for (; pos <= n; pos+= LSOne(pos)) ft[pos]+=val;
}
long long rsq(int b)
{
    long long s = 0;
    for (; b > 0; b -= LSOne(b)) s+=ft[b];
    return s;
}
long long rsq(int a, int b)
{
    if (a>b) return 0LL;
    return rsq(b) - rsq(a-1);
}
int main() {
    freopen("fenwick.in", "r", stdin);
    freopen("fenwick.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        adjust(i, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int l = i - LSOne(i) + 1;
        int r = i-1;
        //cout << l << " " << r << endl;
        if (rsq(l, r) != 0) {
            long long tmp = - rsq(l, r-1);
            adjust(i-1, tmp - a[i-1]);
            a[i-1] = tmp;
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
}
