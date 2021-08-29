#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define mp make_pair
#define fi first
#define se second
int n, m, k, t;
long long total;
vector<ii> v;

int main() {
    freopen("BAI2_1617.inp", "r", stdin);
    freopen("BAI2_1617.out", "w", stdout);
    scanf("%d %d", &m, &n);
    while (m--) {
        scanf("%d %d", &k, &t);
        total += 1LL * k;
        if (k >= t) v.push_back(mp(t, k/t));
        if (k % t) v.push_back(mp(k%t, 1));
    }
    sort(v.begin(), v.end(), greater<ii>());
    for (int i = 0; i < v.size(); i++)
        if (n <= v[i].se) {
            total -= 1LL * n * v[i].fi;
            break;
        }
        else {
            total -= 1LL * v[i].se * v[i].fi;
            n -= v[i].se;
        }
    printf("%lld", total);
}
