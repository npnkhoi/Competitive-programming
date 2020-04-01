#include <bits/stdc++.h>
using namespace std;
void sum(string a, string b, string &c) {

}
int main() {
    scanf("%d %", &m, &n);
    REP(i, m) REP(j, n) {
        long long num;
        scanf("%lld", &num);
        REP(z, 0, 11) a[i][j] += (1<<z)&num;
    }
    REP(j, n) f[0][j] = a[0][j];
    FOR(i, 1, n-1) REP(j, n) {

    }
}
