#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int h, w, n, a[N], b[N];
vector<int> rows, cols;

void process(vector<int> &v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

int main() {
    cin >> h >> w >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i] >> b[i];
        rows.push_back(a[i]);
        cols.push_back(b[i]);
    }

    process(rows);
    process(cols);

    for (int i = 0; i < n; ++ i) {
        int r = upper_bound(rows.begin(), rows.end(), a[i]) - rows.begin();
        int c = upper_bound(cols.begin(), cols.end(), b[i]) - cols.begin();
        cout << r << ' '  << c << '\n';
    }
}