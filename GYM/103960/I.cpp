#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("Test.txt", "r", stdin);

    string ans = "S";
    for(int i = 0; i < 8; i++) {
        int bit; cin >> bit;
        if(bit != 0 && bit != 1)
            ans = "F";
    }

    cout << ans;
    return 0;
}
