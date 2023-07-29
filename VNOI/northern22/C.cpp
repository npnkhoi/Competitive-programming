#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 2005;
int n;
int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, -1, 1};
set <ii> pts;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("C.inp", "r", stdin);

    while (cin >> n) {

        pts.clear();
        map <int, int> cnt, up, down;
        up.clear(); down.clear();
        cnt.clear();
        for (int i =1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            pts.insert({x, y});
            cnt[x + y]++;
        }
        for (ii u : pts) {
            int x = u.first, y = u.second;
            bool ok = true;
            int pre = -1;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (pts.find({nx, ny}) == pts.end()) {
                    continue;
                }
                if (pre == -1) {
                    pre = nx + ny;
                } else if (pre != nx + ny) {
                    ok = false;
                }
            }
            if (!ok) {
                continue;
            }
            //cout << x << ' ' << y << ' ' << pre << endl;
            if (pre > x + y) {
                down[pre]++;
            } else {
                up[pre]++;
            }
        }
        int res = 0;
        vector <int> dp(cnt.size(), 0);
        int i = 0;
        for (auto d : cnt) {
            dp[i] = max(dp[i], (i >= 2 ? dp[i - 2] : 0) + d.second);
            dp[i] = max(dp[i], (i >= 3 ? dp[i - 3] : 0) + d.second + down[d.first - 1]);
            res = max(res, dp[i]);
            i++;
        }

        cout << res << endl;
    }

    return 0;
}
