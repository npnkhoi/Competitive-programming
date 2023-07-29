#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int res[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int h, w, n, h1, w1;
    cin >> h >> w >> n;

    if ((h * w) % n != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (h1 = 1; h1 <= h; ++h1) {
        bool ok = false;
        for (w1 = 1; w1 <= w; ++w1) {
            if ((h % h1 == 0) && (w % w1 == 0) && (h1 * w1 == h * w / n)) {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            int ii = (i - 1) / h1;
            int jj = (j - 1) / w1;
            res[i][j] = ii * w / w1 + jj;
            cout << char(res[i][j] + 'A');
        }
        cout << endl;
    }

    return 0;
}
