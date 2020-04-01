#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
#define task "light"
const int N = 2005;
const long long oo = 1e17 + 5;
int n, t, rr = 0;
int p[N], l[N], r[N], ord[N];
map<int, int> id;
vector<int> v;
long long dp[2*N][2*N];
bool cmp(int i, int j) {
    return r[i] < r[j];
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        int x, h;
        scanf("%d %d %d", &x, &h, &p[i]);
        l[i] = max(x - h, 0);
        r[i] = min(x + h, t);
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    /// Discrete AND Init -----------------------------
    v.push_back(0);
    v.push_back(t);
    sort(v.begin(), v.end());
    rr = -1;
    for (int i = 0; i < v.size(); i++)
    if (i == 0 || v[i] != v[i-1]) id[v[i]] = ++ rr;
    for (int i = 1; i <= n; i++)
        l[i] = id[l[i]], r[i] = id[r[i]];
    t = id[t];

    for (int i = 1; i <= n; i++) ord[i] = i;
    sort(ord + 1, ord + n + 1, cmp);
    /// -----------------------------------------------
    //for (int i = 1; i <= n; i++) cerr << l[i] << " " << r[i] << "\n";

    for (int i = 0; i <= rr; i++)
    for (int j = 0; j <= rr; j++) dp[i][j] = oo;
    dp[0][0] = 0;


    for (int love = 1; love <= n; love++) {
        int k = ord[love];
        for (int i = t; i >= 0; i--)
        for (int j = t; j >= i; j--)
            if (l[k] <= j && j <= r[k]) {
                if (l[k] < i) dp[i][j] = min(dp[i][j], dp[l[k]][i] + p[k]);
                else dp[i][j] = min(dp[i][j], dp[i][l[k]] + p[k]);
            }
        /*for (int i = 0; i <= rr; i++) {
            for (int j = 0; j <= rr; j++) cerr << dp[i][j] << " ";
            cerr << "\n";
        }
        cerr << "\n";*/
    }
    printf("%lld", dp[t][t]);
}
