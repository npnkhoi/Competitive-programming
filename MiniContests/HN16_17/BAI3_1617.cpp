#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 1e4 + 5;
const int M = 1e2 + 5;
int n, m, a[N][M], ans[M];
void answer(int x) {
    int cnt = 0;
    FOR(i, 1, m) if (ans[i] == x) cnt++;
    printf("%d ", cnt);
    FOR(i, 1, m) if (ans[i] == x) printf("%d ", i);
    printf("\n");
}
int main() {
    freopen("BAI3_1617.inp", "r", stdin);
    freopen("BAI3_1617.out", "w", stdout);
    memset(ans, -1, sizeof ans);
    scanf("%d %d", &m, &n);
    FOR(i, 1, n) {
        FOR(j, 1, m+1) scanf("%d", &a[i][j]);
        if (a[i][m+1] == 0)
        FOR(j, 1, m) if (a[i][j]) ans[j] = 0;
    }
    FOR(i, 1, n) if (a[i][m+1]) {
        int cnt = 0, tmp;
        FOR(j, 1, m) if (ans[j] != 0 && a[i][j])
            tmp = j, cnt ++;
        if (cnt == 1) {
            ans[tmp] = 1;
            //printf("found %d at %d\n", tmp, i);
        }
    }
    answer(0);
    answer(1);
    answer(-1);
}
