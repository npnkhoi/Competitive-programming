#include <bits/stdc++.h>

using namespace std;

const int N = 24;
int n, m, s, a[N][N];
vector <int> desire_perm, el[205];

vector <int> apply(vector <int> cur, int col) {
    for (int i = -100; i <= 100; ++i) {
        el[i + 100].clear();
    }
    for (int i : cur) {
        el[a[i][col] + 100].push_back(i);
    }
    vector <int> ret;
    ret.clear();
    for (int i = -100; i <= 100; ++i) {
        for (int j : el[i + 100]) {
            ret.push_back(j);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("L.inp", "r", stdin);

    cin >> m >> n >> s;
    for (int i = 1; i <= m; ++i) {
        desire_perm.push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= s; ++i) {
        int col;
        cin >> col;
        desire_perm = apply(desire_perm, col);
    }
    string res;
    res.clear();
    vector <int> cols;
    cols.clear();

    for (int i = 1; i <= n; ++i) {
        cols.push_back(i);
    }
    int minLen = 100;
    do {
        vector <int> initial_perm;
        initial_perm.clear();
        for (int i = 1; i <= m; ++i) {
            initial_perm.push_back(i);
        }
        if (initial_perm == desire_perm) {
            cout << 0 << endl;
            return 0;
        }
        for (int i = 0; i < cols.size(); ++i) {
            initial_perm = apply(initial_perm, cols[i]);
            if (initial_perm == desire_perm) {
                string temp;
                temp.clear();
                for (int j = 0; j <= i; ++j) {
                    temp += to_string(cols[i]);
                    if (j != i) temp += ' ';
                }
                if (minLen > i + 1) {
                    minLen = i + 1;
                    res = temp;
                } else if (minLen == i + 1) {
                    if (res.size() == 0) {
                        res = temp;
                    }
                    res = min(res, temp);
                }
                break;
            }

        }
    } while (next_permutation(cols.begin(), cols.end()));

    cout << minLen << endl;
    cout << res << endl;
}
