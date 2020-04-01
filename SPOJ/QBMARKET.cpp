#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 500 + 5;
const int S = 1e5 + 5;
int s, n, c[N], m[N];
void sum(string a, string b, string &c) {
    a.reserve(a.begin, a.end());
    b.reserve(b.begin, b.end());
    c = "";
    while (a.size() < b.size) a.push_back('0');
    while (a.size() > b.size) b.push_back('0');
    REP(i, a.size()) {

    }

}
long long f[2][S];
int main () {
    freopen("0.in", "r", stdin);
    scanf("%d %d", &s, &n);
    FOR(i, 1, n) scanf("%d %d", &c[i], &m[i]);
    f[0][0] = 1;
    FOR(i, 1, n) {
        int cur = i&1, pre = cur^1;
        //cout << cur << pre << endl;
        FOR(j, c[i], s) f[pre][j] += f[pre][j - c[i]];
        FOR(j, 0, s) {
            int l = j - min(m[i], j/c[i])*c[i] - c[i];
            if (l < 0) f[cur][j] = f[pre][j];
            else f[cur][j] = f[pre][j] - f[pre][l];
        }
    }
    cout << f[n&1][s] << "\n";
    printf("%lld", f[n&1][s]);
}
