#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 2e5 + 5;

int tc, n;
int a[N], pos[N];

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> tc;
    while (tc --) {
        // Remember to reset
        cin >> n;
        int index = 0;
        FOR(i, 1, 2*n) {
            int x; cin >> a[i];
            if (pos[a[i]] == 0) { // first time
                pos[a[i]] = i;

            } else { // second time

            }
        }
    }
}