using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e5 + 5;
const int k = 1e5 + 5;
int n, val, pos, a[N], nho, lon, cnt[3][N+k];
long long res;
int main() {
    freopen("SUBSTR.inp","r",stdin);
    freopen("SUBSTR.out","w",stdout);
    scanf("%d %d", &n, &val);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        if (a[i] == val) pos = i;
    }
    nho = lon = 0;
    FOD(i, pos, 1) {
        nho += a[i] < val;
        lon += a[i] > val;
        cnt[(pos - i) % 2][nho - lon + k] ++;
    }
    nho = 0; lon = 0;
    FOR(i, pos, n) {
        nho += a[i] < val;
        lon += a[i] > val;
        res += cnt[(i - pos) % 2][lon - nho + k];
    }
    printf("%lld", res);

    return 0;
}
/** Happy Coding ^^ */
