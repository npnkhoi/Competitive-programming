#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 305;

int n, a[N][N];
vector<int> init;

int infected(int delNode) {
    queue<int> q;
    vector<int> mark(n+5, 0);
    int res = 0;

    for (int x : init) {
        if (x != delNode && !mark[x]) {
            q.push(x);
            mark[x] = 1;
            res ++;
        }
    }

    while (!q.empty()) {
        int t = q.front(); q.pop();
        FOR(i, 0, n-1) {
            if ((a[t][i] || a[i][t]) && !mark[i]) {
                q.push(i);
                mark[i] = 1;
                res ++;
            }
        }
    }
    return res;
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> n;
    FOR(i, 0, n-1) FOR(j, 0, n-1) {
        cin >> a[i][j];
    }
    int x;
    while (cin >> x) {
        init.push_back(x);
    }
    sort(init.begin(), init.end());
    int best = n + 5, ans;
    for (int i : init) {
        int tmp = infected(i);
        // cerr << i << ' ' << tmp << '\n';
        if (tmp < best) {
            best = tmp;
            ans = i;
        } 
    }
    cout << ans;
}