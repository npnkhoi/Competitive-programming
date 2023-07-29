#include <bits/stdc++.h>
using namespace std;

int main() {
    while (cin >> p >> q) {
        vector<pair<int, int>> v;
        while (p != q) {
            if (p > q) {
                v.push({1, p/q});
                p %= q;
            } else {
                v.push({2, q/p});
                q %= p;
            }
        }
        int n = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            while (v[i].first --) {
                i
            }
        }
    }

}
