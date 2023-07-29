#include <bits/stdc++.h>
using namespace std;

const int N = 105;

long long x[N], y[N], n;

int ccw(int a, int b, int c) {
    long long x1 = x[b] - x[a], x2 = x[c] - x[b];
    long long y1 = y[b] - y[a], y2 = y[c] - y[b];
    long long tmp = x1 * y2 - x2 * y1; /// NEED CHECK
    if (tmp == 0) return 0;
    else if (tmp > 0) return 1;
    else return -1;
}

bool check(int a, int b, int c, int d) {
    return (ccw(a, c, b) * ccw(a, c, d) < 0) && (ccw(b, d, a) * ccw(b, d, c) < 0);
}

bool solve(int a, int b, int c, int d) {
    // return check(a, b, c, d) || check(a, b, d, c) || check(a, c, b, d) || check(a, c, d, b) || check(a, d, b, c) || check(a, d, c, b);
    if (ccw(a, b, c) == 0) return false;
    if (ccw(a, b, d) == 0) return false;
    if (ccw(a, c, d) == 0) return false;
    if (ccw(b, c, d) == 0) return false;
    return true;
}

int main() {
    // freopen("F.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> x[i] >> y[i];
    }

    int res = 0;

    for (int a = 1; a <= n; ++ a) {
        for (int b = a + 1; b <= n; ++ b) {
            for (int c = b + 1; c <= n; ++ c) {
                for (int d = c + 1; d <= n; ++ d) {
                    // printf("%d %d %d %d: %d\n", a, b, c, d, solve(a, b, c, d));
                    res += solve(a, b, c, d);

                }
            }
        }
    }
    cout << res;
}
