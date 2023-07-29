#include <bits/stdc++.h>
using namespace std;



int main() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        s += get(a[i] + 1, MAX);
    }
}
