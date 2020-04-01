#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int N = 1e5 + 7;
const ll oo = 1e15 + 7;

int n;
ll w1, w2;
ll a[N];
ll d[7];
ll s[7];

int main() {
    freopen("FIVESET.inp", "r", stdin);
    freopen("FIVESET.out", "w", stdout);
    scanf("%d %lld %lld", &n, &w1, &w2);
    d[1] = d[5] = w1;
    d[2] = d[4] = w2;
    d[3] = 1;

    for (int i = 1; i <= 5; i++) s[i] = -oo;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        for (int j = min(i, 5); j >= 1; j--) {
            s[j] = max(s[j], s[j-1] + d[j] * a[i]);
            //cout << j << " " << s[j] << endl;
        }
    }
    cout << s[5];
}
