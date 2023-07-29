#include <bits/stdc++.h>
using namespace std;

#define int long long

int len(int x) {
    if (x == 0) return 0;
    return 1 + len(x/2);
}

int solve(int x) {
    if (x == -1) return 0;
    if (x == 0) return 1;
    if (x == 1) return 2;

    int res = 0, l = len(x);

    /// shorter
    for (int i = 1; i < l; ++ i) {
        if (i == 1) res += 2;
        else res += 1 << ((i-2 + 1) / 2);
    }
    //cerr << res << '\n';

    /// smaller head
    int l1 = l / 2, l2 = l - l1;
    //printf("l1: %d, l2: %d\n", l1, l2);
    int head = x >> l2;
    int mid = (x >> (l2 - 1)) & 1;

    int tmp = head - (1 << (l1 - 1));
    if (l % 2 == 1) tmp *= 2;
    res += tmp;
    //cerr << res << '\n';

    /// equal head
    int tail = x & ((1 << l1) - 1);
    //printf("head: %d, tail: %d\n", head, tail);
    bool flag = true;
    for (int i = 0; i < l1; ++ i) {
        int headBit = (head >> i) & 1;
        int tailBit = (tail >> (l1-1-i)) & 1;
        //cerr << "bits: " << headBit << ' ' << tailBit << '\n';
        if (headBit != tailBit) {
            if (headBit > tailBit) flag = false;
            break;
        }
    }
    //cerr << "flag: " << flag << '\n';

    if (flag) {
        res += ((mid == 1 && l % 2 == 1) ? 2 : 1);
    } else {
        res += (mid == 1 && l % 2 == 1);
    }
    //cerr << res << '\n';
    return res;
}

signed main() {
    // freopen("B.inp", "r", stdin);
    int q, a, b;
    cin >> q;


    while (q--) {
        cin >> a >> b;
        // cout << solve(b) << ' ' << solve(a-1) << '\n';
        cout << solve(b) - solve(a - 1) << '\n';
    }
}
