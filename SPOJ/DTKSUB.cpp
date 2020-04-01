#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<long long, long long> pll;

#define mp make_pair
#define fi first
#define se second

const int N = 5e4 + 5;
const int MAX_L = 5e4 + 1;
const long long base1 = 27;
const long long base2 = 37;
const long long md = 1e9 + 7;

int n, k;
char s[N];
pll h[N], POW[N], v[N];

void hashInit() {
    POW[0] = mp(1, 1);
    for (int i = 1; i <= MAX_L; i++) {
        POW[i].fi = (POW[i-1].fi * base1) % md;
        POW[i].se = (POW[i-1].se * base2) % md;
    }
}
void hashBuild(char s[], pll h[]) {
    int n = strlen(s+1);
    for (int i = 1; i <= n; i++) {
        h[i].fi = (h[i-1].fi * base1 + s[i]) % md;
        h[i].se = (h[i-1].se * base2 + s[i]) % md;
    }
}
pll hashGet(pll h[], int l, int r) {
    pll tmp;
    tmp.fi = (h[r].fi - h[l-1].fi  * POW[r-l+1].fi + md * md) % md;
    tmp.se = (h[r].se - h[l-1].se  * POW[r-l+1].se + md * md) % md;
    return tmp;
}
int calc(int l) { /// max number of appearance of subtring l-size
    int m = n-l+1;
    for (int i = 1; i <= m; i++)
        v[i] = hashGet(h, i, i+l-1);
    sort(v+1, v+m+1);

    int cnt = 1, res = 1;
    for (int i = 2; i <= m; i++)
        if (v[i] == v[i-1]) {
            cnt ++;
            res = max(res, cnt);
        } else cnt = 1;
    return res;
}
int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);

    hashInit();
    hashBuild(s, h);

    int l = 1, r = n, d = l;
    while (l <= r) {
        int mi = (l + r) / 2;
        if (calc(mi) >= k) {
            d = max(d, mi);
            l = mi + 1;
        } else r = mi - 1;
    }
    printf("%d", d);
}
