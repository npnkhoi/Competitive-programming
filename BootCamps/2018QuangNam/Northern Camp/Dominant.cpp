using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

#define fi first
#define se second
typedef pair<int, int> ii;
const int N = 3e5 + 10;
string str;
int n;
pair<long long, int> a[N];

bool cmp(ii x, ii y) {
    if (x.fi != y.fi) return x.fi < y.fi;
    else return x.se > y.se;
}
int main () {
    freopen("dominant.inp", "r", stdin);
    freopen("dominant.out", "w", stdout);
    getline(cin, str);
    n = str.size();
    long long s = 0;
    a[0].fi = a[0].se = 0;
    for (int i = 0; i < str.size(); i++) {
        s += (str[i] == '1');
        a[i + 1].fi = 2*s - i - 1;
        a[i + 1].se =  i + 1;
    }
    sort(a, a + n + 1, cmp);

    long long res = 0;
    int cnt = 1, tmp = a[1].se;

    for (int i = 1; i <= n; i++) {
        if (res < a[i].se - tmp)
            res = a[i].se - tmp, cnt = 1;

        else if (res == a[i].se - tmp) cnt ++;

        tmp = min(tmp, a[i].se);
    }
    printf("%lld %d\n", res, cnt);
}
