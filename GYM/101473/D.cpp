using namespace std;
#include <bits/stdc++.h>

const int N = 40;
int m, n, r, l, pos[N];
long long a[N], b[N], s[N];
bool found() {
    int idx = 15;
    int dir = 1;
    for (int i = 2; i <= m; i++)
}
void Try(int i) {
    //cout << i << "\n";
    if (i == m+1) {
        if (found()) {
            cout << "S";
            assert(0);
        }
        return;
    }

    for (int j = -1; j <= 1; j++) if (j != 0) {
        //if (i > 2 && pos[i-1] == 0 && pos[i] == 0) continue;
        pos[i] = j;
        Try(i+1);
    }
}

int main() {
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    Try(2);

    cout << "N";
}
