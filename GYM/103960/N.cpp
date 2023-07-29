#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
#define int long long

typedef tree<
pair <int, int>,
null_type,
less<pair <int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ordered_set orderset;

const int N = 2e5 + 5;
int n, a[N], b[N], K, L, indices[N], pref[N];

struct FenwickTree {
    int n;
    vector <int> fw;
    FenwickTree() {}
    FenwickTree(int _n) {
        this ->  n = _n;
        fw.assign(n + 5, 0);
    }
    void add(int i, int x) {
        while (i <= n) {
            fw[i] += x;
            i += i & (-i);
        }
    }

    int get(int i) {
        int ret = 0;
        while (i > 0) {
            ret += fw[i];
            i -= (i & -i);
        }
        return ret;
    }
} solver;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("N.inp", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[n + i] = b[i];
    }
    vector <array<int, 2>> val;
    val.clear();
    for (int i = 1; i <= n * 2; ++i) {
        val.push_back({b[i], i});
    }
    sort(val.begin(), val.end(), greater<array<int,2>>());
    int id = 0;
    for (auto d : val) {
        id++;
        indices[d[1]] = id;
    }
    for (int i = 1; i <= 2 * n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    cin >> K >> L;
    int res = 0;
    solver = FenwickTree(2 * n);
    for (int i = n - K + 1; i <= n; ++i) {
        orderset.insert({-b[i], indices[i]});
        solver.add(indices[i], b[i]);
    }
    for (int i = n - K + 1; i <= n + 1; ++i) {
        int r = i + K - 1;
        int temp = pref[r] - pref[i - 1];
        int kth = (*orderset.find_by_order(L - 1)).second;
        temp += solver.get(kth);
        solver.add(indices[i], -b[i]);
        solver.add(indices[r + 1], b[r + 1]);
        orderset.erase({-b[i], indices[i]});
        orderset.insert({-b[r + 1], indices[r + 1]});
        res = max(res, temp);
    }

    cout << res << endl;

    return 0;
}
