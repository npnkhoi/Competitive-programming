#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <complex>
#include <bitset>
#include <iterator>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 5;
const ll md = 1e9 + 7;
const int base1 = 26;
const int base2 = 37;

pll EXP[N], ha[N], hb[N];
char a[N], b[N];
int n;

void hashInit() {
    EXP[0] = mp(1, 1);
    FOR(i, 1, 1e5) {
        EXP[i].fi = EXP[i-1].fi * base1 % md;
        EXP[i].se = EXP[i-1].se * base2 % md;
    }
}
void hashBuild(char s[], pll h[], int n) {
    h[0] = mp(0, 0);
    FOR(i, 1, n) {
        h[i].fi = (h[i-1].fi * base1 + s[i-1] - 'A') % md;
        h[i].se = (h[i-1].se * base2 + s[i-1] - 'A') % md;
    }
}
pll hashGet(pll h[], int l, int r) {
    return mp (
        (h[r].fi - h[l-1].fi * EXP[r-l+1].fi + md * md) % md,
        (h[r].se - h[l-1].se * EXP[r-l+1].se + md * md) % md
    );
}
int diff(int x, int y, int u, int v) {
    int l = 0, r = y - x + 1, d = l;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (hashGet(ha, x, x + mid - 1) == hashGet(hb, u, u + mid - 1)) {
            d = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    //cerr << d << "\n";
    if (d == y - x + 1) return 0;
    if (hashGet(ha, x+d+1, y) == hashGet(hb, u+d+1, v)) return 1;
    else return 2;
}
int main() {
    hashInit();
    scanf("%s", a); scanf("%s", b);
    n = strlen(a);
    hashBuild(a, ha, n);
    //FOR(i, 1, n) cerr << ha[i].fi << " " << ha[i].se << "\n";
    hashBuild(b, hb, n);
    //cerr << "ok\n";
    //FOR(i, 1, n) cerr << hb[i].fi << " " << hb[i].se << "\n";
    long long res = 0;
    FOR(i, 1, n) {
        //cerr << i << "\n";
        int tmp = diff(1, i, n-i+1, n) + diff(i+1, n, 1, n-i);
        //cerr << tmp << "\n";
        if (tmp == 0) res += n;
        else if (tmp == 1) res ++;
    }
    printf("%lld", res);
    //cerr << diff(1, 2, 7, 8);
}
// AHYANGYI YANGYIAH
