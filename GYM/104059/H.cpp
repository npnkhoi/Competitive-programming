#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e4 + 5;

int inp[6][N];
int n, x, l;

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    cout << "? ";
    for (char c = 'a'; c <= 'z'; c++) cout << c;
    cout << endl;
    cin >> n;
    FOR(i, 1, n) {
        cin >> x;
        l = max(l, x);
    }

    FOR(i, 0, 4) {
        cout << "? ";
        FOR(c, 0, 25) {
            if (c >> i & 1) cout << (char)(c + 'a');
        }
        cout << endl;

        cin >> n;
        FOR(j, 1, n) {
            cin >> x;
            inp[i][x] = 1;
        }
    }
    cout << "! ";

    // FOR(i, 0, 4) {
    //     FOR(j, 1, 3) cout << inp[i][j] << ' ';
    //     cout << '\n';
    // }

    FOR(i, 1, l) {
        int ans = 0;
        FOR(j, 0, 4) ans |= (inp[j][i] << j);
        // cout << ans << ' ';
        cout << (char)(ans + 'a'); 
    }
    cout << endl;
}