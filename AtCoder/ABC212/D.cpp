#include <bits/stdc++.h>
using namespace std;

multiset<long long> nums;

int main() {
    int q; cin >> q;
    
    long long inc = 0;

    while (q--) {
        int type;
        cin >> type;
        if (type == 3) {
            cout << *nums.begin() + inc << '\n';
            nums.erase(nums.begin());

        } else {
            int x; cin >> x;
            if (type == 1) {
                nums.insert(x - inc);
            } else {
                inc += x;
            }
        }
    }
}