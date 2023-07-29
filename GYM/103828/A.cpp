#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

set<int> gValues;
int n, a[N], g[N], p[N], gPos[N];
vector<pair<int, int>> items[N];


int main() {
    // freopen("test.inp", "r", stdin);
    int tc;
    cin >> tc;
    while (tc --) {
        // clean up
        for (int val : gValues) {
            items[val].clear();
        }
        gValues.clear();
        memset(p, 0, sizeof p);


        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> a[i];
        for (int i = 1; i <= n; ++ i) {
            cin >> g[i];
            gValues.insert(g[i]);
            // items[x] contains tuples corresponding to an element in the group (value, abs pos)
            items[g[i]].push_back({a[i], i});
        }
        // prep
        bool noSol = false;
        for (int val: gValues) {
            sort(items[val].begin(), items[val].end());
            for (int i = 0; i < items[val].size(); i++) {
                pair<int, int> t = items[val][i]; // check
                gPos[t.second] = i;
                if (i > 0 && items[val][i].first == items[val][i-1].first) {
                    noSol = true;
                }
            }
        }
        if (noSol) {
            cout << "-1\n";
            continue;
        }
        // solve
        // p: the result array
        int firstFree = 1;
        for (int i = 1; i <= n; ++ i) {
            if (p[i] == 0) {
                // how many undertermined positions in that group?
                int pos = gPos[i]; // position in its corresponding group
                int group = g[i];
                int start = pos; // should be the smallest position in group that is undetermined
                while (start > 0 && p[items[group][start-1].second] == 0) start --;
                // get the smallest (pos - start + 1) free values to assign
                for (int j = start; j <= pos; ++ j) {
                    p[items[group][j].second] = firstFree;
                    firstFree ++;
                }
            }
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
}
