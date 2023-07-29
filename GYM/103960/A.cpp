#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("Test.txt", "r", stdin);
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, r = 0;

    int sumLength = 0;
    while(l < n && r < n) {
        if(s[l] == 'a') {
            while(r + 1 < n && s[r + 1] == 'a')
                r++;
            if(r - l + 1 >= 2)
                sumLength += (r - l + 1);
        }

        l = r;
        l++; r++;
    }

    cout << sumLength;
    return 0;
}

